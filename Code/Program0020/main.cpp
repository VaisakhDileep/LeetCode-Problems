/*
Created by  : Vaisakh Dileep
Date        : 24, January, 2022
Description : Reverse Words in a String.
*/

// This approach uses extra space.

#include<iostream>

#include<vector>

#include "../header_files/display_stl/display_stl.hpp"

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        string result {};

        vector<string> words {};

        int start {0}, end {0};

        while(true)
        {
            while((start < s.size()) and (s[start] == ' '))
            {
                start++;
            }

            if(start == s.size())
            {
                break ;
            }

            end = start;

            while((end < s.size()) and (s[end] != ' '))
            {
                end++;
            }

            words.push_back(s.substr(start, end - start));

            start = end;
        }

        if(words.size() == 0)
        {
            return "";
        }

        for(int i {static_cast<int>(words.size()) - 1}; i > 0; i--)
        {
            result += (words[i] + " ");
        }

        result += words[0];

        return result;
    }
};

void debug(string &input)
{
    string result {Solution {}.reverseWords(input)};

    cout<<"reverseWords(\""<<input<<"\"): \""<<result<<"\"";
}

int main()
{
    string input {"   hello     world     "};

    debug(input);

    return 0;
}