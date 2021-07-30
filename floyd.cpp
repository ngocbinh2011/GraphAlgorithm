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

#define next Next

int A[50][50] = {}, n, vis[50] = {};
int path[100] = {};
bool check = false;

int dis[50] = {}, parent[50] = {};
int d[50][50] = {}, next[50][50] = {};

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

void floyd(){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			d[i][j] = A[i][j];
			if(A[i][j] > 1005){
				next[i][j] = -1;
			}	
			else next[i][j] = j;
		}
	}
	cout << "Khoi tao " <<  " VS (d[i][j], next[i][j]) : " << endl;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++) cout << "(" << d[i][j] << ", " << next[i][j] << ") ";
			cout << endl;
		}
	cout << endl;
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(d[i][j] > d[i][k] + d[k][j]){
					d[i][j] = d[i][k] + d[k][j];
					next[i][j] = next[i][k];
				}
			}
		}
		cout << "K = " << k <<  " VS (d[i][j], next[i][j]) : " << endl;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++) cout << "(" << d[i][j] << ", " << next[i][j] << ") ";
			cout << endl;
		}
		cout << endl;
	}
}

vector<int> constructPath(int u,
                        int v)
{
    // If there's no path between
    // node u and v, simply return
    // an empty array
    if (next[u][v] == -1)
        return {};
 
    // Storing the path in a vector
    vector<int> path = { u };
    while (u != v) {
    	if(u == 0 || u == -1) break;
//    	if(u == -1 || v == -1) break;
//		cerr << u << endl;
        u = next[u][v];
        path.push_back(u);
    }
    return path;
}

void road(int u){
	if(u == -1) return;
	road(parent[u]);
	cout << u << " ";
}


void print(int u, int v){
	vector<int> path = constructPath(u, v);
	for (int i = 0; i < path.size(); i++)
        cout << path[i] << " ";
}



int32_t main(){	

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	inputMaxtrixWeight();
	output();
	
//	int start;
//	cin >> start;
	
	floyd();
	
	for(int i=1; i<=n; i-=-1){
		for(int j=1; j<=n; j++){
			cout << "road from " << i << " to " << j << ": ";
			print(i, j);
			cout << "-> dis: " << d[i][j];
			cout << endl;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	
}

