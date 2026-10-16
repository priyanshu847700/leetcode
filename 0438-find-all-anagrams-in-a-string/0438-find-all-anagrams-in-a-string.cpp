class Solution {
public:
    bool allzeros(vector<int> &freq){
        for(auto i : freq){
            if(i != 0){
                return false;
            }
        }
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        vector<int> freq(26,0);

        for(int i=0;i<p.size();i++){
            char ch=p[i];

            freq[ch-'a']++;
        }

        int i=0,j=0;
        vector<int> ans;
        
        while(j<s.size()){
            freq[s[j]-'a']--;

            if(j-i+1 == p.size()){
                if(allzeros(freq)){
                    ans.push_back(i);
                }

                freq[s[i]-'a']++;
                i++;
            }
            j++;
        }
        return ans;
    }
};