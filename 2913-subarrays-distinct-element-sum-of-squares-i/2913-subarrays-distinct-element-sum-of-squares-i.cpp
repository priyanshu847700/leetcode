class Solution {
public:
    int sumCounts(vector<int>& nums) {
        vector<set<int>> subarray;

        set<int> path;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                
                for(int k=i;k<=j;k++){
                    path.insert(nums[k]);
                }
                
                subarray.push_back(path);
                path.clear();
            }
        }

        int ans=0;
        for(int i=0;i<subarray.size();i++){
            int sz=subarray[i].size();
            ans+=(sz*sz);
        }
        return ans;
    }
};