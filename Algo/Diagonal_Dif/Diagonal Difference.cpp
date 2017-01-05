#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector< vector<int> > a(n,vector<int>(n));
    for(int a_i = 0;a_i < n;a_i++){
       for(int a_j = 0;a_j < n;a_j++){
          cin >> a[a_i][a_j];
       }
    }

	int totalDiagA = 0, totalDiagB = 0;
	for(int a_i = 0;a_i < n;a_i++){
			totalDiagA += a[a_i][a_i]; 
			totalDiagB += a[a_i][(n-a_i)-1]; 
       }
	
	cout << abs(totalDiagA - totalDiagB);
    return 0;
}
