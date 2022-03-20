/*
Created by  : Vaisakh Dileep
Date        : 20, March, 2022
Description : Pascal's Triangle.
*/

#include<iostream>

#include<vector>

#include "../header_files/display_stl/display_stl.hpp"

using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result(numRows, vector<int> {});

        result[0].push_back(1);

        for(int i {1}; i < numRows; i++)
        {
            result[i].push_back(1);

            for(int j {1}; j < i; j++)
            {
                result[i].push_back(result[i - 1][j - 1] + result[i - 1][j]);
            }

            result[i].push_back(1);
        }

        return result;
    }
};

void debug(int &input)
{
    vector<vector<int>> result {Solution {}.generate(input)};

    cout<<"generate("<<input<<"): \n";

    display_vector_vector_int(result);
}

int main()
{
    int input {6};

    debug(input);

    return 0;
}