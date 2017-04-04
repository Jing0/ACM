class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> vec;
        string s(10, '0');
        for (int i = 0; i < num; ++i) {
            s.at(i) = '1';
        }
        sort(s.begin(), s.end());
        do {
             int hour = binaryStr2Int(s.substr(0, 4));
             int min = binaryStr2Int(s.substr(4, 6));
             if (hour < 12 && min < 60) {
                 vec.push_back(int2time(hour, min));
             }
         } while (next_permutation(s.begin(), s.end()));
         return vec;
    }
private:
    int binaryStr2Int(string s) {
        int res = 0;
        for (int i = 0; i < s.length(); ++i) {
            res <<= 1;
            res |= (s.at(i) == '1' ? 1 : 0);
        }
        return res;
    }
    string int2time(int hour, int min) {
        return to_string(hour) + ":" + (min < 10 ? "0" : "") + to_string(min);
    }
};
