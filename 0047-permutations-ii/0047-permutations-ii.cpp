class Solution {
public: 
    void solve(vector<int>& nums,unordered_map<int,int> &mp,vector<vector<int>> &ans,vector<int> &temp){

        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }

        for (auto& [num, count] : mp) {
            if (count == 0) {
                continue;
            }

            temp.push_back(num);
            count--;

            solve(nums, mp, ans, temp);

            temp.pop_back();
            count++;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        unordered_map<int,int> mp;
        for(auto i :nums){
            mp[i]++;
        }

        solve(nums,mp,ans,temp);

        return ans;
    }
};