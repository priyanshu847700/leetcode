class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0;
        string str;
        string ans;

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                count++;
                str+=s[i];
            }
            
            if(s[i]==')'){
                count--;
                str+=s[i];
            }

            if(count==0){
                str.pop_back();
                str.erase(0,1);

                ans+=str;
                str="";
            }
            
        }
        return ans;
    }
};