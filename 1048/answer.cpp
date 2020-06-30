class Solution {
public:
    int longestStrChain(vector<string>& words) {
        struct compare {
            bool operator()(const string& first, const string& second) {
              return first.length() < second.length();
            }
        };
        compare c;
        sort(words.begin(), words.end(), c);
        words.insert(words.begin(), "");
        vector<int> dp(words.size(), 1);
        dp[0] = 0;
        for (int i = 1; i < dp.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (words[i].length()-1 != words[j].length()) continue;
                // Edit distance
                int mistakes = 0;
                int i1 = 0, i2 = 0;
                while (i1 < words[j].length() && i2 < words[i].length()) {
                    if (words[j][i1] != words[i][i2]) {
                        if (mistakes == 1) {
                            mistakes += 1; break;
                        }
                        if (words[j].length() > words[i].length()) i1++;
                        else i2++;
                        mistakes++;
                    } else {
                        i1++; i2++;
                    }
                }
                if (mistakes < 2) {
                    dp[i] = max(dp[j]+1, dp[i]);
                }
            }
        }

        return *max_element(begin(dp), end(dp));
    }
};
