class Solution {
public:
    Solution(vector<int> nums) {
        vec = nums;
        srand(42);
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return vec;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> shf;
		vector<int> tmp = vec;
		while (!tmp.empty()) {
			int i = rand() % tmp.size();
			shf.push_back(tmp.at(i));
			swap(tmp.at(i), tmp.back());
			tmp.pop_back();
		}
		return shf;
    }
private:
    vector<int> vec;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
