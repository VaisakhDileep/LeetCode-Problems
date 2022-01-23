/*
Created by  : Vaisakh Dileep
Date        : 23, January, 2022
Description : Linked List Cycle.
*/

// This is solved using the two pointer approach.

#include<iostream>

#include "../header_files/display_stl/display_stl.hpp"

#include "../header_files/ListNode/ListNode.hpp"

using namespace std;

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if((head == nullptr) or (head->next == nullptr))
        {
            return false;
        }

        ListNode *slow_pointer {head}, *fast_pointer {head->next->next};

        while(true)
        {
            if(fast_pointer == nullptr)
            {
                return false;
            }

            if(fast_pointer->next == nullptr)
            {
                return false;
            }

            if(slow_pointer == fast_pointer)
            {
                return true;
            }

            slow_pointer = slow_pointer->next;

            fast_pointer = fast_pointer->next->next;
        }
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