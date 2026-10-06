class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char,int> mp;
        int maxcount=0;
        int l=0,r=0;

        while(r<s.size()){
            if( mp.find(s[r]) == mp.end() ){
                mp[s[r]]=r;
                
            }
            else{
                l=max(l,mp[s[r]]+1);
                mp[s[r]]=r;
                
            }
            maxcount=max(maxcount,r-l+1);
            r++;

        }

        return maxcount;
    }
};