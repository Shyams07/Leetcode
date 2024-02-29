class Solution {
public:
    bool dfs(TreeNode* root, vector<int>& val, int depth) {
        if (!root)
            return 1;
        if (depth + 1 > val.size()) {
            if ((depth & 1) ^ (root->val & 1))
                val.push_back(root->val);
            else
                return 0;
        } else {
            if (depth & 1) {
                if (!(root->val & 1) && val[depth] > root->val)
                    val[depth] = root->val;
                else
                    return 0;
            } else {
                if ((root->val & 1) && val[depth] < root->val)
                    val[depth] = root->val;
                else
                    return 0;
            }
        }
        return dfs(root->left, val, depth + 1) &&
               dfs(root->right, val, depth + 1);
    }
    bool isEvenOddTree(TreeNode* root) {
        vector<int> val;
        int depth = 0;
        return dfs(root, val, depth);
    }
};