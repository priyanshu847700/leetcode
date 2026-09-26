class Solution {
public:
    vector<string> ans;
    bool isValid(string s){
        int count=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                count++;
            }
            else{
                count--;
            }

            if(count<0){
                return false;
            }
        }
        
        return count==0;
    }

    void helper(string &curr,int n){
        if(curr.length()== 2*n){
            if(isValid(curr)){
                ans.push_back(curr);
            }
            return;
        }

        curr.push_back('(');
        helper(curr,n);
        curr.pop_back();

        curr.push_back(')');
        helper(curr,n);
        curr.pop_back();

    }

    vector<string> generateParenthesis(int n) {

        string curr;
        helper(curr,n);

        return ans;
    }
};