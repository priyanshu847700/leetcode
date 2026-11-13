class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        nth_element(nums.begin(), nums.begin() + n/2, nums.end());
        
        int mid=nums[n/2];
        int ans=0;

        for(int i=0;i<nums.size();i++){
            ans+=abs(mid-nums[i]);
        }
        return ans;
    }
};