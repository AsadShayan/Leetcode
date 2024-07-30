class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> b_count(n+1, 0); // To store the number of 'b's up to each index
        vector<int> a_count(n+1, 0); // To store the number of 'a's from each index to the end

        // Count number of 'b's up to each position
        for (int i = 0; i < n; ++i) {
            b_count[i+1] = b_count[i] + (s[i] == 'b' ? 1 : 0);
        }

        // Count number of 'a's from each position to the end
        for (int i = n - 1; i >= 0; --i) {
            a_count[i] = a_count[i+1] + (s[i] == 'a' ? 1 : 0);
        }

        int min_deletions = INT_MAX;

        // Calculate the minimum deletions needed for each position
        for (int i = 0; i <= n; ++i) {
            min_deletions = min(min_deletions, b_count[i] + a_count[i]);
        }

        return min_deletions;
    }
};
