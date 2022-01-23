/*
Created by  : Vaisakh Dileep
Date        : 23, January, 2022
Description : Linked List Cycle.
*/

#include<iostream>

#include<unordered_set>

#include "../header_files/display_stl/display_stl.hpp"

#include "../header_files/ListNode/ListNode.hpp"

using namespace std;

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        unordered_set<ListNode*> u_s {};

        while(head != nullptr)
        {
            if(u_s.count(head) == 1)
            {
                return true;
            }

            u_s.insert(head);

            head = head->next;
        }

        return false;
    }
};

void debug(vector<int> &input, int tail_point_index = -1)
{
    ListNode *head {create_linked_list_with_cycle(input, tail_point_index)};

    bool result {Solution {}.hasCycle(head)};

    cout<<boolalpha;

    cout<<"hasCycle(";

    display_vector_int(input);

    cout<<", "<<tail_point_index<<"): "<<result;
}

int main()
{
    vector<int> input {1, 2, 3, 4, 5};

    debug(input, 4);

    return 0;
}