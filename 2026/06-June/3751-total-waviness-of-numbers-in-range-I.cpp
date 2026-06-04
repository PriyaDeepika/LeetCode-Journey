// Approach 1
class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int start = max(num1, 100);
        if(start > num2){
            return 0;
        }
        int waviness = 0;
        for(int num=start; num<=num2; num++){
            string s = to_string(num);
            for(int i=1; i<s.size()-1; i++){
                int left = s[i-1] - '0';
                int curr = s[i] - '0';
                int right = s[i+1] - '0';

                if((curr > left && curr > right) || (curr < left && curr < right)){
                    waviness++;
                }  
            }
        }
        return waviness;
    }
};



// Approach 2
class Solution {
public:
    int wave[1000];
    Solution(){
        for(int x=0; x<1000; x++){
            int l = x/100;
            int m = (x / 10) % 10;
            int r = x % 10;

            wave[x] = (m > l && m > r) || (m < l && m < r);
        }
    }
    int getwaviness(int num){
        string s = to_string(num);
        int ans  = 0;
        for(int i=1; i < s.size() - 1; i++){
            int window = (s[i-1]-'0')*100 + (s[i]-'0')*10+ (s[i+1]-'0');
            ans += wave[window];
        }
        return ans;
    }
    int totalWaviness(int num1, int num2) {
        int waviness = 0;
        int start = max(num1, 100);
        if(start > num2){
            return 0;
        }
        for(int num = start; num <= num2; num++){
            waviness += getwaviness(num);
        }
        return waviness;
    }
};
