class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int map[26] = {0}, count = 0;
        int len1 = ransomNote.length();
        if (!len1) {
            return true;
        }
        for (int i = 0; i < len1; ++i) {
            map[ransomNote.at(i) - 'a']++;
            count++;
        }
        int len2 = magazine.length();
        for (int i = 0; i < len2; ++i) {
            if (map[magazine.at(i) - 'a'] > 0) {
                map[magazine.at(i) - 'a']--;
                count--;
            }
            if (!count) {
                return true;
            }
        }
        return false;
    }
};
