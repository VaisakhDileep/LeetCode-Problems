/*
Created by  : Vaisakh Dileep
Date        : 17, February, 2022
Description : Binary Tree Inorder Traversal.
*/

#include<iostream>

#include<vector>

#include "../header_files/TreeNode/TreeNode.hpp"

#include "../header_files/display_stl/display_stl.hpp"

using namespace std;

class Solution
{
    void recursive_solve(TreeNode *node, vector<int> &result)
    {
        if(node == nullptr)
        {
            return ;
        }

        recursive_solve(node->left, result);

        result.push_back(node->val);

        recursive_solve(node->right, result);
    }

public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result {};

        recursive_solve(root, result);

        return result;
    }
};

void debug(vector<int> &input)
{
    vector<int> result {};

    TreeNode *head {};

    create_binary_tree(&head, input);

    cout<<"inorderTraversal(";

    display_binary_tree(head);

    result = Solution {}.inorderTraversal(head);

    cout<<"): ";

    display_vector_int(result);
}

int main()
{
    vector<int> input {1, INT_MIN, 2, INT_MIN, INT_MIN, 3};

    debug(input);

    return 0;
}