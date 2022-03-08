/*
Created by  : Vaisakh Dileep
Date        : 29, January, 2022
Description : 4Sum.
*/

#include<iostream>

#include<vector>

#include<algorithm>

#include "../header_files/display_stl/display_stl.hpp"

using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> result {};

        sort(nums.begin(), nums.end());

        for(int i {0}; i < static_cast<int>(nums.size()) - 3; i++)
        {
            for(int j {i + 1}; j < static_cast<int>(nums.size()) - 2; j++)
            {
                int left {j + 1}, right {static_cast<int>(nums.size()) - 1}, target_2_sum {target - (nums[i] + nums[j])};

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
                        result.push_back(vector<int> {nums[i], nums[j], nums[left], nums[right]});

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

                while((j < nums.size() - 1) and (nums[j] == nums[j + 1]))
                {
                    j++;
                }
            }

            while((i < nums.size() - 1) and (nums[i] == nums[i + 1]))
            {
                i++;
            }
        }

        return result;
    }
};

void debug(vector<int> &input_1, int &input_2)
{
    vector<vector<int>> result {};

    cout<<"threeSum(";

    display_vector_int(input_1);

    cout<<", "<<input_2<<"): \n";

    result = Solution {}.fourSum(input_1, input_2);

    display_vector_vector_int(result);
}

int main()
{
    vector<int> input_1 {1, 0, -1, 0, -2, 2};

    int input_2 {0};

    debug(input_1, input_2);

    return 0;
}