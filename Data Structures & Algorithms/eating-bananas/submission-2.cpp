class Solution {
public:
    int calcHours (int bananas, int speed) {
        // add speed to push to next 'bucket', subtract 1 
       return (bananas + speed - 1) / speed;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int minK = INT_MAX;
        while (low <= high) {
            int speed = low + (high - low) / 2;
            int totalH = 0;
            bool valid = true;
            for (auto b : piles) {
                totalH += calcHours(b, speed);
                if (totalH > h) { 
                    low = speed + 1;
                    valid = false;
                    break;
                }
            }
            if (valid) {
                minK = min(minK, speed);
                high = speed - 1;
            }
        }

        return minK;
    }
};
