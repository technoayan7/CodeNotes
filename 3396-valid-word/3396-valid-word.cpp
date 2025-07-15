class Solution {
public:
    bool isValid(string word) {
        int n = word.size();
        if(n<3) return false;
        int vowels = 0, consonant = 0;
        for(auto it: word) {
            if(it >= '0' and it<='9') continue;
            if(it >= 'a' and it <= 'z'  || it >= 'A' and it <= 'Z') {
                it |= 32;
                if(it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u') vowels++;
                else consonant++;
            }
            else return false;
        }
        return vowels and consonant;
    }
};