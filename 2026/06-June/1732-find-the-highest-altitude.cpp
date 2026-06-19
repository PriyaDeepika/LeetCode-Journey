class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int net_gain = 0, high = 0;
        for(int i=0; i<gain.size(); i++){
            net_gain += gain[i];
            high = max(net_gain, high);
        }
        return high;
    }
};
