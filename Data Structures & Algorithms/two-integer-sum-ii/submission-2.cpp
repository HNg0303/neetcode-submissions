class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // Two pointers in opposite direction. Condition index1 < index2. 
        // Because the array is sorted, if sum  > target move right pointer else move left pointer.
        int l = 0;
        int r = numbers.size() - 1;
        vector<int> result;
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum > target) r--;
            else if (sum < target) ++l;
            else {
                result = {l + 1, r + 1};
                return result;
            }
        } 
        return result;
    }
};
