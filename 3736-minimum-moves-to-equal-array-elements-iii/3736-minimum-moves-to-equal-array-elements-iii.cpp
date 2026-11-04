class Solution {
public:
    int minMoves(vector<int>& nums) {
        int count=0;
        int max_el=INT_MIN;

        for(int i=0;i<nums.size();i++){
            max_el=max(max_el,nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            count+= (max_el-nums[i]);
        }
        return count;
    }
};