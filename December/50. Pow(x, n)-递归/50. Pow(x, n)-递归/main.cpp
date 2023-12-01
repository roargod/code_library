#define _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    double myPow(double x, int n) {
        //n����0��Ϊpow(x, n)��nС��0����Ϊ 1.0/pow(x, n)
        if (n < 0) return 1.0 / pow(x, n);
        else return pow(x, n);
    }
    double pow(double x, long long n)
    {
        if (n == 0) return 1;
        //�����⣺����һ��Ĵη�
        double ret = pow(x, n / 2);
        //nΪ���������һ��x
        return n % 2 == 0 ? ret * ret : ret * ret * x;
    }
};