class Solution
{
public:
    vector<int> getFinalState(vector<int> &arr, int k, int mult)
    {
        int n = arr.size();
        for (int i = 0; i < k; ++i)
        {
            int ind = 0;
            for (int j = 1; j < n; ++j)
            {
                if (arr[j] < arr[ind])
                {
                    ind = j;
                }
            }
            arr[ind] *= mult;
        }
        return arr;
    }
};