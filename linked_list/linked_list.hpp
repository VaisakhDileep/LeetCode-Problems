/*
Created by  : Vaisakh Dileep
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

void display_linked_list(ListNode *list_node)
{
    cout<<"[";
    while(list_node != nullptr)
    {
        cout<<list_node->val<<((list_node->next == nullptr) ? "" : " ");

        list_node = list_node->next;
    }
    cout<<"]";
}