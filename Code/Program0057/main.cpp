/*
Created by  : Vaisakh Dileep
Date        : 19, March, 2022
Description : Longest Common Prefix.
*/

#include<iostream>

#include<vector>

#include "../header_files/display_stl/display_stl.hpp"

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string prefix {strs[0]};

        for(int i {1}; i < strs.size(); i++)
        {
            int j {0};

            for(; j < prefix.size(); j++)
            {
                if(strs[i][j] != prefix[j])
                {
                    break;
                }
            }

            prefix = prefix.substr(0, j);
        }

        return prefix;
    }
};

void debug(vector<string> &input)
{
    string result {Solution {}.longestCommonPrefix(input)};

    cout<<"longestCommonPrefix(";

    display_vector_string(input);

    cout<<"): "<<result;
}

int main()
{
    vector<string> input {"flower", "flow", "flight"};

    debug(input);

    return 0;
}