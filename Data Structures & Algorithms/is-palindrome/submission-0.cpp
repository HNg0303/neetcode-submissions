class Solution {
public:
    bool isPalindrome(string s) {
        // Two Pointers: move in opposite direction, until l >= r.
        // Because if reverse the string it will be in that index: i == n - i.
        // Complexity: O(N)
        int l = 0;
        int r = s.length() - 1;
        while (l < r) {
            if (!(('A' <= s[l] && s[l] <= 'Z') || ('a' <= s[l] && s[l] <= 'z') || ('0' <= s[l] && s[l] <= '9'))) {
                ++l;
                continue;
            }
            if (!(('A' <= s[r] && s[r] <= 'Z') || ('a' <= s[r]  && s[r] <= 'z') || ('0' <= s[r] && s[r] <= '9'))) {
                --r;
                continue;
            }
            if (tolower(s[l]) != tolower(s[r])) return false;
            ++l;
            --r;
        }
        return true;
    }
};
