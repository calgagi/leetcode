class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();
        bool found = 0;
        for (int i = 0; i < n/2; i++) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                found = 1;
                break;
            }
        }
        // all a's
        if (n != 1 && !found) {
            palindrome[n-1] = 'b';
            return palindrome;
        }
        return (found ? palindrome : "");
    }
};
