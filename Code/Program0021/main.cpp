/*
Created by  : Vaisakh Dileep
Date        : 24, January, 2022
Description : Reverse Words in a String II.
*/

#include<iostream>

using namespace std;

class Solution
{
public:
    void reverse_substring(string &str, int start, int end)
    {
        int i {start}, j {end - 1};

        while(i < j)
        {
            swap(str[i], str[j]);

            i++;
            j--;
        }
    }

    string reverseWords(string s)
    {
        int start {0}, end {0};

        while(true)
        {
            if(start > s.size())
            {
                break;
            }

            while((end < s.size()) and (s[end] != ' '))
            {
                end++;
            }

            reverse_substring(s, start, end);

            start = end + 1;

            end++;
        }

        return s;
    }
};

void debug(string &input)
{
    string result {};

    cout<<"reverseWords(\""<<input<<"\"): ";

    result = Solution {}.reverseWords(input);

    cout<<"\""<<result<<"\"";
}

int main()
{
    string input {"hello world"};

    debug(input);

    return 0;
}