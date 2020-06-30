class Solution {
public:
    int minimumDistance(string word) {
        // Distance between letters = int diff = abs((word[i] - 'a')-(word[i+1] - 'a')); dist = diff/6 + diff%6; 
        // First hand must start at 0. second hand start at any time
        int res = INT_MAX;
        int n = word.size();
        int cur = 0;
        for (int i = 0; i < n-1; i++) {
            int go_cur = cur, first_hand = i, second_hand = i+1;
            for (int j = i+2; j < n; j++) {
                int diffFirst = abs((word[j]-'A')/6-(word[first_hand]-'A')/6) + abs((word[j]-'A')%6-(word[first_hand]-'A')%6);
                int diffSecond = abs((word[j]-'A')/6-(word[second_hand]-'A')/6) + abs((word[j]-'A')%6-(word[second_hand]-'A')%6);
                if (diffFirst < diffSecond) {
                    first_hand = j;
                    go_cur += diffFirst;
                } else if (diffSecond < diffFirst || j == n-1) {
                    second_hand = j;
                    go_cur += diffSecond;
                } else {
                    int diffFirstLA = abs((word[j+1]-'A')/6-(word[first_hand]-'A')/6) + abs((word[j+1]-'A')%6-(word[first_hand]-'A')%6);
                    int diffSecondLA = abs((word[j+1]-'A')/6-(word[second_hand]-'A')/6) + abs((word[j+1]-'A')%6-(word[second_hand]-'A')%6);
                    if (diffSecondLA < diffFirstLA) {
                        first_hand = j;
                        go_cur += diffFirst;
                    } else {
                        second_hand = j;
                        go_cur += diffSecond;
                    }
                }
            }
            int diff = abs((word[i+1]-'A')/6-(word[i]-'A')/6) + abs((word[i+1]-'A')%6-(word[i]-'A')%6);
            cur += diff;
            res = min(go_cur, res);
        }
        return res;
    }
};
