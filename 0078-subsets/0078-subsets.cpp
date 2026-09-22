class Solution {
public:
    void getallsubset(vector<int>& nums,vector<int> &ans,int i,vector<vector<int>> &allsubset){
        if(i==nums.size()){
            allsubset.push_back({ans});
            return;
        }

        ans.push_back(nums[i]);
        getallsubset(nums,ans,i+1,allsubset);
        ans.pop_back();
        getallsubset(nums,ans,i+1,allsubset);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allsubset;
        vector<int> ans;

        getallsubset(nums,ans,0,allsubset);
        return allsubset;
    }
};