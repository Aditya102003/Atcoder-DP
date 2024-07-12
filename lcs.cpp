#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s1;
    string s2;
    cin >> s1 >> s2;
    ll n1 = s1.size();
    ll n2 = s2.size();
    string ans;
    vector<vector<ll>> dp(n1 + 1, vector<ll>(n2 + 1, 0));
    for (int i = n1 - 1; i >= 0; i--)
    {
        for (int j = n2 - 1; j >= 0; j--)
        {
            if (s1[i] == s2[j])
            {
                dp[i][j] = 1 + dp[i + 1][j + 1];
            }
            else if (s1[i] != s2[j])
            {

                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    // for (int i = 0; i < n1; i++)
    // {
    //     for (int j = 0; j < n2; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int i = 0;
    int j = 0;

    while (i < n1 && j < n2)
    {
        if (s1[i] == s2[j])
        {
            ans += s1[i];
            i++;
            j++;
        }
        else if (dp[i + 1][j] > dp[i][j + 1])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    // reverse(ans.begin(), ans.end());
    cout << ans << endl;
}
