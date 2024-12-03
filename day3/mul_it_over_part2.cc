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

ll solve()
{  
  ll res = 0;
  string line;
  string mul_key = "mul(";
  string do_key = "do()";
  string dont_key = "don't()";
  bool is_do = true;

  while (std::getline(std::cin, line)) 
  {
    size_t pos = 0;

    while (true)
    {
      auto new_pos = line.find(mul_key, pos);

      if (new_pos == string::npos) break;

      // need to find the latest do/dont instruction before new_pos
      auto do_pos = line.rfind(do_key, new_pos);
      auto dont_pos = line.rfind(dont_key, new_pos);

      if (do_pos != string::npos || dont_pos != string::npos)
      {
        if (do_pos == string::npos)
        {
          is_do = false;
        }
        else if (dont_pos == string::npos)
        {
          is_do = true;
        }
        else 
        {
          is_do = do_pos > dont_pos;
        }
      }

      pos = new_pos + mul_key.size();

      if (!is_do) continue;

      // first number
      string left_num;

      while (pos < line.size() && isdigit(line[pos]))
      {
        left_num += line[pos];
        pos++;
      }

      if (left_num.empty()) continue;

      if (line[pos] != ',') continue;
      pos++;

      // second number
      string right_num;

      while (pos < line.size() && isdigit(line[pos]))
      {
        right_num += line[pos];
        pos++;
      }

       if (right_num.empty()) continue;

      if (line[pos] != ')') continue;
      
      res += stoi(left_num) * stoi(right_num);
    }
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