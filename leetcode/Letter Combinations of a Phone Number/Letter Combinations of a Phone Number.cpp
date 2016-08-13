class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int length = digits.length();
        const string map[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for (int i = 0; i < length; ++i) {
            ans = permutation(ans, map[digits.at(i) - '0']);
        }
        return ans;
        
    }
private:
    vector<string> permutation(vector<string> vec, string s) {
        vector<string> ans;
        int size = vec.size();
        int length = s.length();
        if (!size) {
            for (int i = 0; i < length; ++i) {
                ans.push_back(s.substr(i, 1));
            }
            return ans;
        }
        for (int i = 0; i < size; ++i) {
            string t = vec.at(i);
            for (int j = 0; j < length; ++j) {
                ans.push_back(t + s.substr(j, 1));
            }
        }
        return ans;
    }
};
