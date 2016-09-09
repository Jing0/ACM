class Solution {
public:
    int numTrees(int n) {
        vector<int> vec;
        vec.push_back(1);
        vec.push_back(1);
        for (int i = 2; i <= n; ++i) {
            int t = 0;
            for (int j = 0; j < i / 2; ++j) {
                t += vec.at(j) * vec.at(i - 1 - j) * 2;
            }
            if (i % 2) {
                t += vec.at(i / 2) * vec.at(i / 2);
            }
            vec.push_back(t);
        }
        return vec.back();
    }
};
