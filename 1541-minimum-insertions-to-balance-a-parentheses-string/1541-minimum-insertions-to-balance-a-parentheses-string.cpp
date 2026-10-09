class Solution {
public:
    int minInsertions(string s) {
        int ans=0;
        int count=0;
        int i=0;

        while(i<s.size()){
            if(s[i]=='('){
                count++;
                i++;
            }
            else{
                if(count>0){   //for checking if it has '('
                    count--;
                }
                else{
                    ans++;
                }

                if(s[i+1]==')' && s.size()>i){       //for checking 2nd ')' close bracket 
                    i+=2;
                }
                else{
                    ans++;
                    i++;
                }
            }
        }
        return ans+ (2*count);
    }
};