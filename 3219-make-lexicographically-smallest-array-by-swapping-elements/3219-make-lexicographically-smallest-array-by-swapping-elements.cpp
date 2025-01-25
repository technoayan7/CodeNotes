class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int  n = nums.size();
        vector<pair<int,int>>v1; // no , position;
        for(int i=0;i<n;i++){
            v1.push_back({nums[i],i});
        }
        sort(v1.begin(),v1.end());
        set<int>st; //  for inserting position of no
        queue<int>q; // for inserting no
        st.insert(v1[0].second);
        q.push(v1[0].first);
        for(int i=1;i<n;i++){
            if(v1[i].first-v1[i-1].first<=limit){
                st.insert(v1[i].second);
                q.push(v1[i].first);
            }
            else{
                while(!q.empty()){
                    int a  = q.front();
                    int pos = *st.begin();
                    q.pop();
                    st.erase(st.begin());
                    nums[pos]=a;
                }
                st.insert(v1[i].second);
                q.push(v1[i].first);
            }
        }
         while(!q.empty()){
                    int a  = q.front();
                    int pos = *st.begin();
                    q.pop();
                    st.erase(st.begin());
                    nums[pos]=a;
                }
        

        return nums;

    }
};