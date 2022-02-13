/*
Created by  : Vaisakh Dileep
Date        : 13, February, 2022
Description : Palindrome Number.
*/

#include<iostream>

using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if(x < 0)
        {
            return false;
        }

        if(x == 0)
        {
            return true;
        }

        if((x % 10) == 0) // If the number ends with '0'.
        {
            return false;
        }

        int reversed_half {};

        while(x > reversed_half)
        {
            reversed_half = (reversed_half * 10) + (x % 10);

            x = x / 10;
        }

        if((x == reversed_half) or (x == (reversed_half / 10)))
        {
            return true;
        }

        return false;
    }
};

void debug(int &input)
{
    bool result {Solution {}.isPalindrome(input)};

    cout<<boolalpha;

    cout<<"isPalindrome("<<input<<"): "<<result;
}

int main()
{
    int input {100};

    debug(input);

    return 0;
}