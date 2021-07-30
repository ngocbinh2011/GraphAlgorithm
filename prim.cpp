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
int dis[50] = {};
int parent[50] = {};

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

void inputMaxtrixWeight(){
	cin >> n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++) cin >> A[i][j];
	}
}

int findMin(){
	int min_dis = INF, node_ans = -1;
	for(int i=1; i<=n; i++){
		if(!vis[i] && dis[i] < min_dis){
			min_dis = dis[i];
			node_ans = i;
		}
	}
	return node_ans;
}

void prim(int start){

	
	for(int i=1; i<=n; i++) dis[i] = INF;
	
	dis[start] = 0;
	parent[start] = -1;
	
	for(int i=1; i<=n; i++){
		int node = findMin();
		vis[node] = true;
		for(int j=1; j<=n; j++){
			cout << "("  << dis[j] << ", " << parent[j] << ")" << " ";
		}
		cout << endl;
		for(int j=1; j<=n; j++){
			if(A[node][j] > 0 && !vis[j] && A[node][j] < dis[j]){
				dis[j] = A[node][j];
				parent[j] = node;
			}
		}
	}
	
}

void print(int start){
	cout << endl;
	int dh = 0;
	for(int i=1; i<=n; i++){
		dh += dis[i];
	}
	cout << "cay khugn co dh: " << dh << endl;
	for(int i=1; i<=n; i++){
		if(i == start) continue;
		int u = i, v = parent[i];
		if(u > v) swap(u, v);
		cout << u << " " << v << endl;	
	}
}





int32_t main(){	

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	inputMaxtrixWeight();
	output();
	
	int start;
	cin >> start;
	
	prim(start);
	print(start);
	
	fclose(stdin);
	fclose(stdout);
	
}

