/*
Created by  : Vaisakh Dileep
Date        : 20, January, 2022
Description : Reverse Linked List.
*/

// This approach solves the problem recursively.

#include<iostream>

#include<vector>

#include "../header_files/ListNode/ListNode.hpp"

using namespace std;

class Solution
{
public:
    ListNode* reverseList(ListNode *head)
    {
        if(head == nullptr)
        {
            return nullptr; // In case if the linked list is empty.
        }

        if(head->next == nullptr)
        {
            return head; // The new head node.
        }

        ListNode *current_node {head}, *next_node {head->next}, *new_head {};

        new_head = reverseList(head->next);

        next_node->next = current_node;

        current_node->next = nullptr;

        return new_head;
    }
};

void debug(vector<int> &input)
{
    ListNode *head {create_linked_list(input)}, *result {};

    cout<<"reverseList(";

    display_linked_list(head);

    cout<<"): ";

    result = Solution {}.reverseList(head);

    display_linked_list(result);
}

int main()
{
    vector<int> input {1, 2, 3, 4, 5};

    debug(input);

    return 0;
}