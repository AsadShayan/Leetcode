class Solution {
public:
    int minimumLength(string s) {
        int left = 0, right = s.size() - 1;
        
        while (left < right && s[left] == s[right]) {
            char currentChar = s[left];
            
            while (left <= right && s[left] == currentChar) {
                left++;
            }
            
            while (left <= right && s[right] == currentChar) {
                right--;
            }
        }
        
        return right - left + 1;
    }
};
