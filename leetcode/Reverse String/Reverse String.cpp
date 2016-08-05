class Solution {
public:
    string reverseString(string s) {
        int len = s.length();
        for (int i = 0; i < len/2; ++i) {
            swap(s.at(i), s.at(len - 1 - i));
        }
        return s;
        
    }
};
