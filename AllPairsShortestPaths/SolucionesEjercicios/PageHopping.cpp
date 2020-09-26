#include<bits/stdc++.h>

using namespace std;
#define INF 900000
int adjMat[102][102];
int V,a,b,u,v,casos;

int main(){
	while(cin >> a >> b && ( a!=0 && b!=0)){
		V = max(V,max(a,b));
		a--;
		b--;
		for(int i=0 ; i<102; i++){
			for(int j=0 ; j<102; j++){
				if(i!=j){
					adjMat[i][j]= INF;
				}else{
					adjMat[i][j]=0;
				}
			}
		}
		adjMat[a][b]= 1;
		while(cin >> u >> v &&( u!=0 && v!=0)){
			V = max(V, max(u,v));
			u--;
			v--;
			adjMat[u][v]=1;
		}
		/*
		for(int i=0; i<V ; i++){
			for(int j=0; j<V; j++){
				cout << adjMat[i][j] << " ";
			}
			cout << "\n";
		}
		*/
		for(int k=0 ; k < V; k++){
			for(int i=0 ; i<V; i++){
				for(int j=0 ; j<V; j++){
					adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
				}
			}
		}
		double suma=0;
		double num=0;
		for(int i=0; i<V; i++){
			for(int j=0; j<V; j++){
			//	cout << adjMat[i][j] << " ";
				if(i!=j && adjMat[i][j] != INF){
					suma += adjMat[i][j];
					num++;
				}
			}
		//	cout << "\n";
		}
		printf("Case %d: average length between pages = %0.3f clicks\n", ++casos, suma/num);
	}
	return 0;
}
