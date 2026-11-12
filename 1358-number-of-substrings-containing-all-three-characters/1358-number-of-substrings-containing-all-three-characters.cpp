class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0;
        int j=0;
        unordered_map<char,int> m;
        int count=0;

        while(j<s.size()){
            m[s[j]]++;

            while(m['a'] > 0 && m['b'] > 0 && m['c'] > 0){
                count+=s.size() - j;

                m[s[i]]--;
                i++;
            }
            j++;
        }
        return count;
    }
};