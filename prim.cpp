typedef long long ll;
typedef pair<ll,ll > pll;
#define fi first
#define se second
void prim(vector<vector<pll > > &adj){
    priority_queue<pll,vector<pll >, greater<pll > > pq;
    ll n=adj.size();
    vector<ll > vis(n,0);
    pq.push({0,0});
    ll ans=0;
    while(!pq.empty()){
        auto pr=pq.top();
        pq.pop();
        ll u=pr.se;
        if(vis[u]){
            continue;
        }
        ans=ans+pr.fi
        vis[u]=1;
        for(auto temp:adj[u]){
            ll w=temp.se,v=temp.fi;
            if(!vis[v]){
                pq.push(w,v);
            }
        }
    }
    return ans;
}
