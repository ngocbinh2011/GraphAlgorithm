#include <bits/stdc++.h>

using namespace std;

#define ONLINE_JUDGE 1

string to_string(char x) {return (string) "\'" + x + "\'";}
string to_string(const string &x) {return '\"' + x + '\"';}
string to_string(const char *x) {return to_string((string) x);}
string to_string(bool x) {return x ? "true" : "false";}
template<typename T, typename V> string to_string(const pair<T, V> &x)
{return '(' + to_string(x.first) + ',' + to_string(x.second) + ')';}
template<typename T> string to_string(const T &x)
{int f = 0; string r; for (auto &i: x) r += (f++ ? "," : "") + to_string(i); return '{' + r + '}';}
void _print() {cerr << "]\n";}
template <typename T, typename... V> void _print(T t, V... v)
{cerr << to_string(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#define pb push_back
#define ll long long
#define endl '\n'
#define f first
#define s second
#define pii pair<int, int>
#define INF INT_MAX
#define LINF LLONG_MAX
#define all(vec) vec.begin(), vec.end()
#define reset(A) memset(A, 0, sizeof(A))

#ifndef ONLINE_JUDGE
#define debug(...)
#else
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#endif

int A[50][50] = {}, n, vis[50] = {}, parent[50];
bool check = false;

void inputMatrixBinary(){
	cin >> n;
	for(int i=1; i<=n; i++){
		char c;
		for(int j=1; j<=n; j++){
			cin >> c;
			A[i][j] = c - '0';
		}
	}
}

void dfs(int u, int v){
	if(check) return;
	vis[u] = true;
	if(u == v) return void(check = true);
	for(int i=1; i<=n; i++){
		if(A[u][i] && !vis[i]){
			parent[i] = u;
			dfs(i, v);
		}
	}
}


void print_road(int u){
	if(u == 0) return;
	print_road(parent[u]);
	cout << u << " ";
}


void intputMatrix(){
	cin >> n;
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cin >> A[i][j];
}



int32_t main(){	

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	inputMatrixBinary();
	
	int start, fis;
	cin >> start >> fis;
	
	dfs(start, fis);
	
	if(!check){
		cout << -1 << endl;
		return 0;
	}
	
	print_road(fis);
	
	fclose(stdin);
	fclose(stdout);
	
}

