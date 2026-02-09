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
    vector<int> nodes;

    // Step 1: Store BST in sorted order
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        nodes.push_back(root->val);
        inorder(root->right);
    }

    // Step 2: Build balanced BST
    TreeNode* build(int l, int r){
        if(l > r) return NULL;

        int mid = (l + r) / 2;
        TreeNode* root = new TreeNode(nodes[mid]);

        root->left = build(l, mid - 1);
        root->right = build(mid + 1, r);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return build(0, nodes.size() - 1);
    }
};
