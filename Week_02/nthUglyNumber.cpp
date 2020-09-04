//³óÊı
class Solution {
public:
    int nthUglyNumber(int n) {
        int a = 0, b = 0, c = 0;
        int dp[n + 1];
        dp[0] = 1;

        for(int i = 1; i < n; ++i) {
            int tmp1 = dp[a] * 2;
            int tmp2 = dp[b] * 3;
            int tmp3 = dp[c] * 5;

            dp[i] = min(tmp1, min(tmp2, tmp3));
            if(dp[i] == tmp1)
                ++a;
            if(dp[i] == tmp2)
                ++b;
            if(dp[i] == tmp3)
                ++c;
        }
        return dp[n - 1];
    }
};