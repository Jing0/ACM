class Solution {
public:
    string intToRoman(int num) {
        string ans;
        int len = 13;
        const int na[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        const string sa[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        for (int i = 0; num && i < len; ++i) {
            while (num >= na[i]) {
                ans += sa[i];
                num -= na[i];
            }
        }
        return ans;
    }
};

