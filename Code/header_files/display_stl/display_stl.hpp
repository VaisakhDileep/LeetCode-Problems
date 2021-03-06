/*
Created by : Vaisakh Dileep
*/

#include<vector>

#include<iostream>

#include<unordered_map>

using namespace std;

void display_vector_vector_char(const vector<vector<char>> &vec_vec_char)
{
    cout<<"[\n";
    for(int i {0}; i < vec_vec_char.size(); i++)
    {
        cout<<" [ ";
        for(int j {0}; j < vec_vec_char[i].size(); j++)
        {
            cout<<vec_vec_char[i][j]<<" ";
        }
        cout<<"]\n";
    }
    cout<<"]";
}

void display_vector_vector_int(const vector<vector<int>> &vec_vec_int)
{
    cout<<"[\n";
    for(int i {0}; i < vec_vec_int.size(); i++)
    {
        cout<<" [ ";
        for(int j {0}; j < vec_vec_int[i].size(); j++)
        {
            cout<<vec_vec_int[i][j]<<" ";
        }
        cout<<"]\n";
    }
    cout<<"]";
}

void display_vector_int(const vector<int> &vec_int)
{
    cout<<"[ ";
    for(int i {0}; i < vec_int.size(); i++)
    {
        cout<<vec_int[i]<<" ";
    }
    cout<<"]";
}

void display_vector_string(const vector<string> &vec_string)
{
    cout<<"[ ";
    for(int i {0}; i < vec_string.size(); i++)
    {
        cout<<"\""<<vec_string[i]<<"\" ";
    }
    cout<<"]";
}

void display_unordered_map_int_int(unordered_map<int, int> &unordered_map_int_int)
{
    cout<<"[ ";
    for(auto itr {unordered_map_int_int.begin()}; itr != unordered_map_int_int.end(); itr++)
    {
        cout<<"("<<itr->first<<": "<<itr->second<<") ";
    }
    cout<<"]";
}