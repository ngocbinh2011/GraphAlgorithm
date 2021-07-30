#include<iostream>
#define MAX 100
#define INF 1000000
using namespace std;
class   dothi{
    int     n, a[MAX][MAX];
    public:
    int     s, d[MAX], truoc[MAX];
    void    readdata();
    void    init(int s);
    void    bellman_ford(int s);
};
void    dothi::readdata(){
    cin>>n>>s;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++){
            cin>>a[i][j];
            if(a[i][j]==0)  a[i][j]=INF;
        }
}
void    dothi::init(int s){
    for(int i=1; i<=n; i++){
        d[i]=a[s][i];   truoc[i]=s;
    }
    d[s]=0;
}
void    dothi::bellman_ford(int s){
    init(s);
    for(int k=1; k<=n-2; k++)
        for(int v=1; v<=n; v++)
            if(v!=s)
                for(int u=1; u<=n; u++)
                    if((a[u][v]!=INF)&&(d[u]!=INF)&&(d[v]>d[u]+a[u][v])){
                        d[v]=d[u]+a[u][v];  truoc[v]=u;
                    }
    for(int t=1; t<=n; t++)
        if(d[t]==INF)
            cout<<"\nK/c "<<s<<" -> "<<t<<" = INF;";
        else{
            cout<<"\nK/c "<<s<<" -> "<<t<<" = "<<d[t]<<";";
            cout<<"\t"<<t<<" <- ";
            int u=truoc[t];
            while(u!=s){
                cout<<u<<" <- ";
                u=truoc[u];
            }
            cout<<s;
        }
}
int main(){     dothi       g;      g.readdata();       g.bellman_ford(g.s);    }
