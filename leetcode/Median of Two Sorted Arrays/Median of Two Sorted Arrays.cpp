class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans;
        int size1 = nums1.size();
        int size2 = nums2.size();
        bool odd = (size1 + size2) % 2 == 1;
        int i1 = 0, i2 = 0;
        int a, b;
        while ((i1 + i2) <= (size1 + size2) / 2 + 1) {
            if ((i1 + i2) == (size1 + size2) / 2 + 1) {
                break;
            }
            a = b;
            if (i1 < size1 && i2 < size2) {
                if (nums1.at(i1) < nums2.at(i2)) {
                    b = nums1.at(i1);
                    i1++;
                } else {
                    b = nums2.at(i2);
                    i2++;
                }
            } else if (i1 < size1) {
                b = nums1.at(i1);
                i1++;
            } else if (i2 < size2) {
                b = nums2.at(i2);
                i2++;
            }
        }
        if (odd) {
            ans = b;
        } else {
            ans  = (a + b) / 2.0;
        }
        return ans;
    }
};
