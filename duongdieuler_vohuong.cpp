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
int deg_add[50] = {}, deg_sub[50] = {}, deg[50] = {};

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

void dfs(int u){
	vis[u] = true;
	for(int i=1; i<=n; i++){
		if(A[u][i] && !vis[i]){
			dfs(i);
		}
	}
}

void count_deg(){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			deg[i] += A[i][j];
		}	
	}
}


int check_euler_no_directed(){
	
	dfs(1);
	for(int i=1; i<=n; i++) if(!vis[i]) return -1;
	
	count_deg();
	int count = 0;
	for(int i=1; i<=n; i++){
		if(deg[i] & 1) count++;
	}
	
	if(count > 2) return -1;
	if(count > 0) return 0;
	return 1;
}

void print(stack<int> stc){
	vector<int> v;
	while(!stc.empty()){
		v.push_back(stc.top());
		stc.pop();
	}
	for(int i=v.size() - 1; i>=0; i--) cout << v[i] << " ";
	cout << endl;

}

void euler(int u){
	vector<int> path;
	stack<int> stc;
	stc.push(u);
	while(!stc.empty()){
		print(stc);
		int node = stc.top();
		bool oke = true;
		for(int i=1; i<=n; i++){
			if(A[node][i]){
				A[node][i] = 0;
				A[i][node] = 0;
				oke = false;
				stc.push(i);
				break;
			}
		}
		if(oke){
			path.pb(node);
			stc.pop();
		}
	}
	
	cout << "duong di euler: ";
	for(int i=path.size() - 1; i>=0; i--) cout << path[i] << " ";
	cout << endl;
	
}






void intputMatrix(){
	cin >> n;
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cin >> A[i][j];
}



int32_t main(){	

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	inputMatrixBinary();
	output();
	
	int start, fis;
	cin >> start;
	
	int check = check_euler_no_directed();
	if(check == -1){
		cout << -1 << endl;
		return 0;
	}
	
	if(check == 0){
		euler(start);
	}
	
	fclose(stdin);
	fclose(stdout);
	
}

