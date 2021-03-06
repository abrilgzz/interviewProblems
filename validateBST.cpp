/*
    Abril Marina Gonzalez Ramirez
    August 2019
    
    LeetCode Problem 98. Validate Binary Search Tree
    Given a binary tree, determine if it is a valid binary search tree (BST).

    Assume a BST is defined as follows:
        The left subtree of a node contains only nodes with keys less than the node's key.
        The right subtree of a node contains only nodes with keys greater than the node's key.
        Both the left and right subtrees must also be binary search trees.

    Runtime: O(n)
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root){
        return isValidBST(root, NULL, NULL);
    }
    
    bool isValidBST(TreeNode* root, TreeNode* min, TreeNode* max){
        if(root == NULL)
            return true;
        
        if ((min && root->val <= min->val) ||
            (max && root->val >= max->val))
            return false;
        
        return (isValidBST(root->left, min, root) && isValidBST(root->right, root, max));
    }
    
};