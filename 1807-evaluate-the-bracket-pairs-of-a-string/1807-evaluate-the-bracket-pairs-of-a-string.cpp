class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;

        int row=knowledge.size();   

        for(int i=0;i<row;i++){
            mp[knowledge[i][0]]=knowledge[i][1];
        }

        string ans = "";

        for(int i=0;i<s.size();i++){
            char ch=s[i];
            string substr;

            

            if(ch=='('){
                while(true){
                    i++;
                    if(s[i]==')'){
                        break;
                    }
                    else{
                        substr+=s[i];
                    }
                }
            
                if(mp.find(substr) != mp.end()){ 
                    ans+=mp[substr];
                }
                else{
                    ans+='?';
                }
            }
            else{
                ans+=ch;
            }
        }
        return ans;
    }
};