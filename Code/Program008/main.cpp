/*
Created by  : Vaisakh Dileep
Date        : 18, January, 2022
Description : Combination Sum II.
*/

#include<vector>

#include<iostream>

#include<algorithm>

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

        int previous_index {-1};

        for(int i {index}; i < candidates.size(); i++)
        {
            if((previous_index != -1) and (candidates[i] == candidates[previous_index]))
            {
                continue;
            }

            combination.push_back(candidates[i]);

            recursive_solve(candidates, combination, result, current + candidates[i], target, i + 1);

            combination.pop_back();

            previous_index = i;
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> result {};

        vector<int> combination {};

        sort(candidates.begin(), candidates.end());

        recursive_solve(candidates, combination, result, 0, target, 0);

        return result;
    }
};

void debug(vector<int> &input_1, int input_2)
{
    vector<vector<int>> result {Solution {}.combinationSum2(input_1, input_2)};

    cout<<"combinationSum2(";

    display_vector_int(input_1);

    cout<<", "<<input_2<<"): ";

    display_vector_vector_int(result);
}

int main()
{
    vector<int> input_1 {10, 1, 2, 7, 6, 1, 5};

    int input_2 {8};

    debug(input_1, input_2);

    return 0;
}