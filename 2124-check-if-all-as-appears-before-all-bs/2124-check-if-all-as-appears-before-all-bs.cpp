class Solution {
public:
    bool checkString(string s) {
        string n=s;

        sort(s.begin(),s.end());

        if(n==s){
            return true;
        }
        return false;
    }
};