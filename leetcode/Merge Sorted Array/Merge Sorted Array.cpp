class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3;
        for (int i = 0; i < m; ++i) {
            nums3.push_back(nums1.at(i));
        }
        nums1.clear();
        int i2 = 0, i3 = 0;
        while (i2 < n && i3 < m) {
            if (nums2.at(i2) < nums3.at(i3)) {
                nums1.push_back(nums2.at(i2++));
            } else {
                nums1.push_back(nums3.at(i3++));
            }
        }
        while (i2 < n) {
            nums1.push_back(nums2.at(i2++));
        }
        while (i3 < m) {
            nums1.push_back(nums3.at(i3++));
        }
    }
};
