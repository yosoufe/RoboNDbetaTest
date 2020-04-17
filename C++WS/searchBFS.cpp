#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

// Map class
class Map {
public:
    const static int mapWidth = 6;
    const static int mapHeight = 5;
    vector<vector<int> > grid = {
        { 0, 1, 0, 0, 0, 0 },
        { 0, 1, 0, 0, 0, 0 },
        { 0, 1, 0, 0, 0, 0 },
        { 0, 1, 0, 0, 0, 0 },
        { 0, 0, 0, 1, 1, 0 }
    };
    
    bool inMapAndEmpty(int x, int y)
    {
        if (x < 0 || x>=mapHeight) return false;
        if (y < 0 || y>=mapWidth) return false;
        if (grid[x][y]) return false;
        return true;
    }
};

// Planner class
class Planner : Map {
public:
    int start[2] = { 0, 0 };
    int goal[2] = { mapHeight - 1, mapWidth - 1 };
    int cost = 1;

    string movements_arrows[4] = { "^", "<", "v", ">" };

    vector<vector<int> > movements{
        { -1, 0 },
        { 0, -1 },
        { 1, 0 },
        { 0, 1 }
    };
};

// Template function to print 2D vectors of any type
template <typename T>
void print2DVector(T Vec)
{
    for (int i = 0; i < Vec.size(); ++i) {
        for (int j = 0; j < Vec[0].size(); ++j) {
            cout << Vec[i][j] << ' ';
        }
        cout << endl;
    }
}

/*#### TODO: Code the search function which will generate the expansion list ####*/
// You are only required to print the final triplet values

vector<int> pop_best_node(vector<vector<int>> &open_list)
{
    int best_value = open_list[0][0];
    int best_idx = 0;
    for (unsigned int idx = 0 ; idx < open_list.size(); idx++)
    {
        vector<int>& node  = open_list[idx];
        if (node[0] < best_value) {
            best_idx = idx;
            best_value = node[0];
        }
    }
    vector<int> result = open_list[best_idx];
    open_list.erase(open_list.begin() + best_idx);
    return result;
};

bool ifProposalIsBetter(vector<vector<int>> &visited_values, vector<int> & node)
{
    int& current_value_of_node = visited_values[ (unsigned int)(node[1]) ][ (unsigned int) (node[2]) ];
    if ( node[0] <  current_value_of_node)
    {
        current_value_of_node =  node[0];
        return true;
    }
    return false;
}

bool isGoal(vector<int> &picked_node)
{
    return (picked_node[1] == 4 && picked_node[2] == 5);
}

void update_expansion_order(vector<vector<int>> &expansion_order_map, vector<int> &node, int order)
{
    expansion_order_map[node[1]][node[2]] = order;
}

void print_solution_path(Map &map, Planner &planner, vector<vector<int>> &action_array)
{
    vector<vector<string>> solution_path (map.mapHeight, vector<string>(map.mapWidth, "-"));
    solution_path[4][5] = "*";

    int cur_x = 4, cur_y = 5;
    while (cur_x != planner.start[0] || cur_y != planner.start[1])
    {
        int x = cur_x - planner.movements[action_array[cur_x][cur_y]][0];
        int y = cur_y - planner.movements[action_array[cur_x][cur_y]][1];
        solution_path[x][y] = planner.movements_arrows[action_array[cur_x][cur_y]];
        cur_x = x;
        cur_y = y;
    }
    print2DVector(solution_path);
}

void search(Map map, Planner planner)
{
    vector<vector<int>> open_list = {{0,0,0}};
    vector<vector<int>> visited_values (map.mapHeight, vector<int>(map.mapWidth, 100000));
    vector<vector<int>> expansion_order_map (map.mapHeight, vector<int>(map.mapWidth, -1));
    vector<vector<int>> action_array (map.mapHeight, vector<int>(map.mapWidth, -1));
    visited_values[0][0] = 0;
    expansion_order_map[0][0] = 0;

    int current_order_value = -1;
    
    while (!open_list.empty())
    {   
        vector<int> picked_node = pop_best_node(open_list);
        current_order_value += 1;
        update_expansion_order(expansion_order_map, picked_node, current_order_value);
        if (isGoal(picked_node)){
            cout << "Reached the Goal: [" << picked_node[0] << ", " << picked_node[1] << ", " << picked_node[2] << "]" << endl;
            // print2DVector(action_array);
            print_solution_path(map, planner, action_array);
            return;
        }
        for (int idx = 0 ; idx < planner.movements.size(); idx++)
        {
            auto &move = planner.movements[idx];
            int new_x = picked_node[1] + move[0], new_y =  picked_node[2] + move[1];
            if (map.inMapAndEmpty(new_x, new_y))
            {
                vector<int> proposal({picked_node[0]+1, new_x, new_y});
                if (ifProposalIsBetter(visited_values, proposal))
                {
                    update_expansion_order(action_array, proposal, idx);
                    open_list.push_back(proposal);
                }
            }
        }
    }
    print2DVector(expansion_order_map);
    cout << "No Path to Goal Found!" << endl;
}

int main()
{
    // Instantiate map and planner objects
    Map map;
    Planner planner;

    // Search for the expansions
    search(map, planner);

    return 0;
}
