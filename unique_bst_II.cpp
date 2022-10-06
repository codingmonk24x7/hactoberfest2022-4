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
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<vector<TreeNode*>>> ans(n+1, vector<vector<TreeNode*>>(n+1));
        
        for(int dif = 0; dif < n; dif++) {
            for(int i = 1; i <= n-dif; i++) {
                if(i == i+dif) {
                    TreeNode* node = new TreeNode(i);
                    ans[i][i+dif].push_back(node);
                } else {
                    for(int k = i; k <= i+dif; k++) {
                        if(i <= k-1 && k+1 <= i+dif) {
                            for(auto X: ans[i][k-1]) {
                                for(auto Y: ans[k+1][i+dif]) {
                                    TreeNode* node = new TreeNode(k);
                                    node->left = X;
                                    node->right = Y;
                                    ans[i][i+dif].push_back(node);
                                }
                            }
                        } else if(i > k-1 && k+1 <= i+dif) {
                            for(auto Y: ans[k+1][i+dif]) {
                                TreeNode* node = new TreeNode(k);
                                node->left = NULL;
                                node->right = Y;
                                ans[i][i+dif].push_back(node);
                            }
                        } else if(i <= k-1 && k+1 > i+dif) {
                            for(auto X: ans[i][k-1]) {
                                TreeNode* node = new TreeNode(k);
                                node->left = X;
                                node->right = NULL;
                                ans[i][i+dif].push_back(node);
                            }
                        }
                    }
                }
            }
        }
        
        return ans[1][n];
    }
};
