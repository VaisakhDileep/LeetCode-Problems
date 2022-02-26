/*
Created by : Vaisakh Dileep
*/

#include<iostream>

#include<vector>

#include<math.h>

#include<iomanip>

using namespace std;

void display_unweighted_graph_adj_matrix(const vector<vector<int>> &graph) // We use adjacency matrix.
{
    int width {static_cast<int>(floor(log10(graph.size()))) + 1};

    for(int i {0}; i < width; i++) {cout<<((i == (width - 1)) ? "   " : " ");}

    for(int i {0}; i < graph.size(); i++)
    {
        cout<<setw(width)<<left<<i<<" ";
    }

    cout<<"\n";

    for(int i {0}; i < graph.size(); i++)
    {
        cout<<setw(width)<<left<<i<<"| ";

        for(int j {0}; j < graph[i].size(); j++)
        {
            cout<<setw(width)<<left<<graph[i][j]<<" ";
        }

        cout<<"\n";
    }
}

void display_unweighed_graph_adj_list(const vector<vector<int>> &graph) // We use adjacency list.
{
    for(int i {0}; i < graph.size(); i++)
    {
        if(graph[i].size() == 0)
        {
            continue ;
        }

        cout<<i<<" -> { ";

        for(int j {0}; j < graph[i].size(); j++)
        {
            cout<<graph[i][j]<<" ";
        }

        cout<<"}\n";
    }
}