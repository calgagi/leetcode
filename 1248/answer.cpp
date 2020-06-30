class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> end(nums.size());
        int count = 0;
        int res = 0;
        for (int i = nums.size()-1; i >= 0; i--) {
            count++;
            end[i] = count;
            if (nums[i] % 2 == 1)
                count = 0;
        }
        queue<int> q;
        int prev = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 1)
                q.push(i);
            if (q.size() == k) {
                int left = (q.front() - prev + 1);
                int right = end[i];
                res += left * right;
                prev = q.front()+1;
                q.pop();
            }
        }
        return res;
    }
};
