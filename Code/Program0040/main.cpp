/*
Created by  : Vaisakh Dileep
Date        : 27, January, 2022
Description : To Lower Case.
*/

#include<iostream>

using namespace std;

class Solution
{
public:
    string toLowerCase(string s)
    {
        for(int i {0}; i < s.size(); i++)
        {
            if(isalpha(s[i]))
            {
                s[i] = tolower(s[i]);
            }
        }

        return s;
    }
};

void debug(string &input)
{
    string result {Solution {}.toLowerCase(input)};

    cout<<"toLowerCase(\""<<input<<"\"): "<<result;
}

int main()
{
    string input {"Hello"};

    debug(input);

    return 0;
}