class Solution {
public:
    string maxSumOfSquares(int num, int sum) {

        if (sum > num * 9) return "";

        string ans = "";

        int div=sum/9;

        while (div--) {
            ans+='9';
            num--;
        }

        int rem=sum%9;
        if(rem>0){
            ans+=to_string(rem);
            num--;
        }

        while(num--){
            ans+='0';
        }

        return ans;
    }
};