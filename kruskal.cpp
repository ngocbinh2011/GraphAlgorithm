#include <iostream>
#define MAX 100
using namespace std;
struct  edge{
    int     h, id, n1, n2;
};
class   dothi{
    int         n, a[MAX][MAX], ne, atree[MAX][MAX], dh;
    edge        edgelist[MAX], edgetree[MAX];
    public:
    bool        chuaxet[MAX];
    void        readdata();
    void        init();
    void        bubblesort();
    void        dfs(int u);
    void        kruskal();
};
void    dothi::readdata(){
    ne=0;   cin >> n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++){    cin >> a[i][j];
            if((a[i][j]>0)&&(j>i)){ ne++;   edgelist[ne].h=a[i][j]; edgelist[ne].id=ne;
                                            edgelist[ne].n1=i;      edgelist[ne].n2=j;  }   }
}
void    dothi::init(){  for(int i=1; i<=n; i++) chuaxet[i]=true;    }
void    dothi::bubblesort(){
    edge    tmp;
    for(int i=1; i<=ne; i++)
        for(int j=ne; j>=i+1; j--){
            if(edgelist[j].h<edgelist[j-1].h){
                tmp=edgelist[j-1]; edgelist[j-1]=edgelist[j]; edgelist[j]=tmp; }
        }
}
void    dothi::dfs(int u){
    chuaxet[u]=false;
    for(int v=1; v<=n; v++)
        if((atree[u][v]==1)&&(chuaxet[v]==true)) dfs(v);
}
void    dothi::kruskal(){
    int net=0;  dh=0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)    atree[i][j]=0;
    bubblesort();
    for(int i=1; i<=ne; i++){
        init(); int tmpn1=edgelist[i].n1;   int tmpn2=edgelist[i].n2;   dfs(tmpn1);
        cout << tmpn1 << " " << tmpn2 << " " << (chuaxet[tmpn2]? "OK" : "TAO CHU TRINH") << endl;
            if(chuaxet[tmpn2]==true){
                atree[tmpn1][tmpn2]=1;          atree[tmpn2][tmpn1]=1;
                net++;  edgetree[net].n1=tmpn1; edgetree[net].n2=tmpn2;
                dh += edgelist[i].h;
            }
    }
    cout << "\nanswer cay khung kruskal dH = " << dh << endl;
    for(int i=1; i<=net; i++)   cout << edgetree[i].n1 << "  " << edgetree[i].n2 << endl;
}
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    dothi       g;      g.readdata();   g.kruskal();
}
