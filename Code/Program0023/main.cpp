/*
Created by  : Vaisakh Dileep
Date        : 25, January, 2022
Description : Reverse Words in a String.
*/

// This approach does not use any extra space.

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
        int s_start {0}, s_end {static_cast<int>(s.size()) - 1};

        while(s[s_start] == ' ') // leading spaces.
        {
            s_start++;
        }

        while(s[s_end] == ' ') // trailing spaces.
        {
            s_end--;
        }

        reverse_substring(s, s_start, s_end + 1);

        int i {0};

        int start {s_start}, end {s_start};

        while(true)
        {
            if(start > s_end)
            {
                break;
            }

            while((end <= s_end) and (s[end] != ' '))
            {
                end++;
            }

            reverse_substring(s, start, end);

            for(int j {start}; j < end; j++)
            {
                s[i] = s[j];

                i++;
            }

            s[i] = ' ';

            i++;

            while((end <= s_end) and (s[end] == ' '))
            {
                end++;
            }

            start = end;
        }

        s.resize(i - 1);

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
    string input {"    hello    world    "};

    debug(input);

    return 0;
}