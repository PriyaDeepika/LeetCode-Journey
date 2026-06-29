class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int no = 0;
        for(string str: patterns){
            if(word.find(str) != string::npos) no++;
        }
        return no;
    }
};
