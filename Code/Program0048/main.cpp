/*
Created by  : Vaisakh Dileep
Date        : 16, February, 2022
Description : Binary Tree Preorder Traversal.
*/

#include<iostream>

#include<vector>

#include "../header_files/TreeNode/TreeNode.hpp"

#include "../header_files/display_stl/display_stl.hpp"

using namespace std;

class Solution
{
public:
    void recursive_solve(TreeNode *node, vector<int> &result)
    {
        if(node == nullptr)
        {
            return ;
        }

        result.push_back(node->val);

        recursive_solve(node->left, result);
        recursive_solve(node->right, result);
    }

    vector<int> preorderTraversal(TreeNode *root)
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

    cout<<"preorderTraversal(";

    display_binary_tree(head);

    result = Solution {}.preorderTraversal(head);

    cout<<"): ";

    display_vector_int(result);
}

int main()
{
    vector<int> input {1, INT_MIN, 2, INT_MIN, INT_MIN, 3};

    debug(input);

    return 0;
}