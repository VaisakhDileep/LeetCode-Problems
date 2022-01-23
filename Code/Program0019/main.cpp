/*
Created by  : Vaisakh Dileep
Date        : 24, January, 2022
Description : Isomorphic Strings.
*/

#include<iostream>

#include<unordered_map>

using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> s_to_t {}, t_to_s {};

        for(int i {0}; i < s.size(); i++)
        {
            if(s_to_t.find(s[i]) != s_to_t.end())
            {
                if(t[i] != s_to_t[s[i]])
                {
                    return false;
                }
            }
            else
            {
                s_to_t[s[i]] = t[i];
            }
        }

        for(int i {0}; i < t.size(); i++)
        {
            if(t_to_s.find(t[i]) != t_to_s.end())
            {
                if(s[i] != t_to_s[t[i]])
                {
                    return false;
                }
            }
            else
            {
                t_to_s[t[i]] = s[i];
            }
        }

        return true;
    }
};

void debug(string &input_1, string &input_2)
{
    bool result {Solution {}.isIsomorphic(input_1, input_2)};

    cout<<boolalpha;

    cout<<"isIsomorphic("<<input_1<<", "<<input_2<<"): "<<result;
}

int main()
{
    string input_1 {"egg"}, input_2 {"abb"};

    debug(input_1, input_2);

    return 0;
}