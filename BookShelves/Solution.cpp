class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, INT_MAX); // dp[i] is the minimum height to place the first i books
        dp[0] = 0; // Base case: no books, no height

        for (int i = 1; i <= n; ++i) {
            int width = 0, height = 0;

            // Try to place as many books as possible on the same shelf
            for (int j = i; j > 0; --j) {
                width += books[j - 1][0];
                if (width > shelfWidth) break;
                height = max(height, books[j - 1][1]);
                dp[i] = min(dp[i], dp[j - 1] + height);
            }
        }

        return dp[n];
    }
};
