#include <stdlib.h>
typedef struct TS {
    int v;
    int i;
} TS;
int cmp(const void *a, const void *b) {
    return (*(TS *)a).v - (*(TS *)b).v;
}
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        TS *a = (TS *)malloc(sizeof(TS) * size);
        for (int i = 0; i < size; ++i) {
            a[i].v = nums.at(i);
            a[i].i = i;
        }
        qsort(a, size, sizeof(TS), cmp);
        int i1, i2;
        for (int i = 0; i < size && a[i].v <= target / 2; ++i) {
            for (int j = i + 1; j < size; ++j) {
                int sum = a[i].v + a[j].v;
                if (sum == target) {
                    i1 = a[i].i;
                    i2 = a[j].i;
                    break;
                } else if (sum > target) {
                    break;
                }
            }
        }
        vector<int> v;
        
        if (i1 > i2) {
            swap(i1, i2);
            
        }
        v.push_back(i1);
        v.push_back(i2);
        return v;
    }

};
