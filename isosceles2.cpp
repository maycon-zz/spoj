#include <iostream>
#include <algorithm>

using namespace std;
typedef long long num;

inline num pow(num a){
	return a*a;
}

inline num comb(num a){
	return a*(a-1)/2;
}

int main(){
	int n;
	cin>>n;
	num pts[1000][2];
	num dist[1000][1000];

	while(n){
		int is = 0;
		for(int c = 0; c<n; c++){
			cin>>pts[c][0]>>pts[c][1];
			dist[c][c] = 0;
			for(int k = 0; k<c;k++){
				dist[c][k] = pow(pts[c][0]-pts[k][0])+pow(pts[c][1]-pts[k][1]);
				dist[k][c] = dist[c][k];
			}
		}

		for(int c = 0; c<n; c++)
			sort(&dist[c][0],&dist[c][n]);

		for(int i = 0; i<n; i++){
			num ant = dist[i][0];
			int ac = 1;
			for(int j = 1; j<n;j++){
				if(dist[i][j]!=ant){
					is+=comb(ac);
					ant = dist[i][j];
					ac = 0;
				}

				ac+=1;
			}
			is+=comb(ac);           
		}

		cout<<is<<endl;
		cin>>n;
	}
}

