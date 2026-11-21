#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <cmath>
#include <cassert>
#include <functional>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef vector<pair<int,int> > vii;
typedef vector<pair<ll,int> > vli;
typedef vector<pair<ll,ll> > vll;
typedef vector<pair<db,db> > vdd;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define mp make_pair
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const db PI = acos(-1);

vector<vii> adj;
int n,m;
vector<int> parent;

int dijkstra(int a, int b){

    parent[1]=1;

    vector<int> DIST(n+1,1e9);
    DIST[1]=0;

    priority_queue<pii> q;
    q.push(mp(0,1));

    while(!q.empty()){

        int dist = -q.top().first;
        int here = q.top().second; q.pop();

        for(int i=0;i<adj[here].size();i++){
            int next = adj[here][i].first;
            
            if(here==a&&next==b) continue;
            if(here==b&&next==a) continue;

            int cost = adj[here][i].second+dist;

            if(DIST[next]>cost){
                if(a==0) parent[next]=here;
                DIST[next]=cost;
                q.push(mp(-cost,next));
            }
        }
    }

    return DIST[n]==1e9?-1:DIST[n];
}

int main(){

    std::ios::sync_with_stdio(false);

    scanf("%d %d",&n,&m);

    adj.resize(n+1);
    parent.resize(n+1,-1);

    int a,b,c;
    while(m--){
        scanf("%d %d %d",&a,&b,&c);
        adj[a].pb(mp(b,c));
        adj[b].pb(mp(a,c));
    }

    int dist = dijkstra(0,0);

    int result=0;
    for(int p=n;p!=parent[p];p=parent[p]){
        int dd = dijkstra(p,parent[p]);
        if(dd==-1){
            result=-1;
            break;
        }
        result = max(result,dd-dist);
    }
    printf("%d", result);

    return 0;
}