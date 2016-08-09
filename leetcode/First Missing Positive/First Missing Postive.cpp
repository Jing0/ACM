class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> s;
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            int num = nums.at(i);
            if (num > 0 && !s.count(num)) {
                s.insert(num);
            }
        }
        int size2 = s.size();
        for (int i = 1; i <= size2; ++i) {
            if (!s.count(i)) {
                return i;
            }
        }
        return size2 + 1;
    }
};
