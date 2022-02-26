/*
Created by  : Vaisakh Dileep
Date        : 26, February, 2022
Description : Is Graph Bipartite?
*/

#include<iostream>

#include "../header_files/display_graph_adjacency_matrix/display_graph_adjacency_matrix.hpp"

using namespace std;

class Solution
{
public:
    bool colour_graph(vector<vector<int>> &graph, vector<int> &coloured_node, int node, int colour) // It will return "true", if we successfully colour the graph.
    {
        if(coloured_node[node] == 0)
        {
            coloured_node[node] = colour;

            for(int i {0}; i < graph[node].size(); i++)
            {
                if(colour_graph(graph, coloured_node, graph[node][i], -colour) == false)
                {
                    return false;
                }
            }
        }
        else
        {
            if(coloured_node[node] != colour)
            {
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>> &graph)
    {
        vector<int> coloured_node(graph.size(), 0);

        for(int i {0}; i < graph.size(); i++) // 0(not coloured), 1(red), -1(blue)
        {
            if(coloured_node[i] == 0) // if it is not coloured.
            {
                if(colour_graph(graph, coloured_node, i, 1) == false)
                {
                    return false;
                }
            }
        } // We iterate over all the nodes in case if the graph is disconnected.

        return true;
    }
};

void debug(vector<vector<int>> &input)
{
    bool result {};

    cout<<"isBipartite(\n";

    display_unweighed_graph_adj_list(input);

    result = Solution {}.isBipartite(input);

    cout<<boolalpha;

    cout<<"): "<<result;
}

int main()
{
    vector<vector<int>> input(4, vector<int> {});

    input[0] = vector<int> {1, 3};
    input[1] = vector<int> {0, 2};
    input[2] = vector<int> {3, 1};
    input[3] = vector<int> {0, 2};

    debug(input);

    return 0;
}