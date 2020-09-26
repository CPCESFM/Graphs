#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> viii;
typedef vector<int> vi;
#define INF 990000

int adjMat[20][20];
int p[20][20];
int inter,z,casos,s,t;

void printPath(int i,int j){
	if(i!=j) printPath(i, p[i][j]);
	printf(" %d",j + 1);
}	

void solve(){
	memset(adjMat, INF, sizeof(adjMat));
	for(int i=0 ; i< inter; i++){
		cin >> z;
		for(int j=0; j<z; j++){
			int u=0;
			int delay=0;
			cin >> u >> delay;
			u--;
			adjMat[i][u]=delay;
		}
	}
	cin >> s >> t;
	s--;
	t--;
	for(int i=0 ; i<inter; i++){
		for(int j=0 ; j<inter; j++){
			p[i][j]=i;
		}
	}
	for(int k = 0; k < inter; k++){
		for(int i=0; i<inter; i++){
			for(int j=0; j<inter; j++){
				if(adjMat[i][k] + adjMat[k][j] < adjMat[i][j]){
					adjMat[i][j]= adjMat[i][k] + adjMat[k][j];
					p[i][j] = p[k][j];
				}
			}
		}
	}
	printf("Case %d: Path =",++casos);
	printPath(s,t);
	printf("; %d second delay\n",adjMat[s][t]);

}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	while( cin >> inter && inter !=0){
		solve();
	}	
	return 0;
}
