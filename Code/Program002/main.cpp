/*
Created by  : Vaisakh Dileep
Date        : 16, January, 2022
Description : Permutations II.
*/

#include<iostream>

#include<vector>

#include<unordered_map>

#include "../header_files/display_stl/display_stl.hpp"

using namespace std;

class Solution
{
public:
    void recursive_solve(vector<int> &nums, unordered_map<int, int> &table, vector<vector<int>> &result, vector<int> &current)
    {
        if(current.size() == nums.size())
        {
            result.push_back(current);

            return ;
        }

        for(auto itr {table.begin()}; itr != table.end(); itr++)
        {
            if(itr->second != 0)
            {
                itr->second--;

                current.push_back(itr->first);

                recursive_solve(nums, table, result, current);

                current.pop_back();

                itr->second++;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> result {};

        vector<int> current {};

        unordered_map<int, int> table {};

        for(int i {0}; i < nums.size(); i++)
        {
            if(table.find(nums[i]) != table.end())
            {
                table[nums[i]]++;
            }
            else
            {
                table[nums[i]] = 1;
            }
        }

        recursive_solve(nums, table, result, current);

        return result;
    }
};

void debug(vector<int> &input)
{
    vector<vector<int>> result {Solution {}.permuteUnique(input)};

    cout<<"permuteUnique(";

    display_vector_int(input);

    cout<<"): ";

    display_vector_vector_int(result);
}

int main()
{
    vector<int> input {1, 1, 2};

    debug(input);

    return 0;
}