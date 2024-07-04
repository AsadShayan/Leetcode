#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> num_to_index;  // Hash map to store number and its index
        
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            // Check if the complement exists in the hash map
            if (num_to_index.find(complement) != num_to_index.end()) {
                return {num_to_index[complement], i};
            }
            
            // If not found, add the current number and its index to the hash map
            num_to_index[nums[i]] = i;
        }
        
        // If no solution is found, return an empty vector (though the problem guarantees a solution)
        return {};
    }
};
