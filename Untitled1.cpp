#include <iostream>
#define MAX 100
using namespace std;
struct  edg{    int h, id, n1, n2; };
class   dothi{
    int         n, a[MAX][MAX], ne, atree[MAX][MAX], dH;
    edg         graph[MAX], tree[MAX];
    public:
    int         stree;
    bool        chuaxet[MAX];
    void        readdata();
    void        init();
    void        dfstree(int u);
    void        bubblesort();
    void        prim(int s);
};
void    dothi::readdata(){
    cin>>n>>stree;  ne=0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++){
            cin>>a[i][j];
            if((a[i][j]>0)&&(i<j)){
                ne++; graph[ne].h=a[i][j]; graph[ne].n1=i; graph[ne].n2=j;
            }
        }
}
void    dothi::init(){ for(int i=1; i<=n; i++) chuaxet[i]=true; }
void    dothi::dfstree(int u){
    chuaxet[u]=false;
    for(int i=1; i<=n; i++)
        if((atree[u][i]==1)&&(chuaxet[i]==1)) dfstree(i);
}
void    dothi::bubblesort(){
    for(int i=1; i<ne; i++)
        for(int j=ne; j>=i+1; j--){
            if(graph[j].h<graph[j-1].h) swap(graph[j],graph[j-1]);
        }
}
void    dothi::prim(int s){
    int net=0;  dH=0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) atree[i][j]=atree[j][i]=0;
    bubblesort();
    while(net!=n-1){
        for(int i=1; i<=ne; i++){   //moi lan xet 1 canh tu trong so be nhat
            init(); dfstree(stree); int n1=graph[i].n1, n2=graph[i].n2;
            if(((chuaxet[n1]&&chuaxet[n2])==false)&&
               ((chuaxet[n1]||chuaxet[n2])==true)){
                   net++; dH+=graph[i].h; tree[net].n1=n1; tree[net].n2=n2;
                   atree[n1][n2]=atree[n2][n1]=1; //break;
               }
        }
        if(connected==0)    return;
    }
    cout<<"dH = "<<dH<<endl;
    for(int i=1; i<=net; i++){ cout<<tree[i].n1<<"   "<<tree[i].n2<<endl; }
}
int main(){ dothi       g;      g.readdata();       g.prim(g.stree);    }
