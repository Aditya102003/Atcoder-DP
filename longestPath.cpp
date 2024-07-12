
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll mod = 1e9 + 7;
ll solve(vector<ll> adj[], ll node, vector<ll> &dp)
{
    ll ans = 0;
    if (dp[node] != -1)
    {
        return dp[node];
    }
    for (ll child : adj[node])
    {
        ans = max(ans, 1 + solve(adj, child, dp));
    }
    dp[node] = ans;
    return dp[node];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<ll> dp(n + 1, -1);

    vector<ll> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        dp[i] = solve(adj, i, dp);
    }
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}
