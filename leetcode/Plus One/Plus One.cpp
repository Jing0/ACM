class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> v;
        int size = digits.size();
        int carry = 1;
        auto it = v.begin();
        for (int i = size - 1; i >=0; --i) {
            int d = digits.at(i);
            d += carry;
            if (d > 9) {
                d -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            it = v.insert(it, d);
        }
        if (carry == 1) {
            v.insert(it, 1);
        }
        return v;
    }
};
