class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count=0;
        bool is_all_valid=true;

        for(int i=0;i<arr1.size();i++){
            for(int j=0;j<arr2.size();j++){
                if( abs(arr1[i] - arr2[j]) <= d) {
                    is_all_valid=false;
                }
            }
            if(is_all_valid){
                count++;
            }
            is_all_valid=true;
        }

        return count;
    }
};