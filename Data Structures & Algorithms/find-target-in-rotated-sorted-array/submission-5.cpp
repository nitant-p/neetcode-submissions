class Solution {
public:
    int binarySearch(vector<int>& nums, int low, int high, int target) {
        cout << "here" << endl;
        cout << "low: " << low << endl;
        cout << "high: " << high << endl;


        while (low <= high) {
            
            int mid = (high + low) / 2;
            cout << "mid: " << mid << endl;
            if (nums[mid] > target) {
                high = mid - 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                return mid;
            }
        cout << "low: " << low << endl;
        cout << "high: " << high << endl;

        }
        return -1; 
    }

    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;

        if (nums.size() > 1 && nums[0] > nums[nums.size() - 1]) {
            // rotated
            // find pivot first
            int high = nums.size() - 1, low = 0;
            int pivot = (high + low) / 2;
            while (true) {
                cout << "pivot: " << pivot << endl;
                if (pivot == nums.size() - 1) {
                    if (nums[pivot] < nums[pivot - 1]) break;
                } else if (pivot == 0) {
                    if (nums[0] > nums[1]) break;
                } else if (nums[pivot - 1] < nums[pivot] && nums[pivot] > nums[pivot + 1]) {
                    break;
                }
                
                if (nums[pivot] > nums.back()) {
                    // move pivot right and exclude current
                    low = pivot + 1;
                } else {
                    // move left and exclude current
                    high = pivot - 1;
                }
                pivot = (high + low) / 2;
            }
            if (nums.back() >= target) return binarySearch(nums, pivot + 1, nums.size() - 1, target);
            else return binarySearch(nums, 0, pivot, target);
        } else {
            // normal
            return binarySearch(nums, 0, nums.size() - 1, target);
        }
    }
};
