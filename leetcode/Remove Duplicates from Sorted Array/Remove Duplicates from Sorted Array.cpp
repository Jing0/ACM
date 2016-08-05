class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        int size = nums.size();
        int dupcount = 0;
        for (int i = 0; i < size; ++i) {
            if (s.count(nums.at(i))) {
               dupcount++; 
            } else {
                s.insert(nums.at(i));
                nums.at(i - dupcount) = nums.at(i);
            }
        }
        return s.size();
    }
};
