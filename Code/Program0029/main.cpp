/*
Created by  : Vaisakh Dileep
Date        : 25, January, 2022
Description : Valid Mountain Array.
*/

#include<iostream>

#include<vector>

#include "../header_files/display_stl/display_stl.hpp"

using namespace std;

class Solution
{
public:
    bool validMountainArray(vector<int> &arr)
    {
        if(arr.size() < 3)
        {
            return false;
        }

        int i {1};

        for(; i < arr.size(); i++) // climbing up.
        {
            if(arr[i] == arr[i - 1])
            {
                return false;
            }

            if(arr[i] < arr[i - 1])
            {
                break;
            }
        }

        if((i == 1) or (i == arr.size())) // the array is in decreasing order.
        {
            return false;
        }

        for(; i < arr.size(); i++) // climbing down.
        {
            if(arr[i] >= arr[i - 1])
            {
                return false;
            }
        }

        return true;
    }
};

void debug(vector<int> &input_1)
{
    bool result {Solution {}.validMountainArray(input_1)};

    cout<<boolalpha;

    cout<<"validMountainArray(";

    display_vector_int(input_1);

    cout<<"): "<<result;
}

int main()
{
    vector<int> input {5, 4, 3, 2, 1};

    debug(input);

    return 0;
}