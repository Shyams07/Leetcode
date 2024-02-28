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
    bool isValidBST(TreeNode* root) {
        long long int min=LLONG_MIN, max=LLONG_MAX;
        return ispos(root,min,max);
    }
    bool ispos(TreeNode* root,long long min,long long max){
        if(root==NULL) return true;
        if(root->val <=min || root->val >=max) return false;
        return ispos(root->left,min,root->val) && ispos(root->right,root->val,max);
    }
};