class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        long long ans=0;
        int i=0;
        int j=nums.size()-1;

        while(i<j){
            ans+=nums[j-1];
            i++;
            j-=2;
        }
        return ans;
    }
};