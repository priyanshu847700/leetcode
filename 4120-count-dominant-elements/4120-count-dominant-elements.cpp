class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        int n=nums.size();

        if(n==1){
            return n;
        }

        int ans=0;

        if( nums[0] >= nums[1] ){
            ans++;
        }
        if( nums[n-2] <= nums[n-1] ){
            ans++;
        }

        for(int i=1;i<n-1;i++){
            float avg = ( nums[i+1] + nums[i-1] ) / 2.0;
            if( nums[i] >= avg ){
                ans++;
            }
        }

        return ans;
    }
};