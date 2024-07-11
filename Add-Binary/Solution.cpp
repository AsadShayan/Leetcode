class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        std::string result = "";
        int carry = 0;
        int i = a.length() - 1, j = b.length() - 1;
        
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            carry = sum / 2;
            result += (sum % 2) + '0';
        }

        // Reverse the result string manually
        int start = 0, end = result.length() - 1;
        while (start < end) {
            char temp = result[start];
            result[start] = result[end];
            result[end] = temp;
            start++;
            end--;
        }

        return result;
    }
};
