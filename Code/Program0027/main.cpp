/*
Created by  : Vaisakh Dileep
Date        : 25, January, 2022
Description : Two Sum.
*/

// This is the brute-force approach.

#include<iostream>

#include<vector>

#include "../header_files/display_stl/display_stl.hpp"

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for(int i {0}; i < nums.size(); i++)
        {
            for(int j {i + 1}; j < nums.size(); j++)
            {
                if((nums[i] + nums[j]) == target)
                {
                    return vector<int> {i, j};
                }
            }
        }

        return vector<int> {}; // should never come to this.
    }
};

void debug(vector<int> &input_1, int &input_2)
{
    vector<int> result {Solution {}.twoSum(input_1, input_2)};

    cout<<"twoSum(";

    display_vector_int(input_1);

    cout<<", "<<input_2<<"): ";

    display_vector_int(result);
}

int main()
{
    vector<int> input_1 {2, 7, 11, 15};

    int input_2 {9};

    debug(input_1, input_2);

    return 0;
}