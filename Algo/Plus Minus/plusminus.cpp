#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
    }

	int posCount = 0,negCount = 0,zeroCount =0;
	for(int arr_i = 0;arr_i < n;arr_i++){
		if(arr[arr_i]<0)
			negCount ++;
		else if(arr[arr_i]>0)
			posCount ++;
		else
			zeroCount ++;
	}

	cout << posCount/float(n) << endl << negCount/float(n) << endl << zeroCount/float(n);

    return 0;
}
