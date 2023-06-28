class Solution {
public:
    string trim(string s) {
        int x,y;
        for(int i=0;i<s.size();i++) {
            if(s[i]!=' '){ 
                x=i;
                break;
            }
        }
        for(int i=s.size()-1;i>=0;i--) {
            if(s[i]!=' '){ 
                y=i;
                break;
            }
        }
        s=s.substr(x,y-x+1);
        return s;
    }

    string reverseWords(string s) {
        vector<string>v;
        s = trim(s);
        s+=" ";
        int n=s.size();
        string w="";
        for(int i=0;i<n;i++) {
            if(s[i]!=' ') {
                w+=s[i];
            }
            else {
                if(w=="") continue;
                v.push_back(w);
                w="";
            }
        }
        reverse(v.begin(),v.end());
        string ans="";
        for(auto i:v) {
            ans.append(' '+ i);
        }
        ans = trim(ans);
        return ans;
    }
};