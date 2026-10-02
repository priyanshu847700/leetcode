class Solution {
public:
    bool hasduplicate(string &s1,string &s2){
        vector<int> freq(26,0);

        for(int i = 0; i < s1.size(); i++){
            char ch = s1[i];
            if(freq[ch - 'a'] > 0){
                return true;
            }
            freq[ch - 'a']++;
        }

        for(int i = 0; i < s2.size(); i++){
            char ch = s2[i];
            if(freq[ch - 'a'] > 0){
                return true;
            }

            freq[ch - 'a']++;
        }
        return false;
    }

    int solve(vector<string> &arr,string temp,int n,int i){
        if(i == n){
            return temp.length();
        }

        int include=0;
        int exclude=0;

        if(hasduplicate(temp,arr[i])){
            exclude=solve(arr,temp,n,i+1);
        }
        else{
            exclude=solve(arr,temp,n,i+1);
            include=solve(arr,temp+arr[i],n,i+1);
        }
        return max(include,exclude);

    }
    int maxLength(vector<string>& arr) {
        string temp="";
        int n=arr.size();

        return solve(arr,temp,n,0);
    }
};