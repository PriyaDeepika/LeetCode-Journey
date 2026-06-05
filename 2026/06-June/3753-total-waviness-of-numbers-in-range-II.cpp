class Solution {
public:
    vector<int> wavepatterns;
    Solution(){
        for(int x = 0; x<1000; x++){
            int left = x / 100;
            int middle = (x / 10) % 10;
            int right = x%10;
            bool ispeak = (middle > right) && (middle > left);
            bool isvalley = (middle < right) && (middle < left);
            if(ispeak || isvalley){
                wavepatterns.push_back(x);
            }
        }
    }
    long long totalWaviness(long long num1, long long num2) {
        return countwavinessupto(num2) - countwavinessupto(num1-1);
    }

private:
    long long countwavinessupto(long long num){
        if(num < 100) return 0;

        long long total =0;
        for(int pattern: wavepatterns){
            total += countoccurrences(num, pattern);
        }
        return total;
    }

    long long countoccurrences(long long num, int pattern){
        bool patternstartswithzero = (pattern < 100);
        long long totalCount = 0;
        long long mult = 1;
        while(mult*100 <= num){
            long long digitsLeftofWindow = num / (mult * 1000);
            long long currWindow = (num / mult) % 1000;
            long long digitsRightofWindow = num % mult;

            long long freeCount = 0;
            long long tightCount = 0;

            if(currWindow > pattern){
                freeCount = digitsLeftofWindow - patternstartswithzero + 1;
                tightCount = 0;
            }    
            else if(currWindow == pattern){
                freeCount = max(0LL, digitsLeftofWindow - patternstartswithzero);
                tightCount = digitsRightofWindow + 1;
            } else{
                freeCount = max(0LL, digitsLeftofWindow - patternstartswithzero);
                tightCount = 0;
            }
            totalCount += freeCount*mult + tightCount;
            mult *= 10;      
        }
        return totalCount;
    }
};
