//PAth compression
int find(int u){
        if(par[u]==u){
            return u;
        }
        return par[u]=find(par[u]);
    }
    //union by rank
    void unionf(int u,int v){
        int par1=find(u),par2=find(v);
        if(par1==par2){
            return;
        }
        if(size[par1]>=size[par2]){
            par[par2]=par1;
            size[par1]+=size[par2];
        }
        else{
            par[par1]=par2;
            size[par2]+=par1;
        }
        return;
    }
