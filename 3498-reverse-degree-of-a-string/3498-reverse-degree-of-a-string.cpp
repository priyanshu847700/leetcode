class Solution {
public:
    int reverseDegree(string s) {
        int count=0;
        int pos=1;

        for(char i:s){
            count+= pos * (26-(i-'a'));
            pos++;
        }
        return count;
    }
};