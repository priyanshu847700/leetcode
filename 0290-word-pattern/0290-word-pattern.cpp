class Solution {
public:
    bool wordPattern(string pattern, string s) {

        unordered_map<string,char> mp;
        unordered_map<char,char> mp2;

        stringstream ss(s);
        string word;

        string newstr,newpattern;

        int i=0;
        
        while( ss >> word){

            if(mp.find(word) == mp.end()){
                char ch='a'+i;
                mp[word]=ch;
                i++;
            }

            newstr+=mp[word];
        }

        i = 0;
        for (char ch : pattern) {
            if (mp2.find(ch) == mp2.end()) {
                mp2[ch] = 'a' + i;
                i++;
            }

            newpattern += mp2[ch];
        }

        if(newpattern == newstr ) return true;
        return false;
    }
};