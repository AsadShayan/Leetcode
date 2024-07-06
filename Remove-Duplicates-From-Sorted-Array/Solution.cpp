class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int k = 1; // Initialize the count of unique elements
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                nums[k] = nums[i]; // Place the unique element in its correct position
                ++k; // Increment the count of unique elements
            }
        }
        
        return k; // Return the number of unique elements
    }
};
