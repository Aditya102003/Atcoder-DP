#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, w;
    cin >> n >> w;
    ll sum = 0;
    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        p.push_back({x, y});
        sum += y;
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(sum + 1, 1e15));
    for (ll i = n - 1; i >= 0; i--)
    {
        for (ll j = 0; j <= sum; j++)
        {
            if (j == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                ll pick = 1e15;
                if (j >= p[i].second)
                {
                    pick = p[i].first + dp[i + 1][j - p[i].second];
                }
                ll notpick = dp[i + 1][j];

                dp[i][j] = min(pick, notpick);
            }
        }
    }
    ll ans = 0;
    for (int i = sum; i >= 0; i--)
    {
        if (dp[0][i] <= w)
        {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}
