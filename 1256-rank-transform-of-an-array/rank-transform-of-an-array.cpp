class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int> fre(n,0);
        for(int i=0;i<n;i++){
            fre[i]=arr[i];
        }
        map<int,int> ans;
        sort(fre.begin(),fre.end());
        int rank=1;
        for( int x: fre){
            if(ans.find(x)==ans.end()){
                ans[x]=rank++;
            }
        }
        for(int i=0;i<n;i++){
            arr[i]=ans[arr[i]];
        }
        return arr;
        
    }
};