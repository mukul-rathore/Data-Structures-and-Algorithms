#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> dp;
    int solve(int n, int m, vector<vector<int>> M, int i, int j)
    {
        if (i == n || j == m || i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int right = solve(n, m, M, i, j + 1);
        int right_up = solve(n, m, M, i - 1, j + 1);
        int right_down = solve(n, m, M, i + 1, j + 1);

        int mx = max(right, max(right_up, right_down));
        dp[i][j] = max(dp[i][j], M[i][j] + mx);
        return dp[i][j];
    }
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        dp.resize(n, vector<int>(m, -1));
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            int temp = solve(n, m, M, i, 0);
            res = max(res, temp);
        }
        return res;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> M[i][j];
        }

        Solution ob;
        cout << ob.maxGold(n, m, M) << "\n";
    }
    return 0;
}