class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int single_digit = 0, double_digit = 0;
        for(int num: nums){
            if(num <=9){
                single_digit += num;
            }else{
                double_digit += num;
            }
        }
        return single_digit != double_digit;
    }
};
