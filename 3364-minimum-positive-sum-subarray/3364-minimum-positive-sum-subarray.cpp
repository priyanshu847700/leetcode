class Solution {
public:
    int get_sum(vector<int> &temp){
        int sum=0;

        for(int i=0;i<temp.size();i++){
            sum+=temp[i];
        }
        return sum;
    }

    int minimumSumSubarray(vector<int>& nums, int l, int r) {

        int ans=INT_MAX;

        for(int k=l;k<=r;k++){

            int i=0;
            int j=0;

            vector<int> temp;

            while(j<nums.size()){
                temp.push_back(nums[j]);
            
                if(temp.size() == k){
                    int sum=get_sum(temp);

                    if(sum > 0){
                        ans=min(ans,sum);
                    }
                    temp.erase(temp.begin());
                    i++;
                }
                j++;
            }
        }

        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};