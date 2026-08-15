class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        bool allzero=true;
        int ans=0;

        for(int i=0;i<nums.size();i++){
            ans^=nums[i];
            if(nums[i]!=0){
                allzero=false;
            }
        }
        if(allzero) return 0;
        if(ans!=0){
            return nums.size();
        }
        return nums.size()-1;
    }
};