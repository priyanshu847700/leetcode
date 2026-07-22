class Solution {
public:
    int climbStairs(int n) {
        if(n==1 || n==2){
            return n;
        }

        vector<int> dq(n+1,-1);
        dq[1]=1;
        dq[2]=2;

        for(int i=3;i<=n;i++){
            dq[i]=dq[i-1]+dq[i-2];
        }
        return dq[n];
    }
};