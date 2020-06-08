#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;

vector<vector<int>> adj(N);

int tree_height(int r)
{
	if(adj[r].size()==0)
		return 1;
	else
	{
		int height=0;

		for(int i=0; i< adj[r].size(); i++)
		{
			int j= adj[r][i];
			height=max(height, tree_height(j));
		}

		return height+1;
	}
}


int32_t main()
{
   IOS;
   int n;
   cin >> n;
   int a[n];
   int root;

   for(int i=0; i<n; i++)
   {
   	cin >> a[i];

   	if(a[i]==-1)
   		root=i;
   	else
   		adj[a[i]].push_back(i);
   }

   cout << tree_height(root) << endl;


   return 0;
}
 