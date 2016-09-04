class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> mp;
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            int num = nums.at(i);
            mp[num] = 1;
        }
        int ans = 1;
        for (int i = 0; i < size; ++i) {
            int num = nums.at(i);
            if (mp[num] == 1) {
                int count1 = 1;
                while (mp[num - count1] == 1) {
                    mp[num - count1] = 0;
                    count1++;
                }
                count1--;
                int count2 = 1;
                while (mp[num + count2] == 1) {
                    mp[num + count2] = 0;
                    count2++;
                }
                count2--;
                mp[num] = 0;
                int count = count1 + count2 + 1;
                if (count > ans) {
                    ans = count;
                }
            }
        }
        return ans;
    }
};
