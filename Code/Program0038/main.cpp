/*
Created by  : Vaisakh Dileep
Date        : 27, January, 2022
Description : Search in a Binary Search Tree.
*/

#include<iostream>

#include "../header_files/TreeNode/TreeNode.hpp"

using namespace std;

class Solution
{
public:
    TreeNode* searchBST(TreeNode *root, int val)
    {
        if(root == nullptr)
        {
            return nullptr;
        }

        TreeNode *current_node {root};

        while(current_node != nullptr)
        {
            if(val > current_node->val)
            {
                current_node = current_node->right;
            }
            else if(val < current_node->val)
            {
                current_node = current_node->left;
            }
            else
            {
                return current_node;
            }
        }

        return nullptr;
    }
};

void debug(vector<int> &input_1, int &input_2)
{
    TreeNode *result {}, *head {};

    create_binary_tree(&head, input_1);

    cout<<"searchBST(";

    display_binary_tree(head);

    cout<<", "<<input_2<<"): ";

    result = {Solution {}.searchBST(head, input_2)};

    display_binary_tree(result);
}

int main()
{
    vector<int> input_1 {4, 2, 7, 1, 3, INT_MIN, INT_MIN};

    int input_2 {2};

    debug(input_1, input_2);

    return 0;
}