#include <string>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int letterCount[26] = {0};  // Array to store counts of each letter

        // Count the characters in the magazine
        for (char c : magazine) {
            letterCount[c - 'a']++;
        }

        // Check if we can construct the ransomNote
        for (char c : ransomNote) {
            if (letterCount[c - 'a'] > 0) {
                letterCount[c - 'a']--;
            } else {
                return false;  // Not enough letters in the magazine
            }
        }

        return true;  // Successfully constructed the ransomNote
    }
};
