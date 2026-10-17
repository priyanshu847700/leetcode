class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        set<int> s;

        while(j<nums.size()){

            while(abs(i-j) > k){
                s.erase(nums[i]);
                i++;
            }

            if(j-i <= k){
                if(s.find(nums[j]) != s.end()){
                    return true;
                }
            }

            s.insert(nums[j]);
            j++;
        }
        return false;
    }
};