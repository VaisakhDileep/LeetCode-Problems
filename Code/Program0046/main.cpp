/*
Created by  : Vaisakh Dileep
Date        : 31, January, 2022
Description : Jump Game.
*/

// This approach uses greedy strategy.

#include<iostream>

#include<vector>

#include "../header_files/display_stl/display_stl.hpp"

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        if(nums.size() == 0)
        {
            return true;
        }

        int counter {1};

        for(int i {static_cast<int>(nums.size()) - 2}; i >= 0; i--)
        {
            if((nums[i] >= counter) and (nums[i] != 0))
            {
                counter = 1;
            }
            else
            {
                counter++;
            }
        }

        return (counter == 1);
    }
};

void debug(vector<int> &input)
{
    bool result {Solution {}.canJump(input)};

    cout<<boolalpha;

    cout<<"canJump(";

    display_vector_int(input);

    cout<<"): "<<result;
}

int main()
{
    vector<int> input {0, 1};

    debug(input);

    return 0;
}