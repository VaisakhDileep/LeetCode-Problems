/*
Created by  : Vaisakh Dileep
Date        : 25, January, 2022
Description : Majority Element.
*/

// This approach uses map.

#include<iostream>

#include<vector>

#include<unordered_map>

#include "../header_files/display_stl/display_stl.hpp"

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> u_m {};

        for(int i {0}; i < nums.size(); i++)
        {
            u_m[nums[i]]++;
        }

        int result {0}, count {0};

        for(auto itr {u_m.begin()}; itr != u_m.end(); itr++)
        {
            if(itr->second > count)
            {
                result = itr->first;

                count = itr->second;
            }
        }

        return result;
    }
};

void debug(vector<int> &input)
{
    int result {Solution {}.majorityElement(input)};

    cout<<"majorityElement(";

    display_vector_int(input);

    cout<<"): "<<result;
}

int main()
{
    vector<int> input {1, 2, 6, 3, 3, 3};

    debug(input);

    return 0;
}