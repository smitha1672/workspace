//  Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
//
//  Note:
//  You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
//
//  Example 1:
//  Input: root = [3,1,4,null,2], k = 1
//      3
//     / \
//    1   4
//     \
//      2
//  Output: 1
//
//  Example 2:
//  Input: root = [5,3,6,2,4,null,null,1], k = 3
//         5
//        / \
//       3   6
//      / \
//     2   4
//    /
//   1
//  Output: 3
//  Follow up:
//  What if the BST is modified (insert/delete operations) often and you
//  need to find the kth smallest frequently? How would you optimize the
//  kthSmallest routine?

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
//      int kthSmallest(TreeNode* root, int k);
//  };

#include <stack>
#include <iostream>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

class Solution {
public:
    int kthSmallest(struct TreeNode* root, int k);
};

// in-order travel - recursive way
static int
kthSmallestHelper_recursive(struct TreeNode* root, int& k)
{
    if (root == NULL) return 0; //this behavior is undefined!
    int result = kthSmallestHelper_recursive(root->left, k);
    if (k == 0)
        return result;
    k--;
    if (k == 0)
        return root->val;
    return kthSmallestHelper_recursive(root->right, k);
}

// in-order travel - non-recursive way
static int
kthSmallestHelper_nonRecursive(struct TreeNode* root, int k)
{
    std::stack<struct TreeNode*> s;
    while (!s.empty() || root) {
        while (root) {
            s.push(root);
            root = root->left;
        }
        k--;
        root = s.top()->right;
        if (k==0)
            return s.top()->val;
        s.pop();
    }
    return -1;
}

int
Solution::kthSmallest(struct TreeNode* root, int k)
{
    return kthSmallestHelper_nonRecursive(root, k);
    //return kthSmallestHelper_recursive(root, k);
}

static struct TreeNode*
newTreeNode(int val)
{
    struct TreeNode* tmpnode = new struct TreeNode;
    if (!tmpnode) return NULL;
    tmpnode->val = val;
    tmpnode->left = NULL;
    tmpnode->right = NULL;
    return tmpnode;
}

struct TreeNode*
insert_treenode(struct TreeNode* root, int val)
{
    /*create a new node containing the new element*/
    struct TreeNode* newnode = newTreeNode(val);
    // Pointer to start traversing from root and
    // traverses downward path to search
    // where the new node to be inserted
    struct TreeNode* x = root;
    // Pointer y maintains the trailing
    // pointer of x
    struct TreeNode* y = NULL;
    while (x) {
        y = x;
        if (val < x->val)
            x = x->left;
        else
            x = x->right;
    }
    // If the root is NULL i.e the tree is empty
    // The new node is the root node
    if (y == NULL)
        y = newnode;
    // If the new key is less then the leaf node key
    // Assign the new node to be its left child
    else if (val < y->val)
        y->left = newnode;
    else
        y->right = newnode;
    return y;
}

// A utility function to do inorder
// traversal of BST
static void
inorder(struct TreeNode* root)
{
    if (root == NULL)
        return;
    else {
        inorder(root->left);
        std::cout << root->val << " ";
        inorder(root->right);
    }
}

int
main(void)
{
    struct TreeNode* root = NULL;
    Solution s;
    root = insert_treenode(root, 3);
    insert_treenode(root, 1);
    insert_treenode(root, 4);
    insert_treenode(root, 2);
    inorder(root);
    std::cout << std::endl;
    std::cout << s.kthSmallest(root, 1) << std::endl;
    return 0;
}

