/*
Created by  : Vaisakh Dileep
Date        : 19, January, 2022
Description : Palindrome Linked List.
*/

// This approach using vector.

#include<iostream>

#include "../header_files/ListNode/ListNode.hpp"

using namespace std;

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        vector<int> array {};

        while(head != nullptr)
        {
            array.push_back(head->val);

            head = head->next;
        }

        int start {0}, end {static_cast<int>(array.size()) - 1};

        while(start < end)
        {
            if(array[start] != array[end])
            {
                return false;
            }

            start++;

            end--;
        }

        return true;
    }
};

void debug(vector<int> input)
{
    bool result {};

    ListNode *head {create_linked_list(input)};

    cout<<boolalpha;

    cout<<"isPalindrome(";

    display_linked_list(head);

    result = Solution {}.isPalindrome(head);

    cout<<"): "<<result;
}

int main()
{
    vector<int> input {1, 2, 2, 1};

    debug(input);

    return 0;
}