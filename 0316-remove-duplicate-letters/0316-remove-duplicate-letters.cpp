class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.size();

        string ans;
        vector<bool> visited(26,false);
        vector<int> lastidx(26,false);

        for(int i=0;i<n;i++){
            char ch=s[i];
            lastidx[ch-'a']=i;
        }

        for(int i=0;i<n;i++){
            char ch=s[i];

            int idx=ch-'a';

            if(visited[idx] == true){
                continue;
            }

            while(ans.length() > 0 && ans.back() > ch && lastidx[ans.back() - 'a'] > i){
                visited[ans.back()-'a'] = false;
                ans.pop_back();
            }
            ans.push_back(ch);
            visited[idx]=true;
        }
        return ans;
    }
};