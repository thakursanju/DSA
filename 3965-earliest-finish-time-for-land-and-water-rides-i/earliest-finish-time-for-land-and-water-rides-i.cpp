class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landDuration.size();
        int m=waterDuration.size();
        long long x=LLONG_MAX;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // land start
                long long ans=landStartTime[i]+landDuration[i];
                long long ans1=max(ans,(long long)waterStartTime[j])+waterDuration[j];
                // water 
                long long ans2=waterStartTime[j]+waterDuration[j];
                long long ans3=max(ans2,(long long)landStartTime[i])+landDuration[i];
                x=min(x,min(ans1,ans3));
            }
        }
        return (int)x;
        
    }
};