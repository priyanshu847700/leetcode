class Solution {
public:
    static int digitsum(int n){
        int sum=0;

        while(n>0){
            sum += n%10;
            n /= 10;
        }

        return sum;
    }

    static bool compare(int num1,int num2){
        int num1digsum=digitsum(num1);
        int num2digsum=digitsum(num2); 

        if(num1digsum != num2digsum){
            return num1digsum < num2digsum;
        }
        else{
            return num1 < num2;   
        }
    }

    int minSwaps(vector<int>& nums) {
        
        vector<int> after_swap(nums);

        // auto lambda=[&](int num1,int num2){
        //     int num1digsum=digitsum(num1);
        //     int num2digsum=digitsum(num2);

        //     if(num1digsum != num2digsum){
        //         return num1digsum < num2digsum;
        //     }
        //     else{
        //         return num1 < num2;   
        //     }
        // };

        sort(nums.begin(),nums.end(),compare);

        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]=i;
        }

        int swap_count=0;

        for(int i=0;i<nums.size();i++){
            if(after_swap[i] != nums[i] ){
                int pos=m[after_swap[i]];

                swap(nums[i],nums[pos]);
                m[nums[i]]=i;
                m[nums[pos]]=pos;
                
                swap_count++;
            }
        }

        return swap_count;
    }
};