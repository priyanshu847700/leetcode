class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {

        vector<int> countdiff(1e5+1,0);

        int k=k1+k2;

        for(int i=0;i<nums1.size();i++){
            int d=abs(nums1[i]-nums2[i]);
            countdiff[d]++;
        }

        for(int i=1e5; i>0 && k>0 ;i--){
            int minoperation=min(countdiff[i],k);
            countdiff[i] -= minoperation;
            countdiff[i-1] += minoperation;

            k-=minoperation;
        }

        long long ans=0;
        for(long long  d=0;d<=1e5;d++){
            ans+= (countdiff[d] * (d*d));
        }

        return ans;
    }
};