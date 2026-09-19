class Solution {
public:
    int search(vector<int>& n, int tar) {
        int st = 0, end = n.size() - 1;
        
        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (n[mid] == tar)
                return mid;

            // Left half is sorted
            if (n[st] <= n[mid]) {
                if (n[st] <= tar && tar < n[mid])
                    end = mid - 1;
                else
                    st = mid + 1;
            }
            // Right half is sorted
            else {
                if (n[mid] < tar && tar <= n[end])
                    st = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return -1;
    }
};