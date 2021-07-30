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

vector<vector<int>> adj;
vector<bool> vis;
int n, cycle_gr = 0;
int A[50][50] = {};
vector<int> ans;

void dfs(int u, int vertex){
	vis[u] = true;
	for(auto x: adj[u]){
		if(vis[x] || x == vertex) continue;
		dfs(x, vertex);
	}
}

void countVertex(int vertex){
	vis.assign(n + 1, false);
	int cycle = 0;
	FOR(i, 1, n + 1){
		if(vis[i] || i == vertex) continue;
		dfs(i, vertex);
		cycle++;
	}
	if(cycle > cycle_gr){
		ans.pb(vertex);
	}
}


void solution(){
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	cin >> n;
	adj.clear();
	adj.resize(n + 1);
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			char c; cin >> c;
			A[i][j] = c - '0';
			if(A[i][j]){
				adj[i].pb(j);
			}
		}
	}
	
	vis.assign(n + 1, false);
	for(int i=1; i<=n; i++){
		if(vis[i]) continue;
		dfs(i, 0);
		cycle_gr++;
	}
	
	FOR(i, 1, n + 1){
		countVertex(i);
	}
	
	cout << "so dinh tru: " << ans.size() << endl;
	for(auto x: ans) cout << x << " ";
	
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
