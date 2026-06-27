class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(auto &num: nums){
            freq[num]++;
        }
        int ans = (freq[1]-1)|1;
        freq.erase(1);
        for(auto &f: freq){
            int n = 0;
            int x = f.first;
            int s = sqrt(x);
            if(s*s == x && freq.count(s) && freq[s]>1){
                continue;
            }
            while(x<31623 && freq.count(x) && freq[x]>1){
                n+=2;
                x*=x;
            }
            ans = fmax(ans, n+((freq.count(x)<<1)-1));
        }
        return ans;
    }
};
