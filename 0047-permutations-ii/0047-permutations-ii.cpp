class Solution {
public:
    void all_unique_permutation(vector<int>& nums,vector<vector<int>> &ans,int idx){
        if(idx==nums.size()){
            ans.push_back(nums);
            return;
        }

        unordered_set<int> s;
        for(int i=idx;i<nums.size();i++){
            if(s.find(nums[i]) != s.end() ){
                continue;
            }

            s.insert(nums[i]);

            swap(nums[idx],nums[i]);
            all_unique_permutation(nums,ans,idx+1);
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;

        all_unique_permutation(nums,ans,0);

        return ans;
    }
};
