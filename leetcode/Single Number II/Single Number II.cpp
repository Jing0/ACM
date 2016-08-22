class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0;//记录只出现过1次的bits
        int twos = 0;//记录只出现过2次的bits
        int threes;
        int size = nums.size();
        for(int i = 0; i < size; i++){
            int t = nums.at(i);
            twos |= ones&t;//要在更新ones前面更新twos
            ones ^= t;
            threes = ones&twos;//ones和twos中都为1即出现了3次
            ones &= ~threes;//抹去出现了3次的bits
            twos &= ~threes;
        }
        return ones; 
    }
};
