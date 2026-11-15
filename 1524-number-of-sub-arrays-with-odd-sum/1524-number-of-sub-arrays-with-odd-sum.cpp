class Solution {
public: 
    int M=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();

        vector<int> subarr_sum(n,0);
        int sum=0;

        for(int i=0;i<n;i++){
            sum+=arr[i];
            subarr_sum[i]=sum;
        }

        long long  count=0;

        int even_count=0;
        int odd_count=0;
        for(int i=0;i<subarr_sum.size();i++){
            if(subarr_sum[i] % 2 != 0){      //odd + previous_even = odd
                count+=even_count+1;         // +1 for odd number itself
                odd_count++;
            }
            else{
                count+=odd_count;            //even + prvious_odd = odd 
                even_count++;
            }
        }

        return count % M;
    }
};