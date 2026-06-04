class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        long long ans = LLONG_MAX;

        auto calc = [&](vector<int>& firstStart,
                        vector<int>& firstDur,
                        vector<int>& secondStart,
                        vector<int>& secondDur) {

            int m = secondStart.size();

            vector<pair<int,int>> rides;
            for(int i = 0; i < m; i++) {
                rides.push_back({secondStart[i], secondDur[i]});
            }

            sort(rides.begin(), rides.end());

            vector<int> start(m);
            vector<long long> prefDur(m);
            vector<long long> suffVal(m);

            for(int i = 0; i < m; i++) {
                start[i] = rides[i].first;

                if(i == 0)
                    prefDur[i] = rides[i].second;
                else
                    prefDur[i] = min(prefDur[i - 1],
                                     (long long)rides[i].second);
            }

            for(int i = m - 1; i >= 0; i--) {
                long long cur =
                    (long long)rides[i].first + rides[i].second;

                if(i == m - 1)
                    suffVal[i] = cur;
                else
                    suffVal[i] = min(suffVal[i + 1], cur);
            }

            long long best = LLONG_MAX;

            for(int i = 0; i < (int)firstStart.size(); i++) {

                long long finish =
                    (long long)firstStart[i] + firstDur[i];

                int idx =
                    upper_bound(start.begin(), start.end(), finish)
                    - start.begin();

                if(idx > 0) {
                    best = min(best,
                               finish + prefDur[idx - 1]);
                }

                if(idx < m) {
                    best = min(best, suffVal[idx]);
                }
            }

            return best;
        };

        ans = min(ans,
                  calc(landStartTime, landDuration,
                       waterStartTime, waterDuration));

        ans = min(ans,
                  calc(waterStartTime, waterDuration,
                       landStartTime, landDuration));

        return (int)ans;
    }
};