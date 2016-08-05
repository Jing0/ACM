class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            if (nums.at(i) == val) {
                count++;
            } else {
                nums.at(i - count) = nums.at(i);
            }
        }
        return size - count;
    }
};
