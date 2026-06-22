class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> freq;
        for(char ch:text){
            freq[ch]++;
        }
        int no = min({freq['b'], freq['a'], freq['l']/2, freq['o']/2, freq['n']});
        return no;
    }
};
