class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>> &ans,unordered_set<int> &s,vector<int> &temp){

        if(temp.size() == nums.size()){
            ans.push_back({temp});
            return;
        }

        for(int i=0;i<nums.size();i++){
            if( s.find(nums[i]) == s.end() ){
                temp.push_back(nums[i]);
                s.insert(nums[i]);
                solve(nums,ans,s,temp);

                temp.pop_back();
                s.erase(nums[i]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        unordered_set<int> s;

        solve(nums,ans,s,temp);

        return ans;
    }
};