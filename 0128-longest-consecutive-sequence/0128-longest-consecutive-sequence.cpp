class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int n : nums) {
            s.insert(n);
        }
        int longestStreak = 0;
         for (int num : s) {
            if (!s.count(num-1)) {
                int currentNum = num;
                int currentStreak = 1;
                while (s.count(currentNum+1)) {
                    currentNum++;
                    currentStreak++;
                }
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        return longestStreak;
    }
};

// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         unordered_set<int> s;
//         for(int n : nums) {
//             s.insert(n);
//         }
//         int ans=0;
//         for(auto it:s) {
//             if (!s.count(it-1)) {
//                 int x = it;
//                 int cnt = 1;
//                 while (s.count(x+1)) {
//                     x++;
//                     cnt++;
//                 }
//                 ans = max(ans, cnt);
//             }
//         }
//         return ans;
//     }
// };