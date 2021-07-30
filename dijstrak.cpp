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

int A[50][50] = {}, n, vis[50] = {};
int path[100] = {};
bool check = false;

int dis[50] = {}, parent[50] = {};

void inputMatrixBinary(){
	cin >> n;
	for(int i=1; i<=n; i++){
		char c;
		for(int j=1; j<=n; j++){
			cin >> c;
			if(c == ' '){
				j--;
			}
			else A[i][j] = c - '0';
		}
	}

}

void inputMaxtrixWeight(){
	cin >> n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++) cin >> A[i][j];
	}
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

#define N 123456

void dijstrak(int start){
	
	for(int i=1; i<=n; i++) dis[i] = N, parent[i] = -1;
	
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dis[start] = 0;
	pq.push({0, start});
	while(!pq.empty()){
		cout << "(distance[i], parent[i]): ";
		for(int i=1; i<=n; i++) cout << "(" << dis[i] << ", " << parent[i] << ") ";
		cout << endl;
		auto p = pq.top(); pq.pop();
		int node = p.s, price = p.f;
		if(price > dis[node]) continue;
		for(int i=1; i<=n; i++){
			if(A[node][i] > 0 && dis[node] + A[node][i] < dis[i]){
				dis[i] = dis[node] + A[node][i];
				pq.push({dis[i], i});
				parent[i] = node;
			}
		}
	}
	
}

void road(int u){
	if(u == -1) return;
	road(parent[u]);
	cout << u << " ";
}


void print(){
	for(int i=1; i<=n; i++){
		cout << "road " << i << ": "; road(i);
		cout << "-> distance: " << dis[i];
		cout << endl;
	}
}



int32_t main(){	

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	inputMaxtrixWeight();
	output();
	
	int start;
	cin >> start;
	
	dijstrak(start);
	print();
	
	fclose(stdin);
	fclose(stdout);
	
}

