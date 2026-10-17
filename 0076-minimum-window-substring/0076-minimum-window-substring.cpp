class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";

        unordered_map<char,int> mp;
        for(int i=0;i<t.size();i++){
            mp[t[i]]++;
        }

        int requiredcount=t.size();
        int i=0, j=0;

        int minwindow_sz=INT_MAX;
        int start_i=0;

        while(j<s.size()){

            if(mp[s[j]] > 0){
                requiredcount--;
            }
            mp[s[j]]--;

            if(requiredcount == 0){
                
                while(requiredcount == 0){

                    if(minwindow_sz > j-i+1){
                        minwindow_sz=j-i+1;
                        start_i=i;  
                    }
                    
                    mp[s[i]]++;

                    if(mp[s[i]] > 0){
                        requiredcount++;
                    }
                    i++;
                }
            }
            j++;
        }

        if(minwindow_sz == INT_MAX) return "";
        return s.substr(start_i,minwindow_sz);
    }
};