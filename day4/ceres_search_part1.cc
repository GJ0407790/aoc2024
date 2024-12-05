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

const map<int, pi> directions = {
  {0, {0, -1}}, // left horizontal
  {1, {0, 1}}, // right horizontal
  {2, {-1, 0}}, // up vertical
  {3, {1, 0}}, // down vertical
  {4, {-1, -1}}, // left-up diagonal
  {5, {-1, 1}}, // right-up diagonal
  {6, {1, -1}}, // left-down diagonal
  {7, {1, 1}}, // right-down diagonal
};

ll dfs(vector<string>& words, int r, int c, int idx, const string xmas, int dir)
{
  if (idx == xmas.size()) return 1; // valid
  if (r < 0 || c < 0 || r >= words.size() || c >= words[r].size() || words[r][c] != xmas[idx]) return 0;

  auto d = directions.at(dir);

  int dr = d.first;
  int dc =d.second;

  return dfs(words, r + dr, c + dc, idx + 1, xmas, dir);
}

ll dfs_helper(vector<string>& words, int r, int c, int idx, const string xmas)
{
  ll res = 0;

  for (const auto& dir_offset_pair : directions)
  {
    auto dir = dir_offset_pair.first;
    auto dr = dir_offset_pair.second.first;
    auto dc = dir_offset_pair.second.second;

    res += dfs(words, r + dr, c + dc, idx + 1, xmas, dir);
  }

  return res;
}

ll solve()
{  
  ll count = 0;
  vector<string> words;
  string line;
  string xmas = "XMAS";

  while (std::getline(std::cin, line)) 
  {
    words.emplace_back(move(line));
  }

  for (int r = 0; r < words.size(); r++)
  {
    for (int c = 0; c < words[r].size(); c++)
    {
      if (words[r][c] == xmas[0])
      {
        count += dfs_helper(words, r, c, 0, xmas);
      }
    }
  }

  cout << count << "\n";
  return count;
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