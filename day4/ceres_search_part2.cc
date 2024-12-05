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

bool check(vector<string>& words, int r, int c)
{
  if (r <= 0 || c <= 0 || r >= words.size() - 1 || c >= words[r].size() - 1) return false;

  // there are 4C2 = 6 possibilites
  vector<vector<int>> offset = {
    {-1, -1, 1, 1, 1, -1, -1, 1}, // M at top left, bottom left
    {-1, -1, 1, 1, -1, 1, 1, -1}, // M at top left, top right
    {1, 1, -1, -1, -1, 1, 1, -1}, // M at bottom right, top right
    {1, 1, -1, -1, 1, -1, -1, 1}, // M at bottom right, bottom left
  };

  for (const auto& d : offset)
  {
    if (words[r + d[0]][c + d[1]] == 'M' && words[r + d[2]][c + d[3]] == 'S') 
    {
      if (words[r + d[4]][c + d[5]] == 'M' && words[r + d[6]][c + d[7]] == 'S') return true;
    }
  }

  return false;
}

ll solve()
{  
  ll count = 0;
  vector<string> words;
  string line;

  while (std::getline(std::cin, line)) 
  {
    words.emplace_back(move(line));
  }

  for (int r = 0; r < words.size(); r++)
  {
    for (int c = 0; c < words[r].size(); c++)
    {
      if (words[r][c] == 'A')
      {
        if (check(words, r, c)) count++;
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