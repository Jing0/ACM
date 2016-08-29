class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        for (int i = size - 1; i > 0; --i) {
		    if (nums[i] > nums[i - 1]) {
			    for (int j = size - 1; j > i - 1; --j) {
				    if (nums[j] > nums[i - 1]) {
					    swap(nums[i - 1], nums[j]);
					    reverse(nums, i, size - 1);
					    return;
				    }
			    }
		    }
	    }
	    reverse(nums, 0, size - 1);
    }
private:
    void reverse(vector<int>& nums, int begin, int end) {
	    for (int i = begin; i < (begin + end) / 2 + 1; ++i) {
		    swap(nums[i], nums[end + begin - i]);
	    }
    }
};
