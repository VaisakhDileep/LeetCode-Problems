/*
Created by  : Vaisakh Dileep
Date        : 29, January, 2022
Description : Count Special Quadruplets.
*/

#include<iostream>

#include<vector>

#include "../header_files/display_stl/display_stl.hpp"

using namespace std;

class Solution
{
public:
    int countQuadruplets(vector<int> &nums)
    {
        int result {0};

        for(int i {0}; i < nums.size(); i++)
        {
            for(int j {i + 1}; j < nums.size(); j++)
            {
                for(int k {j + 1}; k < nums.size(); k++)
                {
                    for(int l {k + 1}; l < nums.size(); l++)
                    {
                        if((nums[i] + nums[j] + nums[k]) == nums[l])
                        {
                            result++;
                        }
                    }
                }
            }
        }

        return result;
    }
};

void debug(vector<int> &input)
{
    int result {Solution {}.countQuadruplets(input)};

    cout<<"countQuadruplets(";

    display_vector_int(input);

    cout<<"): "<<result;
}

int main()
{
    vector<int> input {1, 2, 3, 6};

    debug(input);

    return 0;
}