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

int min_diff = 1, max_diff = 3;

bool checkSafety(std::vector<int>& levels, bool is_increasing) 
{
  bool has_one_bad_level = true;
  int diff;

  int left = 0; // everything before left is a safe sequence
  int right = levels.size() - 1; // everything after right is a safe sequence

  while (left < levels.size() - 1)
  {
    diff = is_increasing ? levels[left + 1] - levels[left] : levels[left] - levels[left + 1];

    if (min_diff <= diff && diff <= max_diff) left++;
    else break;
  }

  while (right > 0)
  {
    diff = is_increasing ? levels[right] - levels[right - 1] : levels[right - 1] - levels[right];

    if (min_diff <= diff && diff <= max_diff) right--;
    else break;
  }

  // cout << is_increasing << ", " << left << ", " << right << "\n";

  if (left >= right)
  {
    // valid
    return true;
  }
  else if (left == right - 1)
  {
    if (left == 0 || right == levels.size() - 1) return true;
    
    // try removing left
    diff = is_increasing ? levels[right] - levels[left - 1] : levels[left - 1] - levels[right];

    if (min_diff <= diff && diff <= max_diff) return true;

    // try removing right
    diff = is_increasing ? levels[right + 1] - levels[left] : levels[left] - levels[right + 1];

    if (min_diff <= diff && diff <= max_diff) return true;
  }
  else if (left == right - 2)
  {
    // still possible since we have 1 bad level tolerance
    diff = is_increasing ? levels[right] - levels[left] : levels[left] - levels[right];

    if (min_diff <= diff && diff <= max_diff) return true;
  }

  // there are at least 2 bad level
  return false;
}

ll solve()
{  
  vector<int> curr;
  string line;
  ll safe = 0;

  while (std::getline(std::cin, line)) {
    curr.clear();
    
    std::stringstream ss(line);
    int number;
    while (ss >> number) {
      curr.push_back(number);
    }

    if (checkSafety(curr, true) || checkSafety(curr, false))
    {
      safe++;
    }
  }

  cout << safe << "\n";
  return safe;
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