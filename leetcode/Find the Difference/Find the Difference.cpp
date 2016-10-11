class Solution {
public:
    char findTheDifference(string s, string t) {
        long letterSum = 0;
        int lens = s.length(), lent = t.length();
        for (int i = 0; i < lens; ++i) {
            letterSum += s.at(i);
        }
        for (int i = 0; i < lent; ++i) {
            letterSum -= t.at(i);
        }
        return (char)abs(letterSum);
    }
};
