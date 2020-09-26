#include<bits/stdc++.h>

using namespace std;
int V,E;
int adjMat[60][60];
const int INF = 1e8;
int casos = 0;

void solve(){
	for(int i=0; i<V; i++) 
		for(int j=0; j<V; j++) adjMat[i][j] =1e8; 
	map<string,int> direc;
	string a,b;
	int ver_num = 0;
	for(int i=0; i<E; i++){
		cin >> a >> b;
		int u,v;
		if(direc.find(a) == direc.end()){
			direc[a] = ver_num++;
			u = direc[a];
		}else{
			u = direc[a];
		}
		if(direc.find(b) == direc.end()){
			direc[b] = ver_num++;
			v = direc[b];
		}else{
			v = direc[b];
		}
		adjMat[u][v] = 1;
		adjMat[v][u] = 1;
	}
	for(int k=0; k<V; k++){
		for(int i=0; i<V; i++){
			for(int j=0; j<V; j++){
				adjMat[i][j] = min(adjMat[i][j],adjMat[i][k] + adjMat[k][j]);
			}
		}
	}
	int maximo = -1*INF;
	for(int i=0; i<V; i++){
		for(int j=0; j<V; j++){
			if( i != j) maximo = max(adjMat[i][j], maximo);
		}
	}
	if(maximo != INF){
		printf("Network %d: %d\n", ++casos, maximo);	
	}else{
		printf("Network %d: DISCONNECTED\n", ++casos);
	}

}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	while(cin >> V >> E && (V!= 0 && E!=0)){
		solve();
		cout << "\n";
	}

	return 0;
}
