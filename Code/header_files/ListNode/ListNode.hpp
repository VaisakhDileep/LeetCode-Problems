/*
Created by : Vaisakh Dileep
*/

#include<vector>

#include<iostream>

using namespace std;

struct ListNode // This is the format used in representing linked lists in LeetCode.
{
    int val;

    ListNode *next;

    ListNode() : val {0}, next {nullptr} {}

    ListNode(int x) : val {x}, next {nullptr} {}

    ListNode(int x, ListNode *next) : val {x}, next {next} {}
};

ListNode* create_linked_list(vector<int> &input)
{
    if(input.size() == 0)
    {
        return nullptr;
    }

    ListNode *head_node {}, *current_node {};

    head_node = new ListNode {input[0], nullptr};

    current_node = head_node;

    for(int i {1}; i < input.size(); i++)
    {
        current_node->next = new ListNode {input[i], nullptr};

        current_node = current_node->next;
    }

    return head_node;
}

ListNode* create_linked_list_with_cycle(vector<int> &input, int tail_point_index = -1) // '-1' means that the linked list does not contain any cycle.
{
    if(input.size() == 0)
    {
        return nullptr;
    }

    ListNode *head_node {}, *current_node {}, *tail_point_node {};

    head_node = new ListNode {input[0], nullptr};

    current_node = head_node;

    if(tail_point_index == 0)
    {
        tail_point_node = head_node;
    }

    for(int i {1}; i < input.size(); i++)
    {
        current_node->next = new ListNode {input[i], nullptr};

        if(i == tail_point_index)
        {
            tail_point_node = current_node->next;
        }

        current_node = current_node->next;
    }

    current_node->next = tail_point_node;

    return head_node;
}

void display_linked_list(ListNode *list_node)
{
    cout<<"[ ";
    while(list_node != nullptr)
    {
        cout<<list_node->val<<" ";

        list_node = list_node->next;
    }
    cout<<"]";
}