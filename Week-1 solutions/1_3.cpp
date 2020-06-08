#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;


int32_t main()
{
   IOS;
   int s,n,k,j,t;
   cin >> s >> n;
   queue<pair<int, pair<int,int>>> q;
   vector<pair<int, pair<int,int>>> v(n);

   for(int i=0; i<n; i++)
   {
   	cin >> j >> k;
   	v[i]=make_pair(i, make_pair(j,k));
   }
   vector<int> a(n);
   j=0;

   while(j<n && j<s)
   {
   	q.push(v[j]);
   	j++;
   }

   t=0;

   while(!q.empty())
   {
   	int var =max(t,q.front().second.first);
   	t= var+q.front().second.second;
   	a[q.front().first]=var;
   	q.pop();

   	while(q.size()<s && j<n)
   	{
   		if(v[j].second.first <t)
   		{
   			a[j++]=-1;
   		}
   		else
   		{
   			q.push(v[j++]);
   		}
   	}
   }

   for(int i=0; i<n; i++)
   {
   	cout << a[i] << endl;
   }


   return 0;
}
 