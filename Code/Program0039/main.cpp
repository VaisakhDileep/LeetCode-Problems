/*
Created by  : Vaisakh Dileep
Date        : 27, January, 2022
Description : Capitalize the Title.
*/

#include<iostream>

#include<sstream>

using namespace std;

class Solution
{
public:
    string capitalizeTitle(string title)
    {
        stringstream ss {title};

        string result {};

        string word {};

        while(ss>>word)
        {
            word[0] = toupper(word[0]);

            if(word.size() <= 2)
            {
                word[0] = tolower(word[0]);
            }

            for(int i {1}; i < word.size(); i++)
            {
                word[i] = tolower(word[i]);
            }

            result = result + word + " ";
        }

        result.pop_back();

        return result;
    }
};

void debug(string input)
{
    string result {Solution {}.capitalizeTitle(input)};

    cout<<"capitalizeTitle(\""<<input<<"\"): "<<result;
}

int main()
{
    string input {"A b cD OnE TWO thREE foUR fIVE siX SeveN EighT NINE"};

    debug(input);

    return 0;
}