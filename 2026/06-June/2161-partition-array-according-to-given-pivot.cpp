class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int less = 0, equal = 0;
        for(int num: nums){
            if(num < pivot){
                less++;
            }
            else if(num == pivot){
                equal++;
            }
        }
        int less1 = 0, equal1 = less;
        int greater1 = less+equal;
        vector<int> ans(nums.size());
        for(int x:nums){
            if(x < pivot){
                ans[less1++] = x;
            } else if(x > pivot){
                ans[greater1++] = x;
            } else{
                ans[equal1++] = x;
            }
        } 
        return ans;
    }
};
