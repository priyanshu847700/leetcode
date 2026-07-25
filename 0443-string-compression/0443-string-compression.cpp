class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int idx=0;
        for(int i=0;i<n;i++){
            char ch=chars[i];
            int count=0;
            while(n>i && chars[i]==ch){
                count++;i++;
            }
            if(count==1){
                chars[idx]=ch;
                idx++;
            }
            else{
                chars[idx]=ch;
                idx++;
                string str=to_string(count);
                for(char val:str){
                chars[idx]=val;
                idx++;
                }
            }
            i--;
        }
        chars.resize(idx);
        return idx;
    }
};
