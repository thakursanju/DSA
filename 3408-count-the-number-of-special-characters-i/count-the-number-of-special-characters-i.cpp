class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size();
        vector<int>freq(26,0);
        vector<int> freq1(26,0);
        for( char c: word){
            if(c>='a'&&c<='z'){
            freq[c-'a']++;
            }
            if(c>='A'&&c<='Z'){
                freq1[c-'A']++;
            }
        }
        int c=0;
        for(int i=0;i<26;i++){
            if(freq[i]>0&&freq1[i]>0){
                c++;
            }
        }
        return c;
   
    }
};