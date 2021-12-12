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
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> l, r;
        if (p)
            l.push(p);
        if (q)
            r.push(q);
        if (l.size()!=r.size())
            return false;
        while(!l.empty() && !r.empty()) {
            TreeNode *lp = l.top(), *rp = r.top();
            l.pop();
            r.pop();
            if (lp->left==nullptr && rp->left==nullptr) {
                // nothing
            } else if (lp->left!=nullptr && rp->left!=nullptr) {
                l.push(lp->left);   
                r.push(rp->left);
            } else {
                return false;
            }
            if (lp->right==nullptr && rp->right==nullptr) {
                // nothing
            } else if (lp->right!=nullptr && rp->right!=nullptr) {
                l.push(lp->right);   
                r.push(rp->right);
            } else {
                return false;
            }
            if (lp->val!=rp->val)
                return false;
        }
        return true;
    }
};