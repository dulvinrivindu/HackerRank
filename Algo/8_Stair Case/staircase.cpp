#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;

	for(int cntUp = 0;cntUp < n;cntUp++){
		for(int cntSpace = 0;cntSpace < (n - cntUp - 1);cntSpace++){
			cout << " ";
		}

		for(int cntStars = 0;cntStars < (cntUp + 1);cntStars++){
			cout << "#";
		}

		cout << endl;
	}
    return 0;
}
