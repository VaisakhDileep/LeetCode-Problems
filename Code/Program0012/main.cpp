/*
Created by  : Vaisakh Dileep
Date        : 19, January, 2022
Description : Palindrome Linked List.
*/

// This approach uses no extra space.

#include<iostream>

#include "../header_files/ListNode/ListNode.hpp"

using namespace std;

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *slow {head}, *fast {head};

        while(fast->next != nullptr)
        {
            fast = fast->next;

            if(fast->next != nullptr)
            {
                fast = fast->next;
            }

            slow = slow->next;
        }

        ListNode *previous {slow}, *current {slow->next}, *next {}; // "slow" is now at the middle of the linked list.

        previous->next = nullptr;

        while(current != nullptr)
        {
            next = current->next;

            current->next = previous;

            previous = current;

            current = next;
        }

        ListNode *last {previous};

        while((head != nullptr) and (last != nullptr))
        {
            if(head->val != last->val)
            {
                return false;
            }

            head = head->next;

            last = last->next;
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
    vector<int> input {1, 2, 1};

    debug(input);

    return 0;
}