//https://leetcode.com/problems/gray-code

vector<int> GrayCode(int n) {
    vector<int> res;
    int N = 1 << n;
    for (int i = 0; i < N; i++) res.push_back(i ^ i >> 1);
    return res;
}