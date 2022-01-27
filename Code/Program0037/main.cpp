/*
Created by  : Vaisakh Dileep
Date        : 27, January, 2022
Description : Insert into a Binary Search Tree.
*/

#include<iostream>

#include "../header_files/TreeNode/TreeNode.hpp"

using namespace std;

class Solution
{
public:
    TreeNode* insertIntoBST(TreeNode *root, int val)
    {
        if(root == nullptr)
        {
            return new TreeNode {val, nullptr, nullptr};
        }

        TreeNode *current_node {root};

        while(true)
        {
            if (val > current_node->val)
            {
                if(current_node->right != nullptr)
                {
                    current_node = current_node->right;
                }
                else
                {
                    current_node->right = new TreeNode {val, nullptr, nullptr};

                    return root;
                }
            }

            if(val < current_node->val)
            {
                if(current_node->left != nullptr)
                {
                    current_node = current_node->left;
                }
                else
                {
                    current_node->left = new TreeNode {val, nullptr, nullptr};

                    return root;
                }
            }
        }

        return nullptr; // should never come to this.
    }
};

void debug(vector<int> &input_1, int &input_2)
{
    TreeNode *result {};

    TreeNode *head {};

    create_binary_tree(&head, input_1);

    cout<<"insertIntoBST(";

    display_binary_tree(head);

    cout<<", "<<input_2<<"): ";

    result = Solution {}.insertIntoBST(head, input_2);

    display_binary_tree(result);
}

int main()
{
    vector<int> input_1 {4, 2, 7, 1, 3, INT_MIN, INT_MIN};

    int input_2 {5};

    debug(input_1, input_2);

    return 0;
}