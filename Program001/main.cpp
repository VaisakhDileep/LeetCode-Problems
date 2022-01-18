/*
Created by  : Vaisakh Dileep
Date        : 16, January, 2022
Description : Permutations.
*/

#include<iostream>

#include<vector>

#include "../display_stl/display_stl.hpp"

using namespace std;

class Solution
{
public:
    void recursive_solve(vector<int> &nums, vector<int> &is_visited, vector<vector<int>> &result, vector<int> &current, int index)
    {
        if(current.size() == nums.size())
        {
            result.push_back(current);

            return ;
        }

        for(int i {0}; i < nums.size(); i++)
        {
            if(is_visited[i] == 0)
            {
                is_visited[i] = 1;

                current.push_back(nums[i]);

                recursive_solve(nums, is_visited, result, current, ++index);

                current.pop_back();

                is_visited[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<int> is_visited(nums.size(), 0);

        vector<vector<int>> result {};

        vector<int> current {};

        recursive_solve(nums, is_visited, result, current, 0);

        return result;
    }
};

void debug(vector<int> &input)
{
    vector<vector<int>> result {Solution {}.permute(input)};

    display_vector_int(input);

    cout<<": ";

    display_vector_vector_int(result);
}

int main()
{
    vector<int> input {1, 2, 3};

    debug(input);

    return 0;
}