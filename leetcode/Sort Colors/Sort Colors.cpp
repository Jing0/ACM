class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red, white, blue;
        red = white = blue = 0;
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            switch(nums.at(i)) {
                case 0: red++; break;
                case 1: white++; break;
                case 2: blue++; break;
            }
        }
        for (int i = 0; i < size; ++i) {
            if (red) {
                nums.at(i) = 0;
                red--;
            } else if (white) {
                nums.at(i) = 1;
                white--;
            } else {
                nums.at(i) = 2;
                blue--;
            }
        }
    }
};
