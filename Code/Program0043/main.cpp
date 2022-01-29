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
    vector<vector<int>> two_sum(vector<int> &nums, int left, int right, int target) // here we assume that the given input array is sorted and contains duplicate values.
    {
        vector<vector<int>> result {};

        while(left < right)
        {
            if((nums[left] + nums[right]) < target)
            {
                left++;
            }
            else if((nums[left] + nums[right]) > target)
            {
                right--;
            }
            else
            {
                result.push_back(vector<int> {-target, nums[left], nums[right]});

                left++;

                while((left < nums.size()) and (nums[left - 1] == nums[left]))
                {
                    left++;
                }

                right--;

                while((right >= 0) and (nums[right + 1] == nums[right]))
                {
                    right--;
                }
            }
        }

        return result;
    }

    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result {};

        if(nums.size() < 3)
        {
            return result;
        }

        sort(nums.begin(), nums.end());

        for(int i {0}; i < nums.size() - 2; i++)
        {
            vector<vector<int>> temp {};

            temp = two_sum(nums, i + 1, nums.size() - 1, -nums[i]);

            if(temp.size() == 0)
            {
                continue;
            }

            result.insert(result.end(), temp.begin(), temp.end());

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
    vector<int> input {0, 0, 0};

    debug(input);

    return 0;
}