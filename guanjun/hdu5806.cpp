/* ***********************************************
Author        :guanjun
Created Time  :2016/8/7 10:02:54
File Name     :hdu5806.cpp
************************************************ */
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include <list>
#include <deque>
#include <stack>
#define ull unsigned long long
#define ll long long
#define mod 90001
#define INF 0x3f3f3f3f
#define maxn 10010
#define cle(a) memset(a,0,sizeof(a))
const ull inf = 1LL << 61;
const double eps=1e-5;
using namespace std;
priority_queue<int,vector<int>,greater<int> >pq;
struct Node{
	int x,y;
};
struct cmp{
    bool operator()(Node a,Node b){
        if(a.x==b.x) return a.y> b.y;
        return a.x>b.x;
	}
};

bool cmp(int a,int b){
    return a>b;
}
int a[200010];
int sum[200010];
int n,m,k;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int t;
	cin>>t;
	while(t--){
		scanf("%d%d%d",&n,&m,&k);
		int x;
		sum[0]=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			if(x>=m)a[i]=1;
			else a[i]=0;
			sum[i]=sum[i-1]+a[i];
		}
		ll ans=0;
		int r=1;
		for(int l=1;l<=n;l++){//枚举左端点
			while(r<=n&&sum[r]-sum[l-1]<k)r++;
			if(r>n)break;
			ans+=(n-r+1);
		}
		printf("%lld\n",ans);
	}
    return 0;
}
