class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0;
        
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }

        if(sum<x){
            return -1;
        }

        int target_sum=sum-x;
        int l=0,r=0,maxlen=INT_MIN;
        sum=0;
        while(r<nums.size()){
            sum+=nums[r];

            while(sum>target_sum){
                sum-=nums[l];
                l++;
            }
            
            if(sum == target_sum){
                maxlen=max(maxlen,r-l+1);
            }
            
            r++;
        }
        if(maxlen==INT_MIN){
            return -1; 
        }
        return nums.size()-maxlen;
    }
};