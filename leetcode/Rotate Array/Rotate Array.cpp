class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        queue<int> que;
        int size = nums.size();
         k = k % size;
        for (int i = 0; i < size; ++i) {
            if (i < size - k) {
                que.push(nums.at(i));
            }
            if (i < k) {
                nums.at(i) = nums.at((i + size - k));
            } else {
                nums.at(i) = que.front();
                que.pop();
            }
        }
    }
};
