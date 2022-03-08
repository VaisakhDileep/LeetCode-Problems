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
    void recursive_solve(vector<int> &nums, unordered_map<int, int> &u_m, vector<vector<int>> &result, vector<int> &current)
    {
        if(current.size() == nums.size())
        {
            result.push_back(current);

            return ;
        }

        for(auto itr {u_m.begin()}; itr != u_m.end(); itr++)
        {
            if(itr->second != 0)
            {
                itr->second--;

                current.push_back(itr->first);

                recursive_solve(nums, u_m, result, current);

                current.pop_back();

                itr->second++;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> result {};

        vector<int> current {};

        unordered_map<int, int> u_m {};

        for(int i {0}; i < nums.size(); i++)
        {
            if(u_m.find(nums[i]) != u_m.end())
            {
                u_m[nums[i]]++;
            }
            else
            {
                u_m[nums[i]] = 1;
            }
        }

        recursive_solve(nums, u_m, result, current);

        return result;
    }
};

void debug(vector<int> &input)
{
    vector<vector<int>> result {Solution {}.permuteUnique(input)};

    cout<<"permuteUnique(";

    display_vector_int(input);

    cout<<"): \n";

    display_vector_vector_int(result);
}

int main()
{
    vector<int> input {1, 1, 2};

    debug(input);

    return 0;
}