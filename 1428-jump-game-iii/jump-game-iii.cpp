class Solution {
bool t(int start,vector<int>& arr,int n){
    if(start<0||start>=n){
        return 0;
    }
    if(arr[start]<0){
        return 0;
    }
    if(arr[start]==0){
        return 1;
    }
    int jump=arr[start];
    arr[start]=-arr[start];
    bool diff=t(start-jump,arr,n);
    bool ad=t(start+jump,arr,n);
    arr[start]=jump;
    return diff||ad;

}
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        return t(start,arr,n);
    }
};