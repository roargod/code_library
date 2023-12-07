#define _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> heap;
        double sum = 0;
        for (auto& e : nums)
        {
            heap.push(e);
            sum += e;
        }
        sum /= 2.0;
        int ret = 0;
        while (sum > 0)
        {
            double tmp = heap.top() / 2.0;
            heap.pop();
            sum -= tmp;
            ret++;
            heap.push(tmp);
        }
        return ret;
    }
};