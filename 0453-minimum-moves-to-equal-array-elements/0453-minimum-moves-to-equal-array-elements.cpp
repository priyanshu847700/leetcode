class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans=0;
        int min_val=INT_MAX;

        for(int i=0;i<nums.size();i++){
            if(min_val>nums[i]){
                min_val=nums[i];
            }
        }

        for(int i=0;i<nums.size();i++){
            ans+=abs(min_val-nums[i]);
        }

        return ans;
    }
};