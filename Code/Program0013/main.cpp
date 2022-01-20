/*
Created by  : Vaisakh Dileep
Date        : 20, January, 2022
Description : Reverse Linked List.
*/

#include<iostream>

#include "../header_files/linked_list/linked_list.hpp"

using namespace std;

class Solution
{
public:
    ListNode* reverseList(ListNode *head)
    {
        if(head == nullptr)
        {
            return nullptr;
        }

        ListNode *previous {head}, *current {head->next}, *next {};

        previous->next = nullptr;

        while(current != nullptr)
        {
            next = current->next;

            current->next = previous;

            previous = current;

            current = next;
        }

        return previous;
    }
};

void debug(vector<int> input)
{
    ListNode *head {create_linked_list(input)}, *result {};

    cout<<"reverseList(";

    display_linked_list(head);

    result = Solution {}.reverseList(head);

    cout<<"): ";

    display_linked_list(result);
}

int main()
{
    vector<int> input {1, 2, 3, 4, 5};

    debug(input);

    return 0;
}