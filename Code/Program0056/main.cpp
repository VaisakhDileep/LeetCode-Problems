/*
Created by  : Vaisakh Dileep
Date        : 19, March, 2022
Description : Binary Tree Postorder Traversal.
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

        recursive_solve(node->left, result);
        recursive_solve(node->right, result);

        result.push_back(node->val);
    }

    vector<int> postorderTraversal(TreeNode *root)
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

    cout<<"postorderTraversal(";

    display_binary_tree(head);

    result = Solution {}.postorderTraversal(head);

    cout<<"): ";

    display_vector_int(result);
}

int main()
{
    vector<int> input {1, INT_MIN, 2, INT_MIN, INT_MIN, 3};

    debug(input);

    return 0;
}