class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        
        string result = "1";
        
        for (int i = 2; i <= n; ++i) {
            result = nextSequence(result);
        }
        
        return result;
    }
    
private:
    string nextSequence(const string& s) {
        string result;
        int count = 1;
        
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) {
                ++count;
            } else {
                result += to_string(count) + s[i - 1];
                count = 1;
            }
        }
        
        result += to_string(count) + s.back();
        return result;
    }
};
