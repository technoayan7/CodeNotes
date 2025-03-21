class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<bool> isDone(recipes.size(), false);
        
        unordered_map<string, int> mp;
        for (const string& s : supplies) {
            mp[s] = 1;
        }

        bool crafted = true;
        
        while (crafted) {
            crafted = false;
            
            for (int i = 0; i < recipes.size(); ++i) {
                if (isDone[i]) continue;

                int num = 0;
                for (const string& ing : ingredients[i]) {
                    if (mp[ing] == 1) num++;
                }

                if (num == ingredients[i].size()) {
                    mp[recipes[i]] = 1;
                    isDone[i] = true;
                    crafted = true;
                }
            }
        }

        vector<string> result;
        for (int i = 0; i < recipes.size(); ++i) {
            if (isDone[i]) {
                result.push_back(recipes[i]);
            }
        }

        return result;
    }
};