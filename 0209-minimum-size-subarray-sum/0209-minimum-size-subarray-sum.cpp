class Solution {
public:
    int minSubArrayLen(int tar, vector<int>& nums) {
        int i=0,j=0;
        int sum=0;
        int minlen=INT_MAX;

        while(j<nums.size()){
            sum+=nums[j];

            while(sum>=tar){
                minlen=min(minlen,j-i+1);
                
                sum-=nums[i];
                i++;
            }
            
            j++;
        }

        if(minlen==INT_MAX) return 0;
        return minlen;
    }
};