class Solution {
    double pow(double a, int n) {
        if (!n) return 1;
        double x = pow(a, n >> 1);
        if (n & 1) return a * x * x;
        return x * x;
    }
    
public:
    double myPow(double x, int n) {
        if (!n) return 1;
        double num = pow(x, abs(n / 2));
        // cout << "pow(" << x << ", " << n << "); num = " << num << endl;
        
        if (n > 0) {
            if (n & 1) return x * num * num;
            return num * num;
        } else if (n & 1) return 1 / (x * num * num);
        
        return 1 / (num * num);
    }
};