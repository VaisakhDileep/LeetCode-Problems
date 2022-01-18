/*
Created by  : Vaisakh Dileep
Date        : 17, January, 2022
Description : Next Permutation.
*/

#include<iostream>

#include<vector>

#include<algorithm>

#include "../display_stl/display_stl.hpp"

using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int peak_index {-1};

        for(int i {static_cast<int>(nums.size()) - 1}; i > 0; i--)
        {
            if(nums[i] > nums[i - 1])
            {
                peak_index = i;

                break;
            }
        }

        if(peak_index == -1) // If we couldn't find any peak that means the elements are in descending order.
        {
            sort(nums.begin(), nums.end());

            return ;
        }

        int swap_index_1 {peak_index - 1};
        int swap_index_2 {swap_index_1};

        for(int i {peak_index + 1}; i < nums.size(); i++)
        {
            if((swap_index_1 == swap_index_2) and (nums[i] > nums[swap_index_1]))
            {
                swap_index_2 = i;

                continue;
            }

            if((nums[i] > nums[swap_index_1]) and (nums[i] < nums[swap_index_2]))
            {
                swap_index_2 = i;
            }
        }

        if(swap_index_1 != swap_index_2)
        {
            swap(nums[swap_index_1], nums[swap_index_2]);
        }
        else
        {
            swap(nums[peak_index], nums[swap_index_1]);
        }

        sort(nums.begin() + peak_index, nums.end());
    }
};

void debug(vector<int> &input)
{
    cout<<"nextPermutation(";

    display_vector_int(input);

    cout<<"): ";

    Solution {}.nextPermutation(input);

    display_vector_int(input);
}

int main()
{
    vector<int> input {1, 3, 2};

    debug(input);

    return 0;
}