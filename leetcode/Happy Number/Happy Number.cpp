class Solution {
public:
	bool isHappy(int n) {
		if (n == 1) {
			return true;
		}
		set<int> s;
		s.insert(n);
		int r = n;
		while (r != 1) {
			int tmp = r;
			r = 0;
			while (tmp) {
				r += (int)pow(tmp % 10, 2);
				tmp /= 10;
			}
			if (s.count(r)) {
				break;
			} else if (r == 1) {
				return true;
			}
			s.insert(r);
		}
		return false;
	}
};
