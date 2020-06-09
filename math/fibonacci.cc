/**
 * Calculating Fibonacci numbers
 */

#include <vector>

using namespace std;

/**
 * Inefficient algorithm
 * 
 * Time complexity: O(1.6 ^ N)
 * Space complexity: O(1.6 ^ N) - all cause of recursize call stack
 */
int fib(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}

/**
 * More efficient algorithm
 * 
 * Time complexity: O(n)
 * Space complexity: O(n)
 */
int fibMemo(int n) {
    vector<int> memo {0, 1};
    return fibMemoInternal(n, memo);
}

int fibMemoInternal(int n, vector<int>& memo) {
    if (n < 0) return 0;
    if (memo.size() <= n) {
        memo.push_back(fibMemoInternal(n - 1, memo) + fibMemoInternal(n - 2, memo));
    }

    return memo[n];
}

int main() {
    // TODO: add tests here
}