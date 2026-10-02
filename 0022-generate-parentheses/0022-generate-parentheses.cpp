class Solution {
public:
    void validparenthesis(vector<string> &ans,string currstr,int n,int open,int close){
        if(currstr.size()==2*n){
            ans.push_back(currstr);
        }

        if(open < n){
            currstr.push_back('(');
            validparenthesis(ans,currstr,n,open+1,close);
            currstr.pop_back();
        }
        if(open > close){
            currstr.push_back(')');
            validparenthesis(ans,currstr,n,open,close+1);
            currstr.pop_back();
        }
       
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string currstr;
        int open;
        int close;

        validparenthesis(ans,currstr,n,0,0);

        return ans;

    }
};