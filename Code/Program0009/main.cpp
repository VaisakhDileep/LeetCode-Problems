/*
Created by  : Vaisakh Dileep
Date        : 19, January, 2022
Description : Asteroid Collision.
*/

#include<iostream>

#include<vector>

#include<stack>

#include<algorithm>

#include "../header_files/display_stl/display_stl.hpp"

using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> result {};

        stack<int> stk {};

        int i {0}, top_element {};

        while(i < asteroids.size())
        {
            if(stk.empty())
            {
                stk.push(asteroids[i]);

                i++;

                continue;
            }

            if(stk.top() < 0)
            {
                stk.push(asteroids[i]);

                i++;

                continue;
            }

            if(asteroids[i] > 0)
            {
                stk.push(asteroids[i]);

                i++;

                continue;
            }

            top_element = stk.top();

            stk.pop();

            if(abs(top_element) == abs(asteroids[i]))
            {
                i++;

                continue;
            }
            else
            {
                asteroids[i] = (abs(top_element) > abs(asteroids[i])) ? top_element : asteroids[i];
            }
        }

        while(!stk.empty())
        {
            result.push_back(stk.top());

            stk.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};

void debug(vector<int> &input)
{
    vector<int> result {};

    cout<<"asteroidCollision(";

    display_vector_int(input);

    result = Solution {}.asteroidCollision(input);

    cout<<"): ";

    display_vector_int(result);
}

int main()
{
    vector<int> input {7, -1, 8};

    debug(input);

    return 0;
}