class Solution {
public:
    int find_day_of_year(string s,vector<int> &prefixsum){
        int month=stoi(s.substr(0,2));
        int day=stoi(s.substr(3,2));

        return prefixsum[month-1] + day;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> month_days = {31,28,31,30,31,30,31,31,30,31,30,31};

        
        vector<int> prefixsum(13,0);

        for(int i=1;i<=12;i++){
            prefixsum[i]=prefixsum[i-1]+month_days[i-1];
        }

        int arriveAlice_day = find_day_of_year(arriveAlice, prefixsum);
        int leaveAlice_day = find_day_of_year(leaveAlice, prefixsum);
        int arriveBob_day = find_day_of_year(arriveBob, prefixsum);
        int leaveBob_day = find_day_of_year(leaveBob, prefixsum);

        int days_overlaps= min(leaveAlice_day,leaveBob_day) - max(arriveAlice_day,arriveBob_day)+1;

        if(days_overlaps <= 0){
            return 0;
        }

        return days_overlaps;
    }
};