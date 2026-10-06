class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        string ans="";

        for(int i=0;i<s.size();i++){
            string word="";

            if(s[i]==' '){
                continue;
            }
            
            while(i<s.size() && s[i] != ' '){
                word+=s[i];
                i++;
            }

            reverse(word.begin(),word.end());
            
            ans+=word;
            ans+=" ";
        
        }

        return ans.substr(0,ans.size()-1);
    }
};