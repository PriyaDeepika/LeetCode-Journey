class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while(n!= 1){
            if(seen.find(n)!=seen.end()){
                return false;
            }
            seen.insert(n);
            int happy = 0;
            while(n > 0){
                int digit = n % 10;
                happy += digit* digit;
                n /= 10;
            }
            n = happy;
        }
        return true;
    }
};
