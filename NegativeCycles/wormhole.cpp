#include<bits/stdc++.h>

using namespace std;
int c, V , E;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 1e9 -7;
vector<vii> Lista(1002);

bool TieneCiclo(int source){
	vi dist(V,INF); dist[source] = 0;
	vi visitado(V,0);
	vi encola(V,0); encola[source] = 1;
	queue<int> q; q.push(source);
	while(!q.empty()){
		int u = q.front(); visitado[u]++;
		q.pop(); encola[u] = 0;
		if(visitado[u] < V){
			for(int j=0 ; j<(int)Lista[u].size(); j++){
				ii v = Lista[u][j];
				if(dist[v.first] > dist[u] + v.second){
					dist[v.first] = dist[u] + v.second;
					if(!encola[v.first]){
						q.push(v.first);
						encola[v.first] = 1;
					}
				}
			}
		}else{
			return true;
		}
	}
	return false;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> c;
	while(c--){
		cin >> V >> E;
		int u,v,w;
		for(int i=0; i<V; i++) Lista[i].clear();
		for(int i=0; i<E; i++){
			cin >> u >> v >> w;
			Lista[u].push_back(ii(v,w));
		}
		if(E < 2){cout <<"not possible\n"; continue;}
		string res = TieneCiclo(0) ? "possible" :"not possible";	
		cout << res <<"\n";
	}

	return 0;
}
