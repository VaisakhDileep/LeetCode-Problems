/*
Created by  : Vaisakh Dileep
Date        : 25, January, 2022
Description : Majority Element.
*/

#include<iostream>

#include<vector>

#include "../header_files/display_stl/display_stl.hpp"

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int result {0}, counter {0};

        for(int i {0}; i < nums.size(); i++)
        {
            if(counter == 0)
            {
                result = nums[i];

                counter++;
            }
            else
            {
                if(nums[i] == result)
                {
                    counter++;
                }
                else
                {
                    counter--;
                }
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