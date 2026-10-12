class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        
        vector<int> count(32,0);

        for(auto el : nums){
            bitset<32> b(el);
            for(int i=0;i<32;i++){
                if(b[i]==1){
                    count[i]++;
                }
            }
        }

        long long ans=0;

        while(k--){
            long long curr=0;
            for(int i=0;i<32;i++){
                if(count[i]>0){
                    count[i]--;

                    bitset<32> bits(curr);  // Convert curr into bits
                    bits[i] = 1;            // Set bit i to 1
                    curr = bits.to_ullong();
                }
            }
            ans= (ans + curr * curr) % int(1e9+7);
        }

        return ans;
    }
};