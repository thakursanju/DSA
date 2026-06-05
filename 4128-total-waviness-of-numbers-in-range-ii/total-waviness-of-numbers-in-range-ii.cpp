class Solution {
public:
    long long dp[20][11][11][2][2];
    long long cnt[20][11][11][2][2];
    string s;

    pair<long long,long long> dfs(int pos, int a, int b,
                                  bool started, bool tight) {

        if(pos == s.size()) {
            return {1, 0};
        }

        if(dp[pos][a][b][started][tight] != -1)
            return {
                cnt[pos][a][b][started][tight],
                dp[pos][a][b][started][tight]
            };

        int lim = tight ? s[pos]-'0' : 9;

        long long ways = 0;
        long long wav = 0;

        for(int d=0; d<=lim; d++) {

            bool ntight = tight && (d==lim);

            if(!started && d==0) {
                auto res = dfs(pos+1,10,10,false,ntight);
                ways += res.first;
                wav += res.second;
            }
            else {

                int add = 0;

                if(started && a!=10 && b!=10) {
                    if((a < b && b > d) ||
                       (a > b && b < d))
                        add = 1;
                }

                int na, nb;

                if(!started) {
                    na = 10;
                    nb = d;
                } else {
                    na = b;
                    nb = d;
                }

                auto res = dfs(pos+1,na,nb,true,ntight);

                ways += res.first;
                wav += res.second + 1LL*add*res.first;
            }
        }

        cnt[pos][a][b][started][tight] = ways;
        dp[pos][a][b][started][tight] = wav;

        return {ways,wav};
    }

    long long solve(long long x) {
        if(x <= 0) return 0;

        s = to_string(x);

        memset(dp,-1,sizeof(dp));
        memset(cnt,-1,sizeof(cnt));

        return dfs(0,10,10,false,true).second;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1-1);
    }
};