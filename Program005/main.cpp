/*
Created by  : Vaisakh Dileep
Date        : 18, January, 2022
Description : Watering Plants.
*/

#include<iostream>

#include<vector>

#include "../display_stl/display_stl.hpp"

using namespace std;

class Solution
{
public:
    int wateringPlants(vector<int> &plants, int capacity)
    {
        int bucket {capacity};

        int steps {0};

        for(int i {0}; i < plants.size(); i++)
        {
            if(plants[i] <= bucket)
            {
                bucket -= plants[i];

                steps++;
            }
            else
            {
                steps += (2 * (i + 1)) + 1 - 2; // We subtract '2' since we had to do the refilling when we reached the previous plant.

                bucket = capacity - plants[i];
            }
        }

        return steps;
    }
};

void debug(vector<int> &input_1, int input_2)
{
    int result {Solution {}.wateringPlants(input_1, input_2)};

    cout<<"wateringPlants(";

    display_vector_int(input_1);

    cout<<", "<<input_2<<"): "<<result;
}

int main()
{
    vector<int> input_1 {1, 1, 1, 4, 2, 3};

    int input_2 {4};

    debug(input_1, input_2);

    return 0;
}