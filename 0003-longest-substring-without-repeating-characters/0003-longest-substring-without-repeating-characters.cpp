// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int i=0;
//         int j=0;
//         int count=0;
//         int maxcount=INT_MIN;

//         unordered_set<char> s1;

//         while(j<s.size()){
//             if(s1.find(s[j]) == s1.end()){
//                 count++;
//                 s1.insert(s[j]);
//                 maxcount=max(maxcount,count);
//             }
//             else{
//                 s1.erase(s[i]);
//                 i++;
//                 count--;
//             }
//         }
//         return maxcount;
//     }
// };


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        int count = 0;
        int maxcount = 0;

        unordered_set<char> s1;

        while (j < s.size()) {

            if (s1.find(s[j]) == s1.end()) {
                count++;
                s1.insert(s[j]);
                maxcount = max(maxcount, count);
                j++;
            }
            else {
                s1.erase(s[i]);
                i++;
                count--;
            }
        }

        return maxcount;
    }
};