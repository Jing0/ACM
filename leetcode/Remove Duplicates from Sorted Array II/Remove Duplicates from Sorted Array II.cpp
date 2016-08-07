class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s1, s2;
        int size = nums.size();
        int dupcount = 0;
        for (int i = 0; i < size; ++i) {
            if (s1.count(nums.at(i))) {
               if (s2.count(nums.at(i))) {
                   dupcount++;
               } else {
                   s2.insert(nums.at(i));
                   nums.at(i - dupcount) = nums.at(i);
               }
            } else {
                s1.insert(nums.at(i));
                nums.at(i - dupcount) = nums.at(i);
            }
        }
        return s1.size() + s2.size();
    }
};
