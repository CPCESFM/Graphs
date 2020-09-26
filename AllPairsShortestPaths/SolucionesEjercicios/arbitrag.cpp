#include<bits/stdc++.h>

using namespace std;
int n,e,casos;
long double x;
string a, b;
const int INF = 1e8;
long double d[100][100];
long double epsilon = 1e-9;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	while(cin >> n && n!= 0){
		for(int i=0; i<n; i++){
			for(int j=0 ; j<n; j++){
				d[i][j] = -INF;
			}
		}
		int num_ver = 0;
		map<string, int> moneda;
		for(int i=0; i<n; i++){
			cin >> a;
			moneda[a] = num_ver++;
		}
		cin >> e;
		for(int i=0; i<e; i++){
			cin >> a >> x >> b;
			d[ moneda[a] ][ moneda[b] ] = log(x);
		}
		for(int k=0; k<n; k++){
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					d[i][j] = max(d[i][j],d[i][k] + d[k][j]);
				}
			}
		}
		bool se_puede = false;
		for(int i=0; i<n; i++){
			if(d[i][i] > epsilon) se_puede = true;
		}
		if(se_puede){
			printf("Case %d: Yes\n", ++casos);
		}else{
			printf("Case %d: No\n", ++casos);
		}	
	}

	return 0;
}	
