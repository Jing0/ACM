class NumArray {
public:
    NumArray(vector<int> &nums) {
        int size = nums.size();
        int sum = 0;
        sums.push_back(sum);
        for (int i = 0; i < size; ++i) {
            sum += nums.at(i);
            sums.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        return sums.at(j + 1) - sums.at(i);
    }
private:
    vector<int> sums;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
