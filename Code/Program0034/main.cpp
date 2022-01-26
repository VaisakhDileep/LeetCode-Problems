/*
Created by  : Vaisakh Dileep
Date        : 26, January, 2022
Description : Generate Parentheses.
*/

#include<iostream>

#include<vector>

#include "../header_files/display_stl/display_stl.hpp"

using namespace std;

class Solution
{
public:
    void recursive_solve(vector<string> &result, string current, int open_count, int closed_count, int size)
    {
        if(current.size() == size)
        {
            result.push_back(current);

            return ;
        }

        if(open_count < size / 2)
        {
            current.push_back('(');

            recursive_solve(result, current, open_count + 1, closed_count, size);

            current.pop_back();
        }

        if(closed_count < open_count)
        {
            current.push_back(')');

            recursive_solve(result, current, open_count, closed_count + 1, size);
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> result {};

        recursive_solve(result, "", 0, 0, 2 * n);

        return result;
    }
};

void debug(int &input)
{
    vector<string> result {Solution {}.generateParenthesis(input)};

    cout<<"generateParentheses("<<input<<"): ";

    display_vector_string(result);
}

int main()
{
    int input {3};

    debug(input);

    return 0;
}