class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> t;
        for(char ch:target){
            t[ch]++;
        }
        unordered_map<char,int> str;
        for(char ch:s){
            str[ch]++;
        }
        int ans = INT_MAX;
        for(auto ch: t){
            ans = min(ans, str[ch.first]/ch.second);
        }
        return ans;
    }   
};
