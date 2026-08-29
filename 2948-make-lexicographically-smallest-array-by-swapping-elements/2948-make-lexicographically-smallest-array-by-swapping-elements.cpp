class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>> val_index;
        for(int i=0;i<nums.size();i++){
            val_index.push_back({nums[i],i});
        }

        sort(val_index.begin(),val_index.end());

        vector<vector<int>> groups={{val_index[0].second}};      //because loop is start from 1 val so 0 index will be left over to form inside group
        for(int i = 1; i < nums.size(); i++) {
            if(val_index[i].first - val_index[i-1].first <= limit) {
                groups.back().push_back(val_index[i].second);
            }
            else {
                groups.push_back({val_index[i].second});
            }
        }

        for(auto &group : groups){
            sort(group.begin(),group.end());
        }


        vector<int> final_index;

        for(auto &group : groups) {
            for(int x : group) {
                final_index.push_back(x);
            }
        }
        
        vector<int> ans(nums.size());
        for(int i = 0; i < final_index.size(); i++){
            ans[final_index[i]] = val_index[i].first;
                
        }
        return ans;
    }
};