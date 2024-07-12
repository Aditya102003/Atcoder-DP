#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> arr;
    for (int i = 0; i < n; i++)
    {
        string ss;
        for (int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            ss += ch;
        }
        arr.push_back(ss);
    }

    // vector<vector<ll>> dp(n, vector<ll>(m, 0));
    // if (arr[n - 1][m - 1])
    //     == '#'
    //     {
    //     }
    vector<vector<ll>> dp(n, vector<ll>(m, 0));
    if (arr[n - 1][m - 1] == '#')
    {
        cout << 0 << endl;
    }
    else
    {

        for (int i = n - 1; i >= 0; i--)
        {

            for (int j = m - 1; j >= 0; j--)
            {
                if (i == n - 1 && j == m - 1)
                {
                    dp[i][j] = 1;
                }
                else if (arr[i][j] != '#')
                {
                    ll down = 0;
                    ll right = 0;
                    if (i + 1 < n)
                    {
                        down = dp[i + 1][j];
                    }
                    if (j + 1 < m)
                    {
                        right = dp[i][j + 1];
                    }
                    dp[i][j] = (down + right) % mod;
                }
            }
        }
        cout << dp[0][0] % mod << endl;
    }
}
