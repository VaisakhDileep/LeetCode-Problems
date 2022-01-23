/*
Created by  : Vaisakh Dileep
*/

#include<iostream>

#include<queue>

#include<vector>

#include<math.h>

using namespace std;

struct TreeNode // This is the format used in representing trees in LeetCode.
{
    int val;

    TreeNode *left;
    TreeNode *right;

    TreeNode() : val {0}, left {nullptr}, right {nullptr} {}

    TreeNode(int x) : val {x}, left {nullptr}, right {nullptr} {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val {x}, left {left}, right {right} {}
};

void create_binary_tree(TreeNode **node, vector<int> vec_nodes, int i)
{
    if((i < vec_nodes.size()) and (vec_nodes[i] != INT_MIN)) // "INT_MIN" corresponds to "nullptr".
    {
        *node = new TreeNode {vec_nodes[i], nullptr, nullptr};

        create_binary_tree(&((*node)->left), vec_nodes, (2 * (i + 1)) - 1);

        create_binary_tree(&((*node)->right), vec_nodes, (2 * (i + 1)));
    }
}

bool contains_non_null_node(vector<TreeNode*> vec_nodes)
{
    for(int i {0}; i < vec_nodes.size(); i++)
    {
        if(vec_nodes[i] != nullptr)
        {
            return true;
        }
    }

    return false;
}

void display_binary_tree(TreeNode *head)
{
    if(head == nullptr)
    {
        cout<<"[ ]";

        return ;
    }

    vector<vector<TreeNode*>> nodes_in_level {};

    vector<TreeNode*> nodes_in_current_level {};

    queue<TreeNode*> Q {};

    int node_counter {0}, current_level {0};

    Q.push(head);

    nodes_in_current_level.push_back(head);

    node_counter++;

    while(Q.empty() == false)
    {
        if(node_counter == pow(2, current_level))
        {
            if(contains_non_null_node(nodes_in_current_level) == false)
            {
                break;
            }

            node_counter = 0;

            nodes_in_level.push_back(nodes_in_current_level);

            nodes_in_current_level = vector<TreeNode*> {};

            current_level++;
        }

        TreeNode *current_node {Q.front()};

        Q.pop();

        if(current_node == nullptr)
        {
            Q.push(nullptr);
            Q.push(nullptr);

            nodes_in_current_level.push_back(nullptr);
            nodes_in_current_level.push_back(nullptr);
        }
        else
        {
            Q.push(current_node->left);
            Q.push(current_node->right);

            nodes_in_current_level.push_back(current_node->left);
            nodes_in_current_level.push_back(current_node->right);
        }

        node_counter += 2;
    }

    cout<<"[ ";
    for(int i {0}; i < nodes_in_level.size(); i++)
    {
        cout<<"[ ";
        for(int j {0}; j < nodes_in_level[i].size(); j++)
        {
            if(nodes_in_level[i][j] == nullptr)
            {
                cout<<"null ";

                continue;
            }

            cout<<nodes_in_level[i][j]->val<<" ";
        }
        cout<<"] ";
    }
    cout<<"]";
}