class Solution {
public:
    int maxDepth(string s) {
        int max_count=INT_MIN;
        int count=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                count++;
                max_count=max(count,max_count);
            }
            else if(s[i]==')'){
                count--;
            }

        }
        if(max_count==INT_MIN){
            return 0;
        }
        return max_count;
    }
};