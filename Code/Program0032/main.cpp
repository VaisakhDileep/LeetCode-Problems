/*
Created by  : Vaisakh Dileep
Date        : 26, January, 2022
Description : Minimum Depth of Binary Tree.
*/

#include<iostream>

#include "../header_files/TreeNode/TreeNode.hpp"

using namespace std;

class Solution
{
public:
    int recursive_solve(TreeNode *node)
    {
        if(node == nullptr)
        {
            return 0;
        }

        if((node->left == nullptr) and (node->right == nullptr)) // leaf node.
        {
            return 1;
        }

        int left_height {0}, right_height {0};

        if(node->left == nullptr)
        {
            return 1 + recursive_solve(node->right);
        }

        if(node->right == nullptr)
        {
            return 1 + recursive_solve(node->left);
        }

        left_height = recursive_solve(node->left);

        right_height = recursive_solve(node->right);

        return min(left_height, right_height) + 1;
    }

    int minDepth(TreeNode *root)
    {
        return recursive_solve(root);
    }
};

void debug(vector<int> &input)
{
    int result {};

    TreeNode *head {};

    create_binary_tree(&head, input);

    cout<<"minDepth(";

    display_binary_tree(head);

    result = Solution {}.minDepth(head);

    cout<<"): "<<result;
}

int main()
{
    vector<int> input {3, 9, 20, INT_MIN, INT_MIN, 15, 7};

    debug(input);

    return 0;
}