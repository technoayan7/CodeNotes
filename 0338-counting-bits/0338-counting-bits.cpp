class Solution
{
public:
	int countSetBits(int n)
	{
		int count = 0;
		while (n)
		{
			n &= (n - 1);
			count++;
		}
		return count;
	}
	vector<int> countBits(int n)
	{
        vector<int> ans;
        int c=0;
        for(int i=0;i<=n;i++)
        {
            c = countSetBits(i);
            ans.push_back(c);
        }
        return ans;
	}
};