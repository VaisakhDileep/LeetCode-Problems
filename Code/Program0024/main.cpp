/*
Created by  : Vaisakh Dileep
Date        : 25, January, 2022
Description : Fizz Buzz.
*/

#include<iostream>

#include<vector>

#include "../header_files/display_stl/display_stl.hpp"

using namespace std;

class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> result(n, "");

        for(int i {0}; i < n; i++)
        {
            if((i + 1) % 15 == 0)
            {
                result[i] = "FizzBuzz";
            }
            else if((i + 1) % 3 == 0)
            {
                result[i] = "Fizz";
            }
            else if((i + 1) % 5 == 0)
            {
                result[i] = "Buzz";
            }
            else
            {
                result[i] = to_string(i + 1);
            }
        }

        return result;
    }
};

void debug(int &input)
{
    vector<string> result {Solution {}.fizzBuzz(input)};

    cout<<"fizzBuzz("<<input<<"): ";

    display_vector_string(result);
}

int main()
{
    int input {16};

    debug(input);

    return 0;
}