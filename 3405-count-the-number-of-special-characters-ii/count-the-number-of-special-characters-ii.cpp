class Solution {
public:
    int numberOfSpecialChars(string word) { int n=word.size();
    vector<int> freq(26,-1);
    vector<int> freq1(26,-1);
    for(int i=0;i<n;i++){
        char c=word[i];
        if(c>='a'&&c<='z'){
            freq[c-'a']=i;
        }
        else{
            if(freq1[c-'A']==-1){
            freq1[c-'A']=i;
            }
        }
    }
    int c=0;
    for(int i=0;i<26;i++){
        if(freq[i]!=-1&&freq1[i]!=-1&&freq[i]<freq1[i]){
            c++;
        }
    }
    return c;
        
    }
};