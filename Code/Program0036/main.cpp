/*
Created by  : Vaisakh Dileep
Date        : 27, January, 2022
Description : Valid Anagram.
*/

#include<iostream>

#include<unordered_map>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if(s.size() != t.size())
        {
            return false;
        }

        unordered_map<char, int> u_m_1 {}, u_m_2 {};

        for(int i {0}; i < s.size(); i++)
        {
            u_m_1[s[i]]++;
        }

        for(int i {0}; i < t.size(); i++)
        {
            u_m_2[t[i]]++;
        }

        for(auto itr {u_m_1.begin()}; itr != u_m_1.end(); itr++)
        {
            if(u_m_2.find(itr->first) == u_m_2.end())
            {
                return false;
            }

            if(itr->second != u_m_2[itr->first])
            {
                return false;
            }
        }

        return true;
    }
};

void debug(string &input_1, string &input_2)
{
    bool result {Solution {}.isAnagram(input_1, input_2)};

    cout<<boolalpha;

    cout<<"isAnagram(\""<<input_1<<"\", \""<<input_2<<"\"): "<<result;
}

int main()
{
    string input_1 {"angel"}, input_2 {"glean"};

    debug(input_1, input_2);

    return 0;
}