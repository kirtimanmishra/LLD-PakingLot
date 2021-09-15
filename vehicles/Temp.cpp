#include <bits/stdc++.h>
using namespace std;

void showMap(unordered_map<int, vector<int>> &mp)
{
  for (auto it : mp)
  {
    vector<int> v = it.second;
    cout << it.first << "-> ";
    for (int i = 0; i < v.size(); i++)
      cout << v[i] << " ";
    cout << endl;
  }
}

int main()
{
  unordered_map<int, vector<int>> mp;
  mp[0] = {};
  mp[1] = {};
  mp[0].push_back(1);
  mp[0].push_back(2);

  mp[1].push_back(3);
  mp[1].push_back(4);

  cout << "printing initial map " << endl;
  showMap(mp);

  cout << "changing map " << endl;
  auto it = mp[1].begin();
  cout << "deleted element " << *it << endl;
  mp[1].erase(it);

  cout << "printing final map " << endl;
  showMap(mp);

  return 0;
}