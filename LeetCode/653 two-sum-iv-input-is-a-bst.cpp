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
class Solution {
    bool findTarget(TreeNode* p, TreeNode *q, int k)
    {
        if(p == nullptr || q == nullptr)
        {
            return false;
        }
        else if(p->val + q->val == k && p == q)
        {
            return findTarget(p->left, q->right, k);
        }
        else if(p->val + q->val == k)
        {
            return true;
        }
        else if(p->val + q->val < k)
        {
            return findTarget(p, q->right, k) || findTarget(p->right, q, k);
        }
        else if(p->val + q->val > k)
        {
            return findTarget(p->left, q, k) || findTarget(p, q->left, k);
        }
        return false;
    }
public:
    bool findTarget(TreeNode* root, int k) {
        return findTarget(root, root, k);
    }
};