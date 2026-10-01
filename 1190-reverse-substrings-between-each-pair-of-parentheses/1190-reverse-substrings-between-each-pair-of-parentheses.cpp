class Solution {
public:
    string reverseParentheses(string s) {
        vector<int> l;
        string ans;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                l.push_back(ans.size());
            }
            else if(s[i]==')'){
                reverse(ans.begin()+l.back(),ans.end());
                l.pop_back();
            }
            else{
                ans+=s[i];
            }
        }
        return ans;
    }
};