#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

ll n, m, k; 

ll solve()
{
	cin >> n;
	vector<int> left_locs(n, 0);
	vector<int> right_locs(n, 0);

  int left_loc, right_loc;
  for (int i = 0; i < n; i++) 
  {
    cin >> left_loc;
    cin >> right_loc;

    left_locs[i] = left_loc;
    right_locs[i] = right_loc; 
  }
	
  // match the elements according to their order
  sort(left_locs.begin(), left_locs.end());
  sort(right_locs.begin(), right_locs.end());

  ll res = 0;

  for (int i = 0; i < n; i++) 
  {
    res += abs(left_locs[i] - right_locs[i]);
  } 

  cout << res << "\n";
  return res;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t = 1;
	for(int i = 1; i <= t; i++)
  {
		solve();
	}
	
	
	return 0;
}