class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalgas=0,totalcost=0;

        for(int i:gas){
            totalgas+=i;
        }
        for(int i:cost){
            totalcost+=i;
        }
        if(totalcost > totalgas){
            return -1;
        }

        //unique soln exist!!
        int st=0,currgas=0;

        for(int i=0;i<gas.size();i++){
            currgas+=(gas[i]-cost[i]);

            if(currgas<0){
                st=i+1;
                currgas=0;
            }
        }
        return st;
    }
};