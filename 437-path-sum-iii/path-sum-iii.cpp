class Solution {
public:

    unordered_map<long long,int> mp;
    int ans=0;

    void dfs(TreeNode* root,long long curr,int target){

        if(root==NULL)
            return;

        curr+=root->val;

        ans+=mp[curr-target];

        mp[curr]++;

        dfs(root->left,curr,target);
        dfs(root->right,curr,target);

        mp[curr]--;
    }

    int pathSum(TreeNode* root, int targetSum) {

        mp[0]=1;

        dfs(root,0,targetSum);

        return ans;
    }
};