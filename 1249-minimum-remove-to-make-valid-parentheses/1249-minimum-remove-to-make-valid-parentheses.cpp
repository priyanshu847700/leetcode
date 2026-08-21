class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }
            if(s[i]==')' && st.empty()){
                s.erase(i,1);
                i--;
                continue;
            }
            if(s[i]==')' && !st.empty()){
                st.pop();
            }
        }
        while(!st.empty()){
            s.erase(st.top(),1);
            st.pop();
        }

        return s;
    }
};