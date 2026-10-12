class Solution {
public: 
    bool palindrome(string s,int st,int end){
        while(st<end){
            if(s[st] != s[end]){
                return false;
                
            }
            st++;
            end--;
        }
        return true;
    }
    void backtrack(string s,vector<vector<string>> &ans,vector<string> &path , int idx){

        if(idx == s.size()){
            ans.push_back(path);
            return;
        }

        for(int i=idx;i<s.size();i++){
            if(palindrome(s,idx,i)){
                path.push_back(s.substr(idx,i-idx+1));
                backtrack(s,ans,path,i+1);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;

        backtrack(s,ans,path,0);

        return ans;
    }
};