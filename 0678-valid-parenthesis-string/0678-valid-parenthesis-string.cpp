class Solution {
public:
    int t[101][101];
    bool solve(string s ,int count,int i){
        if(count < 0){
            return false;
        }

        if(i==s.size()){
            return count==0;
        }

        if(t[count][i] != -1){
            return t[count][i];
        }

        bool isValid=false;

        if(s[i]=='('){
            isValid |= solve(s,count+1,i+1);
        }
        else if(s[i]==')'){
            isValid |= solve(s,count-1,i+1);
        }
        else{ // * vala case [3 choices]
            isValid |= solve(s,count,i+1);
            isValid |= solve(s,count+1,i+1);

            if(count>0){
                isValid |= solve(s,count-1,i+1);
            }
        }

        return t[count][i] = isValid;
    }
    bool checkValidString(string s) {
        memset(t,-1,sizeof(t));
        return solve(s,0,0);
    }
};