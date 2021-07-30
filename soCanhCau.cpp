// <><> NEVER GIVE UP <><> 
// design by CAN NGOC BINH

#include<bits/stdc++.h>
using namespace std;


#define pb push_back
#define ll long long
#define endl '\n'
#define mp make_pair
#define mt make_tuple
#define f first
#define s second
#define eb emplace_back
#define pii pair<int, int>
#define INF INT_MAX
#define LINF LLONG_MAX
#define all(vec) vec.begin(), vec.end()
#define FILEINPUT freopen("inputCNB.txt", "r", stdin);
#define FILEOUTPUT freopen("ouputCNB.txt", "w", stdout);
#define FOR(i, m, n) for(int i=(int)m; i<(int)n; i++)
#define FORD(i, m, n) for(int i=(int)m; i>=(int)n; i--)
#define FastIO cin.tie(0); ios_base::sync_with_stdio(false); cout.tie(0);
#define pq_max priority_queue<int>
#define pq_min priority_queue<int, vector<int>, greater<int>>
#define reset(A) memset(A, 0, sizeof(A))
/******* LIBRARY and DEFINE *******/


template<typename A, typename B> 
ostream& operator << (ostream &os, const pair<A, B> &p){
return os << "(" << p.f << " " << p.s << ")";};

template<typename T>
ostream& operator << (ostream &os, const vector<T> &vec){
os << "VECTOR: "; for(auto ele: vec) os << ele << " "; return os;};
/********** TEMPLATES *********/


const int MAXN = 1e7 + 5;
const ll mod = (ll)1e9 + 7;
/********** CONSTANT *********/

vector<pii> edge;
vector<bool> vis;
int n, cycleGraph;
vector<pii> ans;
int A[50][50] = {};

//void dfs(vector<vector<int>> adj, int u){
//	vis[u] = true;
//	for(auto x: adj[u]){
//		if(!vis[x]) dfs(adj, x);
//	}
//}

void bfs(vector<vector<int>> adj, int u){
	queue<int> q;
	q.push(u);
	vis[u] = true;
	while(!q.empty()){
		int node = q.front(); q.pop();
		for(auto x: adj[node]){
			if(vis[x]) continue;
			vis[x] = true;
			q.push(x);
		}
	}
}

int countCycle(vector<vector<int>> adj){
	int cycle = 0;
	FOR(i, 1, n + 1){
		if(vis[i]) continue;
		bfs(adj, i);
		cycle++;
	}
	return cycle;
}

void output(){
	cout << "mang ban dau: " << endl;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "---------RUN--------" << endl;
}


void isEdge(int num_edge){
	vector<vector<int>> adj(n + 1);
	
	FOR(i, 0, edge.size()){
		if(i == num_edge) continue;
		int x = edge[i].f, y = edge[i].s;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	
	int cycle = countCycle(adj);
	if(cycle > cycleGraph){
		int x = edge[num_edge].f, y = edge[num_edge].s;
		if(x > y) swap(x, y);
		ans.eb(x, y);
	}
}


void solution(){
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n;
	vis.assign(n + 1, false);
	vector<vector<int>> v(n + 1);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			char c; cin >> c;
			A[i][j] = c - '0';
			if(A[i][j]){
				if(i < j) edge.pb({i, j});
				v[i].pb(j);
			}
		}
	}
	
	output();
	
	cycleGraph = countCycle(v);
	
	
	FOR(i, 0, edge.size()){
		vis.assign(n + 1, false);
		isEdge(i);
	}
//	
	cout << "so canh cau: " << ans.size() << endl;
	sort(all(ans));
	for(auto p: ans) cout << p.f << " " << p.s << endl;
	cout << endl;
}



/*******************************/
		
/******** MAIN FUNCTION *********/
int main(){
	
	#ifdef NGOCBINH
		FILEINPUT;
		FILEOUTPUT;
	#endif
	
	FastIO;
	
	int test = 1;	
//	cin >> test; cin.ignore();	

	while(test--) solution();
	
	return 0;	
}
/********** I'mAlone ***********/
