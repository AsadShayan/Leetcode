#include <vector>
#include <algorithm>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        int n = nums.size();
        int jumps = 0, current_end = 0, farthest = 0;

        for (int i = 0; i < n - 1; ++i) {
            // Update the farthest point we can reach
            farthest = std::max(farthest, i + nums[i]);

            // If we have reached the end of the current jump,
            // increment the number of jumps and update the end
            if (i == current_end) {
                ++jumps;
                current_end = farthest;
            }
        }

        return jumps;
    }
};
