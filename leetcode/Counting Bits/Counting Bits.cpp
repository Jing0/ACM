class Solution {
	public:
		vector<int> countBits(int num) {
			vector<int> vec;
			vec.push_back(0);
			int m = 1;
			int j;
			for (int i = 1; i <= num; ++i) {
				if (i == m) {
					m<<=1;
					j = 0;
				} else {
					j++;
				}
				vec.push_back(1 + vec.at(j));
			}
			return vec;
		}
};
