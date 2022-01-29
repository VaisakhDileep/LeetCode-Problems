/*
Created by  : Vaisakh Dileep
Date        : 28, January, 2022
Description : 3Sum.
*/

#include<iostream>

#include<vector>

#include<algorithm>

#include "../header_files/display_stl/display_stl.hpp"

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result {};

        sort(nums.begin(), nums.end());

        for(int i {0}; i < static_cast<int>(nums.size()) - 2; i++)
        {
            int left {i + 1}, right {static_cast<int>(nums.size()) - 1}, target_2_sum {-nums[i]};

            while(left < right)
            {
                if((nums[left] + nums[right]) > target_2_sum)
                {
                    right--;
                }
                else if((nums[left] + nums[right]) < target_2_sum)
                {
                    left++;
                }
                else
                {
                    result.push_back(vector<int> {nums[i], nums[left], nums[right]});

                    left++;

                    while((left < nums.size()) and (nums[left] == nums[left - 1]))
                    {
                        left++;
                    }

                    right--;

                    while((right >= 0) and (nums[right] == nums[right + 1]))
                    {
                        right--;
                    }
                }
            }

            while((i < nums.size() - 1) and (nums[i + 1] == nums[i]))
            {
                i++;
            }
        }

        return result;
    }
};

void debug(vector<int> &input)
{
    vector<vector<int>> result {};

    cout<<"threeSum(";

    display_vector_int(input);

    cout<<"): ";

    result = Solution {}.threeSum(input);

    display_vector_vector_int(result);
}

int main()
{
    vector<int> input {-1, 0, 1, 2, -1, -4};

    debug(input);

    return 0;
}