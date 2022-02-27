/*
Created by  : Vaisakh Dileep
Date        : 27, February, 2022
Description : Validate Binary Search Tree.
*/

#include<iostream>

#include "../header_files/TreeNode/TreeNode.hpp"

using namespace std;

class Solution
{
public:
    bool recursive_solve(TreeNode *current_node, TreeNode **previous_node)
    {
        if(current_node == nullptr)
        {
            return true;
        }

        if(previous_node == nullptr)
        {
            previous_node = new TreeNode* {nullptr};
        }

        if(recursive_solve(current_node->left, previous_node) == false) {return false;}

        if((*previous_node) != nullptr)
        {
            if((*previous_node)->val >= current_node->val)
            {
                return false;
            }
        }

        (*previous_node) = current_node;

        if(recursive_solve(current_node->right, previous_node) == false) {return false;}

        return true;
    }

    bool isValidBST(TreeNode *root)
    {
        return recursive_solve(root, nullptr);
    }
};

void debug(vector<int> &input)
{
    TreeNode *head {};

    bool result {};

    create_binary_tree(&head, input);

    cout<<"isValidBST(";

    display_binary_tree(head);

    cout<<"): ";

    result = Solution {}.isValidBST(head);

    cout<<boolalpha;

    cout<<result;
}

int main()
{
    vector<int> input {5, 1, 4, INT_MIN, INT_MIN, 3, 6};

    debug(input);

    return 0;
}