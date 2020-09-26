#include<bits/stdc++.h>

using namespace std;
int n, k,u,v,w,q;
int adjMat[400][400];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> adjMat[i][j];
		}	
	}	
	cin >> q;
	for(int z=0; z<q; z++){
		cin >> u >> v >> w;
		u--, v--;
		if(adjMat[u][v] > w){
			adjMat[u][v] = w;
			adjMat[v][u] = w;
		}
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(i!=j){
				       	adjMat[i][j] = min(adjMat[i][j], adjMat[i][u] + adjMat[u][v] + adjMat[v][j]); 
					adjMat[i][j] = min(adjMat[i][j], adjMat[i][v] + adjMat[u][v] + adjMat[u][j]);
				}
		long long int sum = 0;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(i!=j) sum += adjMat[i][j];
			}
		}
		
		cout << sum / 2   << " ";

	}
	cout << "\n";
	return 0;
}
