class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int count1 = 0, count2 = 0, candidate1 = 0, candidate2 = 1;
        for (auto& item : nums) {
            if (count1 <= 0 && item != candidate2) {
                candidate1 = item;
            } else if (count2 <= 0 && item != candidate1) {
                candidate2 = item;
            }
            if (item == candidate1) 
                count1++;
            else if (item == candidate2) 
                count2++;
            else { 
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for (auto& item : nums) {
            if (item == candidate1) count1++;
            else if (item == candidate2) count2++;
        }
        if (count1 > nums.size()/3) res.push_back(candidate1);
        if (count2 > nums.size()/3) res.push_back(candidate2);
        return res;
    }
};
