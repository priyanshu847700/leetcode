class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();

        int smallest = *min_element(nums.begin(), nums.end());
        int largest = *max_element(nums.begin(), nums.end());
        
        int count=0;
        int mini=INT_MAX;

        int flag1=0;
        int flag2=0;

        for(int i=0;i<n;i++){
            if(nums[i]==smallest){
                flag1=1;
            }
            if(nums[i]==largest){
                flag2=1;
            }
            count++;

            if(flag1==1 && flag2==1){
                break;
            }
            
        }

        mini=min(mini,count);

        flag1=0;
        flag2=0;
        count=0;

        

        for(int i=n-1;i>=0;i--){
            if(nums[i]==smallest){
                flag1=1;
            }
            if(nums[i]==largest){
                flag2=1;
            }

            count++;
            if(flag1==1 && flag2==1){
                break;
            }
            
        }

        mini=min(mini,count);
        count=0; 

        int l=0;
        int r=n-1;
        while (l <= r) { 
            count++;
            if (nums[l] == smallest || nums[l] == largest){ 
                break;             
            }
            l++;
        } 
        while (l <= r) { 
            count++;
            if (nums[r] == smallest || nums[r] == largest){
                break; 
            }
            r--; 
        }

        mini=min(mini,count);

        return mini;

    }
};

