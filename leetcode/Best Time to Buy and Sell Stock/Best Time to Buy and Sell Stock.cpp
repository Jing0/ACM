class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if (!size) {
            return 0;
        }
        int min = prices.at(0);
        int max = prices.at(0);
        int mini = 0;
        int ans = 0;
        for (int i = 1; i < size; ++i) {
            int price = prices.at(i);
            if (price < min) {
                min = price;
                max = price;
                mini = i;
            } else if (i > mini && price > max) {
                max = price;
                if (max - min > ans) {
                    ans = max - min;
                }
            }
        }
        return ans;
    }
};
