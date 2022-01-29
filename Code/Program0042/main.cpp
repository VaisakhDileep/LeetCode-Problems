/*
Created by  : Vaisakh Dileep
Date        : 28, January, 2022
Description : Two Sum II - Input Array is Sorted.
*/

// This approach uses the two-pointer method.

#include<iostream>

#include<vector>

#include "../header_files/display_stl/display_stl.hpp"

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int start {0}, end {static_cast<int>(numbers.size()) - 1};

        while(start < end)
        {
            if((numbers[start] + numbers[end]) > target)
            {
                end--;
            }
            else if((numbers[start] + numbers[end]) < target)
            {
                start++;
            }
            else
            {
                return vector<int> {start + 1, end + 1};
            }
        }

        return vector<int> {0, 0}; // should never come to this.
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
    vector<int> input_1 {1, 2, 3, 4, 5};

    int input_2 {9};

    debug(input_1, input_2);

    return 0;
}