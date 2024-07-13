#include <string>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        bool hasNum = false, hasDot = false, hasE = false, hasSign = false;
        
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            
            if (isdigit(c)) {
                hasNum = true;
                hasSign = false; // sign is only valid at the beginning or after 'e'
            } else if (c == '+' || c == '-') {
                if (hasSign || hasNum || hasDot) {
                    return false; // sign must be at the beginning or right after 'e'
                }
                hasSign = true;
                hasNum = false; // reset hasNum after a sign
            } else if (c == '.') {
                if (hasDot || hasE) {
                    return false; // no dot after another dot or 'e'
                }
                hasDot = true;
                hasSign = false;
            } else if (c == 'e' || c == 'E') {
                if (hasE || !hasNum) {
                    return false; // 'e' must follow a number and must be the first 'e'
                }
                hasE = true;
                hasSign = true;
                hasNum = false; // reset hasNum for the exponent part
            } else {
                return false; // any other character is invalid
            }
        }
        return hasNum; // there must be at least one digit in the number
    }
};
