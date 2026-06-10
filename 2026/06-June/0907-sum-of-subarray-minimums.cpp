class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9+7;
        vector<int> pse(n), nse(n);
        stack<int> pse_st, nse_st;

        for(int i=0; i<n; i++){
            while(!pse_st.empty() && arr[pse_st.top()] > arr[i]){
                pse_st.pop();
            }
            pse[i] = pse_st.empty()?-1:pse_st.top();
            pse_st.push(i);
        }

        for(int i = n-1; i>=0; i--){
            while(!nse_st.empty() && arr[nse_st.top()]>= arr[i]){
                nse_st.pop();
            }
            nse[i] = nse_st.empty() ? n: nse_st.top();
            nse_st.push(i);
        }

        long long ans = 0;
        for(int i=0; i<n; i++){
            long long left = i-pse[i];
            long long right = nse[i]-i;
            ans = (ans + (long long)arr[i]*left*right)%mod;
        }
        return ans;
    }
};
