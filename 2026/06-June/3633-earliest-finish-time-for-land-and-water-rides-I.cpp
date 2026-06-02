class Solution {
    int minimum(vector<int>& start1, vector<int>& duration1, vector<int>& start2, vector<int>& duration2){
        int finish1 = INT_MAX;
        int n = start1.size(), m = start2.size();
        for(int i=0; i<n; i++){
            finish1 = min(finish1, start1[i]+duration1[i]);
        }
        int finish2 = INT_MAX;
        for(int j=0; j<m; j++){
            finish2 = min(finish2, max(finish1, start2[j])+ duration2[j]);
        }
        return finish2;
    }
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int plan_a = minimum(landStartTime, landDuration, waterStartTime, waterDuration);
        int plan_b = minimum(waterStartTime, waterDuration, landStartTime, landDuration);
        return min(plan_a, plan_b);
    }
};
