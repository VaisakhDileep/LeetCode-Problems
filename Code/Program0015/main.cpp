/*
Created by  : Vaisakh Dileep
Date        : 21, January, 2022
Description : Move Zeroes.
*/

#include<iostream>

#include<vector>

#include "../header_files/display_stl/display_stl.hpp"

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int ptr_1 {0}, ptr_2 {0}; // "ptr_2" will contain the index of the left-most zero in each iteration. 

        while(ptr_1 < nums.size())
        {
            if(nums[ptr_1] == 0)
            {
                ptr_1++;
            }
            else
            {
                swap(nums[ptr_1], nums[ptr_2]);

                ptr_1++;
                ptr_2++;
            }
        }
    }
};

void debug(vector<int> &input)
{
    cout<<"moveZeroes(";

    display_vector_int(input);

    cout<<"): ";

    Solution {}.moveZeroes(input);

    display_vector_int(input);
}

int main()
{
    vector<int> input {4, 7, 1, 2, 0, 3, 0, 0, 4};

    debug(input);

    return 0;
}