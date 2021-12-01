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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *l, *r;
        if (p->val > q->val) {
            r = p;
            l = q;
        } else {
            l = p;
            r = q;
        }
        TreeNode *cur;
        cur = root;
        while (cur != NULL) {
            if (l->val > cur->val && r->val > cur->val)
                cur = cur->right;
            else if (l->val < cur->val && r->val < cur->val)
                cur = cur->left;
            else
                return cur;
        }
        return NULL;
    }
};