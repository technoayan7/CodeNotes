class Solution {
public:
    vector<string> letterCombinations(string s) {
        if(s.size()<1) return vector<string>();
		vector<string> res;
        res.push_back("");
        unordered_map<char,string> mp;
        mp.insert({'0',"abc"});
        mp.insert({'2',"abc"});
        mp.insert({'3',"def"});
        mp.insert({'4',"ghi"});
        mp.insert({'5',"jkl"});
        mp.insert({'6',"mno"});
        mp.insert({'7',"pqrs"});
        mp.insert({'8',"tuv"});
        mp.insert({'9',"wxyz"});
        for(auto x: s){
            vector<string> tmp;
            for(auto prev:res){
                for(auto ch:mp[x]){
                    tmp.push_back(prev+ch);
                }
            }
            res=tmp;
        }
        return res;
        
    }
};