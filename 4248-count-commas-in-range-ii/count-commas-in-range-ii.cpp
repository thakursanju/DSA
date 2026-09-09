class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

        long long p = 1000;
        long long commas = 1;

        while (p <= n) {
            long long next = p * 1000;

            long long cnt = min(n, next - 1) - p + 1;

            ans += cnt * commas;

            p = next;
            commas++;
        }

        return ans;
    }
};