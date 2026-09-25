class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0;
        unordered_map<int,int> mp;

        mp[0]=-1;

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            mp[sum]=i;
        }

        if(sum<x){
            return -1;
        }

        int longest_subarray_sum=sum-x;
        int longest_subarray_size=INT_MIN;

        sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];

            int findsum=sum-longest_subarray_sum;

            if(mp.find(findsum) != mp.end()){
                int idx=mp[findsum];

                longest_subarray_size=max(longest_subarray_size,i-idx);
            }
        }
        if(longest_subarray_size==INT_MIN){
            return -1;
        }
        return (nums.size()-longest_subarray_size);
    }
};