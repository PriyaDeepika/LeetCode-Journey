class Solution {
public:
    char processStr(string s, long long k) {
        long long len = 0;

        for(char ch: s){
            if(ch >='a' && ch <='z'){
                len++;
            }
            else if(ch == '*'){
                len = max(len-1, 0LL);
            }
            else if(ch == '#'){
                len *= 2;
            }
            else if(ch == '%'){}
        }

        if(k>=len){
            return '.';
        }

        for(int i=s.size()-1; i>=0; i--){
            char ch = s[i];
            if(ch >= 'a' && ch<='z'){
                if(k == len-1){
                    return ch;
                }
                len--;
            }
            else if(ch == '*'){
                len++;
            }
            else if(ch == '#'){
                len/=2;
                if(k>=len){
                    k -=len;
                }
            }
            else if(ch == '%'){
                k = len-1-k;
            }
        }
        return '.';
    }
};
