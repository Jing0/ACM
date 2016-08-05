class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1, s2;
        vector<int> vec;
        for (int n:nums1) {
            s1.insert(n);
        }
        for (int n:nums2) {
            if (s1.count(n)) {
                s2.insert(n);
            }
        }
        for (int n:s2) {
            vec.push_back(n);
        }
        return vec;
    }
};
