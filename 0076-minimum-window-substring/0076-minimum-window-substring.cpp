class Solution {
public:
    bool all_zeros_or_lesser(unordered_map<char,int> &m){
        for(auto i:m){
            if(i.second > 0){
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";

        unordered_map<char,int> m;
        for(char ch : t){
            m[ch]++;
        }

        int min_sz=INT_MAX;
        int st_idx=0;

        int i=0,j=0;
        while(j<s.size()){
            m[s[j]]--;
            
            while(all_zeros_or_lesser(m)){
                if(min_sz > j-i+1){
                    min_sz=j-i+1;
                    st_idx=i;
                }

                m[s[i]]++;
                i++;
            }
            j++;

        }

        if (min_sz == INT_MAX) return "";
        return s.substr(st_idx,min_sz);
        
    }
}; 