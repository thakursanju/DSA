class Solution {
public:
    long long MOD = 1e9 + 7;

    long long power(long long a, long long b) {
        long long ans = 1;

        while (b) {
            if (b & 1)
                ans = ans * a % MOD;

            a = a * a % MOD;
            b /= 2;
        }

        return ans;
    }

    int numberOfSets(int n, int k) {
        int N = n + k - 1;
        int R = 2 * k;

        // factorial
        vector<long long> fact(N + 1, 1);

        for (int i = 1; i <= N; i++)
            fact[i] = fact[i - 1] * i % MOD;

        // C(N,R) = N! / (R! * (N-R)!)
        long long ans = fact[N];

        ans = ans * power(fact[R], MOD - 2) % MOD;
        ans = ans * power(fact[N - R], MOD - 2) % MOD;

        return ans;
    }
};