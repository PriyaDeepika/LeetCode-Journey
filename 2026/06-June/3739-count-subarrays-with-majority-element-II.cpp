class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int pref = n;
        vector<int> freq(2*n + 1);
        freq[n] = 1;
        long long x = 0, ans = 0;
        for(int num: nums){
            if(num == target){
                x += freq[pref++];
            }else{
                x -= freq[--pref];
            }
            ++freq[pref];
            ans+=x;
        }
        return ans;
    }
};
