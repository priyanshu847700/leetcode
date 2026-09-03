class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;

        // Find the smallest odd number
        for (int x : nums1) {
            if (x % 2 != 0) {
                minOdd = min(minOdd, x);
            }
        }

        // Check if any even number is smaller than the smallest odd number
        for (int x : nums1) {
            if (x % 2 == 0 && minOdd != INT_MAX && x < minOdd) {
                return false;
            }
        }

        return true;
    }
};