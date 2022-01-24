/*
Created by  : Vaisakh Dileep
Date        : 18, January, 2022
Description : Watering Plants II.
*/

#include<iostream>

#include<vector>

#include "../header_files/display_stl/display_stl.hpp"

using namespace std;

class Solution
{
public:
    int minimumRefill(vector<int> &plants, int capacityA, int capacityB)
    {
        int start {0}, end {static_cast<int>(plants.size()) - 1};

        int current_A {capacityA}, current_B {capacityB};

        int refills {0};

        while(start < end)
        {
            if(plants[start] > current_A)
            {
                current_A = capacityA;

                refills++;
            }

            current_A -= plants[start];

            if(plants[end] > current_B)
            {
                current_B = capacityB;

                refills++;
            }

            current_B -= plants[end];

            start++;

            end--;
        }

        if((start == end) and (plants[start] > max(current_A, current_B)))
        {
            refills++;
        }

        return refills;
    }
};

void debug(vector<int> &input_1, int &input_2, int &input_3)
{
    int result {Solution {}.minimumRefill(input_1, input_2, input_3)};

    cout<<"minimumRefill(";

    display_vector_int(input_1);

    cout<<", "<<input_2<<", "<<input_3<<"): "<<result;
}

int main()
{
    vector<int> input_1 {2, 2, 3, 3};

    int input_2 {5}, input_3 {5};

    debug(input_1, input_2, input_3);

    return 0;
}