//  Given a complete binary tree, count the number of nodes.
//
//  Note:
//
//  Definition of a complete binary tree from Wikipedia:
//  In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
//
//  Example:
//
//  Input:
//           1
//          / \
//         2   3
//        / \  /
//       4  5 6
//
//  Output: 6

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//  class Solution {
//  public:
//      int
//      countNodes(TreeNode* root)
//      {
//      }
//  };

#include <iostream>
#include <cmath> // pow
#include <cstdio>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

//  l       r       return
//  1,2,4   1,3
//  2,4     2,5     (2^2-1)+1 = 4
//  3,6     3
//  6       6       (2^1-1)+1 = 2

class Solution1 {
public:
    int
    countNodes(TreeNode* root)
    {
        int iret = 0;
        int hLeft = 0, hRight = 0;
        TreeNode* pLeft = root, *pRight = root;
        while (pLeft) {
            ++hLeft;
            pLeft = pLeft->left;
        }
        while (pRight) {
            ++hRight;
            pRight = pRight->right;
        }
        if (hLeft == hRight)
            return (pow(2, hLeft) - 1);
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

class Solution2 {
public:
    int
    countNodes(TreeNode* root)
    {
        int hLeft = leftHeight(root);
        int hRight = rightHeight(root);
        if (hLeft == hRight) return pow(2, hLeft) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
    int
    leftHeight(TreeNode* root)
    {
        if (!root) return 0;
        return 1 + leftHeight(root->left);
    }
    int
    rightHeight(TreeNode* root)
    {
        if (!root) return 0;
        return 1 + rightHeight(root->right);
    }
};

struct TreeNode*
newNode(int data)
{
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

int
main(void)
{
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right = newNode(3);
    root->right->left = newNode(6);
    Solution1 s;
    cout << s.countNodes(root) << endl;
    return 0;
}
