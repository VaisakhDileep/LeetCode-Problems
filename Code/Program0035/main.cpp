/*
Created by  : Vaisakh Dileep
Date        : 26, January, 2022
Description : All Elements in Two Binary Search Trees.
*/

#include<iostream>

#include<vector>

#include "../header_files/display_stl/display_stl.hpp"

#include "../header_files/TreeNode/TreeNode.hpp"

using namespace std;

class Solution
{
public:
    void inorder_traversal(TreeNode *node, vector<int> &array_1)
    {
        if(node == nullptr)
        {
            return ;
        }

        inorder_traversal(node->left, array_1);

        array_1.push_back(node->val);

        inorder_traversal(node->right, array_1);
    }

    vector<int> merge_sorted_vectors(vector<int> &array_1, vector<int> &array_2)
    {
        int i {0}, j {0};

        vector<int> result(array_1.size() + array_2.size(), 0);

        int k {0};

        while((i != array_1.size()) and (j != array_2.size()))
        {
            if(array_1[i] < array_2[j])
            {
                result[k++] = array_1[i++];
            }
            else if(array_2[j] < array_1[i])
            {
                result[k++] = array_2[j++];
            }
            else
            {
                result[k++] = array_1[i++];

                result[k++] = array_2[j++];
            }
        }

        while(i != array_1.size())
        {
            result[k++] = array_1[i++];
        }

        while(j != array_2.size())
        {
            result[k++] = array_2[j++];
        }

        return result;
    }

    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        vector<int> array_1 {}, array_2 {};

        inorder_traversal(root1, array_1);
        inorder_traversal(root2, array_2);

        return merge_sorted_vectors(array_1, array_2);
    }
};

void debug(vector<int> input_1, vector<int> input_2)
{
    vector<int> result {};

    TreeNode *head_1 {}, *head_2 {};

    create_binary_tree(&head_1, input_1);
    create_binary_tree(&head_2, input_2);

    cout<<"getAllElements(";

    display_binary_tree(head_1);

    cout<<", ";

    display_binary_tree(head_2);

    cout<<"): ";

    result = Solution {}.getAllElements(head_1, head_2);

    display_vector_int(result);
}

int main()
{
    vector<int> input_1 {2, 1, 4}, input_2 {1, 0, 3};

    debug(input_1, input_2);

    return 0;
}