/*
Created by  : Vaisakh Dileep
Date        : 18, January, 2022
Description : Combination Sum.
*/

#include<iostream>

#include<vector>

#include "../header_files/display_stl/display_stl.hpp"

using namespace std;

class Solution
{
public:
    void recursive_solve(vector<int> &candidates, vector<int> &combination, vector<vector<int>> &result, int current, int target, int index)
    {
        if(current == target)
        {
            result.push_back(combination);

            return ;
        }

        if(index == candidates.size())
        {
            return ;
        }

        if(current > target)
        {
            return ;
        }

        combination.push_back(candidates[index]);

        recursive_solve(candidates, combination, result, current + candidates[index], target, index);

        combination.pop_back();

        recursive_solve(candidates, combination, result, current, target, index + 1); // As we move to the right branches, we ignore the elements present in the left branches(This will prevent duplicate combinations).
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> combination {};

        vector<vector<int>> result {};

        recursive_solve(candidates, combination, result, 0, target, 0);

        return result;
    }
};

void debug(vector<int> &input_1, int &input_2)
{
    vector<vector<int>> result {Solution {}.combinationSum(input_1, input_2)};

    cout<<"combinationSum(";

    display_vector_int(input_1);

    cout<<", "<<input_2<<"): ";

    display_vector_vector_int(result);
}

int main()
{
    vector<int> input_1 {2, 3, 6, 7};

    int input_2 {7};

    debug(input_1, input_2);

    return 0;
}