#include <vector>
#include <algorithm>

using namespace std;

const int kMinInt = 0x80000000;

// Inefficient way with complexity O(2^n)
int CutRodRecursive(vector<int> p, int n) {
    if (n == 0) return 0;
    int q = kMinInt;
    for (int i = 0; i <= n; ++i) {
        q = max(q, p[i] + CutRodRecursive(p, n - 1));
    }
    return q;
}

int CutRodTopBottom(vector<int>& p, int n) {
    vector<int> memo(n + 1, -1);
    return CutRodMemoized(p, n, memo);
}

int CutRodMemoized(vector<int>& p, int n, vector<int>& memo) {
    if (memo[n] > 0) return memo[n];
    if (!n) return 0;
    int q = kMinInt;
    for (int i = 0; i <= n; ++i) {
        q = max(q, p[i] + CutRodMemoized(p, n - 1, memo));
    }
    memo[n] = q;
    return q;
}

int CutRodBottomUp(vector<int>& p, int n) {
    vector<int> dp(n + 1, 0);
    for (int j = 1; j <= n; ++j) {
        int q = kMinInt;
        for (int i = 1; i <= j; ++i) {
            q = max(q, p[i] + dp[j - i]);
        }
        dp[j] = q;
    }
    return dp[n];
}