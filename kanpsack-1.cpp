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
    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        p.push_back({x, y});
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(w + 2, 0));

    for (ll i = n - 1; i >= 0; i--)
    {
        for (ll j = 0; j <= w; j++)
        {
            if (j == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                // taking the current the objects
                ll take = 0;
                ll notake = 0;
                if (j >= p[i].first)
                {
                    take = p[i].second + dp[i + 1][j - p[i].first];
                }
                // skipping the current object
                notake = dp[i + 1][j];
                dp[i][j] = max(take, notake);
            }
        }
    }
    cout << dp[0][w] << endl;
}
