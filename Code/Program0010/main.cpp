/*
Created by  : Vaisakh Dileep
Date        : 19, January, 2022
Description : Palindrome Linked List.
*/

// This approach uses stack.

#include<iostream>

#include<vector>

#include<stack>

#include "../header_files/ListNode/ListNode.hpp"

using namespace std;

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        stack<int> stk {};

        ListNode *current {head};

        while(current != nullptr)
        {
            stk.push(current->val);

            current = current->next;
        }

        int top_element {};

        while(stk.empty() != true)
        {
            top_element = stk.top();

            stk.pop();

            if(head->val != top_element)
            {
                return false;
            }

            head = head->next;
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