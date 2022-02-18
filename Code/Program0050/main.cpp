/*
Created by  : Vaisakh Dileep
Date        : 18, February, 2022
Description : Minimum Distance Between BST Nodes.
*/

#include<iostream>

#include "../header_files/TreeNode/TreeNode.hpp"

using namespace std;

class Solution
{
public:
    void inorder_traversal(TreeNode *root, vector<int> &sorted_list)
    {
        if(root == nullptr)
        {
            return ;
        }

        inorder_traversal(root->left, sorted_list);

        sorted_list.push_back(root->val);

        inorder_traversal(root->right, sorted_list);
    }

    int minDiffInBST(TreeNode *root)
    {
        vector<int> sorted_list {};

        inorder_traversal(root, sorted_list);

        int result {INT_MAX};

        for(int i {0}; i < sorted_list.size() - 1; i++)
        {
            if((sorted_list[i + 1] - sorted_list[i]) < result)
            {
                result = (sorted_list[i + 1] - sorted_list[i]);
            }
        }

        return result;
    }
};

void debug(vector<int> &input)
{
    int result {};

    TreeNode *head {};

    create_binary_tree(&head, input);

    cout<<"minDiffInBST(";

    display_binary_tree(head);

    result = Solution {}.minDiffInBST(head);

    cout<<"): "<<result;
}

int main()
{
    vector<int> input {4, 2, 6, 1, 3};

    debug(input);

    return 0;
}