#define _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    double myPow(double x, int n) {
        //n大于0即为pow(x, n)，n小于0，即为 1.0/pow(x, n)
        if (n < 0) return 1.0 / pow(x, n);
        else return pow(x, n);
    }
    double pow(double x, long long n)
    {
        if (n == 0) return 1;
        //子问题：计算一半的次方
        double ret = pow(x, n / 2);
        //n为奇数，多乘一个x
        return n % 2 == 0 ? ret * ret : ret * ret * x;
    }
};