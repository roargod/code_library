#define _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if (bills[0] != 5) return false;
        unordered_map<int, int> hash;
        hash[5] = 0;
        hash[10] = 0;
        hash[20] = 0;
        for (int i = 0; i < bills.size(); i++)
        {
            if (bills[i] == 5) hash[5]++;
            else if (bills[i] == 10)
            {
                if (hash[5] < 1) return false;
                hash[10]++;
                //ÕÒÁã
                hash[5]--;
            }
            else
            {
                //20
                //Ì°ÐÄ
                if (hash[10])
                {
                    if (hash[5] < 1) return false;
                    //ÓÐ10¿éÇ®
                    hash[10]--;
                    hash[5]--;
                }
                else
                {
                    if (hash[5] < 3) return false;
                    hash[5] -= 3;
                }
            }
            if (hash[5] < 0 || hash[10] < 0) return false;
        }
        return true;
    }
};