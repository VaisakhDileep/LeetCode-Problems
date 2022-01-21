/*
Created by  : Vaisakh Dileep
Date        : 17, January, 2022
Description : Merge Two Sorted Lists.
*/

#include<iostream>

#include<vector>

#include "../header_files/ListNode/ListNode.hpp"

using namespace std;

class Solution
{
public:
    ListNode* mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *head {new ListNode {0, nullptr}};

        ListNode *current_node {head};

        while((list1 != nullptr) and (list2 != nullptr))
        {
            if(list1->val < list2->val)
            {
                current_node->next = list1;

                current_node = current_node->next;

                list1 = list1->next;
            }
            else
            {
                current_node->next = list2;

                current_node = current_node->next;

                list2 = list2->next;
            }
        }

        if(list1 != nullptr)
        {
            current_node->next = list1;
        }

        if(list2 != nullptr)
        {
            current_node->next = list2;
        }

        return head->next;
    }
};

void debug(vector<int> &input_1, vector<int> &input_2)
{
    ListNode *head_1 {create_linked_list(input_1)}, *head_2 {create_linked_list(input_2)}, *result {};

    cout<<"mergeTwoLists(";

    display_linked_list(head_1);

    cout<<", ";

    display_linked_list(head_2);

    cout<<"): ";

    result = Solution {}.mergeTwoLists(head_1, head_2);

    display_linked_list(result);
}

int main()
{
    vector<int> input_1 {1, 4, 5, 6, 8, 9, 11}, input_2 {0, 2, 7, 8, 10};

    debug(input_1, input_2);

    return 0;
}