/*
Created by  : Vaisakh Dileep
Date        : 26, January, 2022
Description : Maximum Depth of Binary Tree.
*/

#include<iostream>

#include<vector>

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

        int left_height {}, right_height {};

        left_height = recursive_solve(node->left);

        right_height = recursive_solve(node->right);

        return max(left_height, right_height) + 1;
    }

    int maxDepth(TreeNode *root)
    {
        return recursive_solve(root);
    }
};

void debug(vector<int> input)
{
    int result {};

    TreeNode *head {};

    create_binary_tree(&head, input);

    cout<<"maxDepth(";

    display_binary_tree(head);

    result = Solution {}.maxDepth(head);

    cout<<"): "<<result;
}

int main()
{
    vector<int> input {3, 9, 20, INT_MIN, INT_MIN, 15, 7};

    debug(input);

    return 0;
}