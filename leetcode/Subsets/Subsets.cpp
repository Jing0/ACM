class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int size1 = nums.size();
        vector<int> tmp;
        ans.push_back(tmp);
        for (int i = 0; i < size1; ++i) {
            vector<int> tmp;
            tmp.push_back(nums.at(i));
            ans.push_back(tmp);
            int size2 = ans.size();
            for (int j = 1; j < size2 - 1; ++j) {
                tmp = ans.at(j);
                tmp.push_back(nums.at(i));
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};
