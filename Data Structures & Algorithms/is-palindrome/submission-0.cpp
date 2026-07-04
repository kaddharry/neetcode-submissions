class Solution {
   public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        int left = 0;
        int right = s.length() - 1;
        while (left <= right) {
            char l = s[left], r = s[right];
            if (isalnum(l) && isalnum(r)) {
                if (l != r)
                    return false;
                else {
                    left++;
                    right--;
                }
            } else if (!isalnum(l))
                left++;
            else
                right--;
        }
        return true;
    }
};
