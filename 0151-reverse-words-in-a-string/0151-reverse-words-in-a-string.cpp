class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;

        string result;

        while(ss >> word){
            result= word+" "+result;
        }

        result.pop_back();
        return result;
    }
};