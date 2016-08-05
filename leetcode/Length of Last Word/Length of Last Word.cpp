class Solution {
public:
	int lengthOfLastWord(string s) {
		int len = s.length();
		while (len > 0 && s.at(len - 1) == ' ') {
		    len--;
		}
		int i;
		for (i = len - 1; i >= 0; --i) {
			if (s.at(i) == ' ' || s.at(i) == '\n' || s.at(i) == '\t' || s.at(i) == '\f') {
				break;
			}
		}
		return len - 1 - i;
	}
};
