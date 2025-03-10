#define ll long long
class Solution {
public:
    bool isVowel(char ch){
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
    }
    ll atleast(string word, int k){
        ll n=word.size();
        ll left =0;
        ll concnt=0;
        unordered_map<char, ll> v;
        ll ans=0;
        for(ll right=0; right<n; right++){
            if(isVowel(word[right])) v[word[right]]++;
            else concnt++;
            while(v.size()>=5 && concnt>=k){
                    ans+=(n-right);
                    if(isVowel(word[left])) v[word[left]]--;
                    else concnt--;
                    if(v[word[left]]==0) v.erase(word[left]);
                    left++;
            }

        }
        return ans;
    }
    ll countOfSubstrings(string word, int k) {
        return atleast(word, k)-atleast(word, k+1);
    }
};