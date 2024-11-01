class Solution
{
private:
    const int MOD = 1e9 + 7;

public:
    int lengthAfterTransformations(string s, int t)
    {
        vector<long long> brr(26, 0);

        for (char c : s)
        {
            brr[c - 'a']++;
        }

        for (int i = 0; i < t; i++)
        {
            vector<long long> arr(26, 0);
            for (int j = 0; j < 26; j++)
            {
                if (brr[j] == 0)
                    continue;

                if (j == 25) //For Z
                {
                    arr[0] = (arr[0] + brr[j]) % MOD;
                    arr[1] = (arr[1] + brr[j]) % MOD;
                }
                else
                {
                    arr[j + 1] = (arr[j + 1] + brr[j]) % MOD;
                }
            }
            brr = arr;
        }

        long long len = 0;
        for (long long c : brr)
        {
            len = (len + c) % MOD;
        }

        return len;
    }
};