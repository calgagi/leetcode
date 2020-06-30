// This solution does not work due to negative numbers (-4 * -8, etc.)
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // Just find the max 3 numbers
        priority_queue<int> q(nums.begin(), nums.end());
        int x = q.top();
        q.pop();
        int y = q.top();
        q.pop();
        int z = q.top();
        q.pop();
        return x * y * z;
    }
};
