class Solution {
public:
    void noduplicatesubset(vector<int>& nums,int i,vector<vector<int>> &uniquesubset,vector<int> &ans){
        if(i==nums.size()){
            uniquesubset.push_back({ans});
            return;
        }

        ans.push_back(nums[i]);
        noduplicatesubset(nums, i+1, uniquesubset,ans);
        ans.pop_back();

        int idx=i+1;
        while(idx<nums.size() && nums[idx]==nums[idx-1]){
            idx++;
        }
        noduplicatesubset(nums,idx, uniquesubset,ans);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> uniquesubset;
        vector<int> ans;

        noduplicatesubset(nums, 0, uniquesubset,ans);

        return uniquesubset;
    }
};