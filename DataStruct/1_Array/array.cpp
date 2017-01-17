#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(){
	int n; 
	scanf("%d",&n);
	int *arr = (int*) malloc(n);

    for(int arr_i = 0; arr_i < n; arr_i++){
       scanf("%d",&arr[arr_i]);
    }

	for(int arr_i = n-1; arr_i >= 0; arr_i--){
		cout << arr[arr_i] << " ";	
	}

	free(arr);
    return 0;
}
