class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        //sort(spaces.begin(),spaces.end());
        int l=spaces.size(),n=s.length();
        int j=0;
        string ans="";
        for(int i=0;i<n;i++){
            if(j<l){
                if(i==spaces[j]){
                    ans+=' ';
                    j++;
                }
            }
                ans+=s[i];
        }
        return ans;
    }
};