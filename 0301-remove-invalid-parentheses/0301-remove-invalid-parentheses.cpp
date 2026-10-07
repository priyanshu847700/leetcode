class Solution {
public:
    void solve(string &s,string &str,set<string> &st,int count,int idx,int &maxlen){

        if(count<0){          //as we are taking include & exclude choice for every char  so -- 
            return;           //--if str= ')()' can never become valid string so dont explore it.
        }

        if(idx == s.size()){
            if(count==0){
                if(str.length()>maxlen){
                    maxlen=str.length();
                    st.clear();
                }

                if(str.length()==maxlen){
                    st.insert(str);
                }
            }
            return;
        }

        str.push_back(s[idx]);
        
        if(s[idx]=='(') {
            solve(s,str,st,count+1,idx+1,maxlen);
        }
        else if(s[idx]==')'){
            solve(s,str,st,count-1,idx+1,maxlen);
        }
        else{
            solve(s,str,st,count,idx+1,maxlen);
        }
        
        str.pop_back();
        solve(s,str,st,count,idx+1,maxlen);

    }
    
    vector<string> removeInvalidParentheses(string s) {

        string str;
        set<string> st;
        int maxlen=0;

        solve(s,str,st,0,0,maxlen);

        return vector<string>(begin(st),end(st));
        
    }
};