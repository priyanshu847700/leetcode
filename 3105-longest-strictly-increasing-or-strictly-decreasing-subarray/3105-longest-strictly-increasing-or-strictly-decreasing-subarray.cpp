class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int strictly_inc=1;
        int strictly_dec=1;

        int max_length=1;

        for(int i=0;i<nums.size()-1;i++){
            
            if(nums[i]<nums[i+1]){
                strictly_inc+=1;
                max_length=max(max_length,strictly_inc);
            }
            else{
                strictly_inc=1;
            }
        }

        for(int i=0;i<nums.size()-1;i++){
            
            if(nums[i]>nums[i+1]){
                strictly_dec+=1;
                max_length=max(max_length,strictly_dec);
            }
            else{
                strictly_dec=1;
            }
        }

        return max_length;
    }
};