/*
Created by  : Vaisakh Dileep
Date        : 26, January, 2022
Description : Symmetric Tree.
*/

#include<iostream>

#include<vector>

#include "../header_files/display_stl/display_stl.hpp"

#include "../header_files/TreeNode/TreeNode.hpp"

using namespace std;

class Solution
{
public:
    bool recursive_solve(TreeNode *t_1, TreeNode *t_2)
    {
        if((t_1 == nullptr) and (t_2 == nullptr))
        {
            return true;
        }

        if(t_1 == nullptr)
        {
            return false;
        }

        if(t_2 == nullptr)
        {
            return false;
        }

        return (t_1->val == t_2->val) and recursive_solve(t_1->left, t_2->right) and recursive_solve(t_1->right, t_2->left);
    }

    bool isSymmetric(TreeNode *root)
    {
        return recursive_solve(root->left, root->right);
    }
};

void debug(vector<int> input)
{
    bool result {};

    TreeNode *head {};

    cout<<boolalpha;

    create_binary_tree(&head, input);

    cout<<"isSymmetric(";

    display_binary_tree(head);

    result = Solution {}.isSymmetric(head);

    cout<<"): "<<result;
}

int main()
{
    vector<int> input {1, 2, 2, 3, 4, 4, 3};

    debug(input);

    return 0;
}