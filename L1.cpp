
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        
        // Handle array of size 1
        if (n == 1) return 0;
        
        int low = 0;
        int high = n - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Case 1: mid is not an edge element
            if (mid > 0 && mid < n - 1) {
                if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                    return mid;
                }
                // If the left neighbor is greater, a peak must exist on the left
                else if (nums[mid - 1] > nums[mid]) {
                    high = mid - 1;
                } 
                // Otherwise, a peak must exist on the right
                else {
                    low = mid + 1;
                }
            }
            // Case 2: mid is the first element
            else if (mid == 0) {
                if (nums[0] > nums[1]) return 0;
                else return 1;
            }
            // Case 3: mid is the last element
            else if (mid == n - 1) {
                if (nums[n - 1] > nums[n - 2]) return n - 1;
                else return n - 2;
            }
        }
        return -1;
    }
};


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Standard Binary Search for the Ascending part
    int binarySearchAsc(vector<int>& nums, int low, int high, int target) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) return mid;
            if (target > nums[mid]) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }

    // Binary Search for the Descending part
    int binarySearchDesc(vector<int>& nums, int low, int high, int target) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) return mid;
            if (target > nums[mid]) high = mid - 1; // Reverse logic for descending
            else low = mid + 1;
        }
        return -1;
    }

    // YOUR PEAK FINDING CODE
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        int low = 0, high = n - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mid > 0 && mid < n - 1) {
                if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return mid;
                else if (nums[mid - 1] > nums[mid]) high = mid - 1;
                else low = mid + 1;
            }
            else if (mid == 0) {
                return (nums[0] > nums[1]) ? 0 : 1;
            }
            else if (mid == n - 1) {
                return (nums[n - 1] > nums[n - 2]) ? n - 1 : n - 2;
            }
        }
        return -1;
    }

    int searchBitonic(vector<int>& nums, int target) {
        int n = nums.size();
        int peak = findPeakElement(nums);

        // Try searching in the ascending half
        int firstHalf = binarySearchAsc(nums, 0, peak, target);
        if (firstHalf != -1) return firstHalf;

        // If not found, try searching in the descending half
        return binarySearchDesc(nums, peak + 1, n - 1, target);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 8, 12, 4, 2};
    int target = 4;
    
    int result = sol.searchBitonic(nums, target);
    cout << "Element found at index: " << result << endl;
    return 0;
}

