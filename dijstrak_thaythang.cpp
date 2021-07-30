#include <iostream>
#define MAX 100
#define INF 1000000
using namespace std;
class   dothi{
    int         n, c[MAX][MAX];
    public:
    bool        chuaxet[MAX];
    int         s, truoc[MAX], d[MAX];
    void        readdata();
    void        init(int s);
    void        dijkstra(int s);
};
void    dothi::readdata(){
    cin>>n>>s;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++){
            cin>>c[i][j];
            if(c[i][j]==0)
                c[i][j]=INF;
        }
}
void    dothi::init(int s){
    for(int i=1; i<=n; i++){
        d[i]=c[s][i];
        truoc[i]=s;
        chuaxet[i]=true;
    }
    //co dinh dinh s
    d[s]=0;
    chuaxet[s]=false;
}
void    dothi::dijkstra(int s){
    //Buoc 1: Khoi tao
    init(s);
    //Buoc 2: - Co dinh 1 dinh u trong tap nhan tam thoi;   - Cap nhat cac nhan con lai theo u
    for(int i=1; i<=n; i++){
        if(chuaxet[i]==true){
            //moi lan co dinh 1 dinh trong so cac dinh co nhan tam thoi
            //tim nhan be nhat va luu vao bien du (min), dinh tuong ung voi nhan be nhat luu vao bien u
            int u=0, du=INF;
            for(int z=1; z<=n; z++)
                if((chuaxet[z]==true)&&(d[z]<du)){
                    u=z;
                    du=d[z];
                }
            if(u!=0){   //tim duoc min <-> co duong di tu s den i: co dinh dinh u
                chuaxet[u]=false;
                for(int v=1; v<=n; v++)
                    if((chuaxet[v]==true)&&(d[v]>du+c[u][v])){ //tim duoc v thoa man, cap nhat lai nhan dinh v
                        d[v]=du+c[u][v];
                        truoc[v]=u;
                    }
            }
            else{   //hay u==0: khong co duong di tu s den i
                chuaxet[i]=false;
            }
            //co dinh duoc 1 dinh
            i=0;
        }
    }
    //Ket thuc thuat toan Dijkstra; in KQ
    for(int t=1; t<=n; t++)
        if(d[t]==INF){
            cout<<"\nK/c "<<s<<" -> "<<t<<" = INF;";
        }
        else{
            cout<<"\nK/c "<<s<<" -> "<<t<<" = "<<d[t]<<";";
            cout<<"\t"<<t<<" <- ";
            int truoctmp=truoc[t];
            while(truoctmp!=s){
                cout<<truoctmp<<" <- ";
                truoctmp=truoc[truoctmp];
            }
            cout<<s;
        }
}
int main(){
    dothi   g;
    g.readdata();
    g.dijkstra(g.s);
}
