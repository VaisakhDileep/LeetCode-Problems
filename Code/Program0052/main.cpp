/*
Created by  : Vaisakh Dileep
Date        : 19, February, 2022
Description : Same Tree.
*/

#include<iostream>

#include "../header_files/TreeNode/TreeNode.hpp"

using namespace std;

class Solution
{
public:
    bool recursive_solve(TreeNode *tree_1, TreeNode *tree_2)
    {
        if((tree_1 == nullptr) and (tree_2 == nullptr))
        {
            return true;
        }
        else if((tree_1 == nullptr) or (tree_2 == nullptr))
        {
            return false;
        }
        else if(tree_1->val != tree_2->val)
        {
            return false;
        }
        else
        {
            return (recursive_solve(tree_1->left, tree_2->left) and recursive_solve(tree_1->right, tree_2->right));
        }
    }

    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        return recursive_solve(p, q);
    }
};

void debug(vector<int> &input_1, vector<int> &input_2)
{
    bool result {};

    TreeNode *head_1 {}, *head_2 {};

    create_binary_tree(&head_1, input_1);
    create_binary_tree(&head_2, input_2);

    cout<<"isSameTree(";

    display_binary_tree(head_1);

    cout<<", ";

    display_binary_tree(head_2);

    cout<<"): ";

    result = Solution {}.isSameTree(head_1, head_2);

    cout<<boolalpha;

    cout<<result;
}

int main()
{
    vector<int> input_1 {1, 2, 3}, input_2 {1, 2, 3};

    debug(input_1, input_2);

    return 0;
}