/*
Created by  : Vaisakh Dileep
Date        : 26, January, 2022
Description : Valid Parentheses.
*/

#include<iostream>

#include<unordered_map>

#include<stack>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        unordered_map<char, char> u_m {{'(', ')'}, {'[', ']'}, {'{', '}'}};

        stack<char> stk {};

        for(int i {0}; i < s.size(); i++)
        {
            if(u_m.find(s[i]) != u_m.end())
            {
                stk.push(s[i]);

                continue;
            }

            if(stk.empty() == true)
            {
                return false;
            }

            if(u_m[stk.top()] == s[i])
            {
                stk.pop();
            }
            else
            {
                return false;
            }
        }

        return stk.empty();
    }
};

void debug(string &input)
{
    bool result {Solution {}.isValid(input)};

    cout<<boolalpha;

    cout<<"isValid(\""<<input<<"\": "<<result;
}

int main()
{
    string input {"(())[[]]{{}}"};

    debug(input);

    return 0;
}