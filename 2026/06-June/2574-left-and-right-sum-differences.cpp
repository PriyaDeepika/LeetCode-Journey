class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int right = accumulate(nums.begin(), nums.end(), 0);
        int left = 0;
        vector<int> result;
        for(int i=0; i<nums.size(); i++){
            right -= nums[i];
            result.push_back(abs(left - right));
            left += nums[i];
        }
        
        return result;
    }
};
