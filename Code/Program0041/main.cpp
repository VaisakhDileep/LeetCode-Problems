/*
Created by  : Vaisakh Dileep
Date        : 28, January, 2022
Description : Two Sum II - Input Array is Sorted.
*/

// This is solved using the optimized brute-force approach(TLE might happen).

#include<iostream>

#include<vector>

#include "../header_files/display_stl/display_stl.hpp"

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int end_index {static_cast<int>(numbers.size()) - 1};

        for(int i {0}; i <= end_index; i++)
        {
            for(int j {i + 1}; j <= end_index; j++)
            {
                if(numbers[i] + numbers[j] == target)
                {
                    return vector<int> {i + 1, j + 1};
                }

                if((numbers[i] + numbers[j]) > target)
                {
                    end_index--;

                    break;
                }
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