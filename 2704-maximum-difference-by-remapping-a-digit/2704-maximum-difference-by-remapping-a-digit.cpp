class Solution {
public:
    int minMaxDifference(int num) {
    string s = std::to_string(num);
    int mx = num;
    int mi = num;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            string s1 = s;
            replace(s1.begin(), s1.end(), '0' + i, '0' + j);
            int temp = stoi(s1);
            if (temp > mx) {
                mx = temp;
            }
            if (temp < mi && (j > 0 || i > 0)) {
                mi = temp;
            }
        }
    }
    return mx - mi;
    }
};