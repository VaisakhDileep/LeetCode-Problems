/*
Created by  : Vaisakh Dileep
Date        : 23, January, 2022
Description : Convert Sorted Array to Binary Search Tree.
*/

#include<iostream>

#include<vector>

#include "../header_files/display_stl/display_stl.hpp"

#include "../header_files/TreeNode/TreeNode.hpp"

using namespace std;

class Solution
{
public:
    TreeNode* recursive_solve(vector<int> &nums, int left, int right)
    {
        if(left > right)
        {
            return nullptr;
        }

        TreeNode *node {};

        int mid {(left + right) / 2};

        node = new TreeNode {nums[mid], nullptr, nullptr};

        node->left = recursive_solve(nums, left, mid - 1);

        node->right = recursive_solve(nums, mid + 1, right);

        return node;
    }

    TreeNode* sortedArrayToBST(vector<int> &nums)
    {
        return recursive_solve(nums, 0, nums.size() - 1);
    }
};

void debug(vector<int> &input)
{
    TreeNode *result {};

    cout<<"sortedArrayToBST(";

    display_vector_int(input);

    cout<<"): ";

    result = Solution {}.sortedArrayToBST(input);

    display_binary_tree(result);
}

int main()
{
    vector<int> input {1, 2, 3, 4, 5, 6, 7, 8, 9};

    debug(input);

    return 0;
}