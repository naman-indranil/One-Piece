/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == NULL)
        {
            return root;
        }
        if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
            return root;
        }
        else if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
            return root;
        }

        if (root->left == NULL)
        {
            TreeNode *t = root->right;
            delete root;
            return t;
        }
        else if (root->right == NULL)
        {
            TreeNode *t = root->left;
            delete root;
            return t;
        }
        else
        {
            TreeNode *parent = root;
            TreeNode *child = root->right;
            while (child->left != NULL)
            {
                parent = child;
                child = child->left;
            }
            if (parent != root)
            {
                parent->left = child->right;
            }
            else
            {
                parent->right = child->right;
            }
            root->val = child->val;
            delete child;
            return root;
        }
    }
};