#include<bits/stdc++.h>

/*
 *
 *Tiene un detalle que no me da AC pero ya no veo porque:(
 *
 *
 */



using namespace std;
typedef pair<int,int> ii;
const int INF = 1e9 - 7;
vector<vector<pair<int,int>>> adjList(102);
vector<int> dist(102, INF);
vector<bool> visitado(102);
int n, aux, k;


bool alcanzable(int source){
	visitado[source] = true;
	for(int i=0; i<(int)adjList[source].size(); i++){
		pair<int,int> v = adjList[source][i];
		if(v.first == n -1) return true;
		if(!visitado[v.first] && alcanzable(v.first )){
			return true;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(cin >> n && n!= -1){
		vector<int> w(n);
		queue<ii> aristas;
		dist = vector<int>(102,INF);
		for(int i=0; i<n ; i++){
			adjList[i].clear();
			cin >> w[i] >> k;
			w[i] *= -1;
			for(int j=0; j<k; j++){
				cin >> aux;
				aux--;
				aristas.push(ii(i,aux));
			}
		}
		while(!aristas.empty()){
			ii nodo = aristas.front(); aristas.pop();
			adjList[nodo.first].push_back(ii(nodo.second,w[nodo.second]));
		}
		dist[0] = -100;
		for(int i=0; i< n - 1; i++){
			for(int u=0; u<n; u++){
				for(int j = 0; j<(int)adjList[u].size(); j++){
					ii v = adjList[u][j];
					if(dist[u] + v.second < 0){
						dist[v.first] = min(dist[v.first],dist[u] + v.second);
					}	
				}
			}
		}
		bool respuesta = false;
		if(dist[n - 1] <= 0){
			printf("winnable\n");
		}else{
			for(int u = 0; u<n; u++){
				for(int j=0; j<(int)adjList[u].size(); j++){
					ii v = adjList[u][j];
					if( (dist[u] + v.second < 0) && (dist[u] + v.second < dist[v.first])){
						visitado.clear();
						if(alcanzable(u)){
							respuesta = true;
						}
					}
				}
			}
			if(respuesta){
				printf("winnable\n");
			}else{
				printf("hopeless\n");
			}
		}
	}
	cout <<"\n";
	return 0;
}
