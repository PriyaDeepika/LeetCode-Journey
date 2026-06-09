class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long min = *min_element(nums.begin(), nums.end());
        long long max = *max_element(nums.begin(), nums.end());
        return 1LL*k*(max-min);
    }
};
