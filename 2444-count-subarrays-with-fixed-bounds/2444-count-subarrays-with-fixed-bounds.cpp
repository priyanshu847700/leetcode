class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int min_idx=-1;
        int max_idx=-1;

        int culprit_idx=-1;
        long long ans=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==minK){
                min_idx=i;
            }
            if(nums[i]==maxK){
                max_idx=i;
            }
            if(nums[i] > maxK || nums[i] < minK){
                culprit_idx=i;
            }

            long long smaller=min(min_idx,max_idx);

            long long temp= smaller - culprit_idx;
            if(temp > 0){
                ans+=temp;
            }
        }
        return ans;
    }
};