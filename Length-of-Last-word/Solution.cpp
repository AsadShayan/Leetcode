class Solution {
public:
    int lengthOfLastWord(string s) {
        int last = 0;
        int len = s.length() - 1;

        // Eliminating the spaces at the end of the string
        // i.e., after the last word
        while (len >= 0 && s[len] == ' ') {
            len--;
        }

        // Counting the length of the last word
        while (len >= 0 && s[len] != ' ') {
            last++;
            len--;
        }

        return last;
    }
};
