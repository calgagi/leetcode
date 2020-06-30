class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<long long> q;
        long long sum = 0, goal = target.size();
        for (int i = 0; i < target.size(); i++) {
            q.push(target[i]);
            sum += target[i];
        }
        while (sum > goal) {
            long long big_item = q.top();
            q.pop();
            long long rest = sum - big_item;
            long long prev = big_item - rest;
            if (prev < 1) {
                return false;
            }
            sum = rest + prev;
            q.push(prev);
        }
        return sum == goal;
    }
};
