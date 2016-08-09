class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int *arr = (int *)malloc(sizeof(int) * size);
        int ans, sum;
        ans = sum = nums.at(0);
        
        for (int i = 0; i < size; ++i) {
            int tmp = nums.at(i);
            if (i) {
                tmp += arr[i - 1];
            }
            if (tmp > ans) {
                ans = tmp;
            }
            arr[i] = tmp;
        }
        
        for (int i = 1; i < size; ++i) {
            for (int j = i; j < size; ++j) {
                int tmp = arr[j] - sum;
                if (tmp > ans) {
                    ans = tmp;
                }
            }
            sum += nums.at(i);
        }
        return ans;
    }
};
