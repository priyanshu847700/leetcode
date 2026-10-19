class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {
        int i=0;
        int j=0;

        int max_count=0;
        int count=0;

        while(j<s.size()){

            if( isVowel(s[j]) ){
                count++;
            }

            if(j-i+1 == k){
                max_count=max(max_count,count);

                if( isVowel(s[i]) ){
                    count--;
                }
                i++;
            }
            j++;
        }

        return max_count;
    }
};