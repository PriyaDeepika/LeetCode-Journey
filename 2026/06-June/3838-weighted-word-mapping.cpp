class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result = "";
        
        for(string word: words){
            int count = 0;
            for(char ch: word){
                count += weights[ch-'a']; 
            }
            result += char('z'-count%26);
        }
        return result;
    }
};
