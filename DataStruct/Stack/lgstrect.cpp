#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {

	stack<int> position;
	stack<int> height;
	int largest = 0;

	vector<int> array;
	int N;

	cin >> N;
	for(int arr_i = 0; arr_i < N; arr_i++) {
		int temp;
		cin >> temp;
		array.push_back(temp);
	}

	for(int arr_i = 0; arr_i < N; arr_i++) {
		if(position.empty() && height.empty()) {
			position.push(arr_i);
			height.push(array[arr_i]);
		}
		else {
			if(height.top() < array[arr_i]) {
				position.push(arr_i);
				height.push(array[arr_i]);
			}
			else if(height.top() > array[arr_i]) {
				int tempLargest = height.top() * (arr_i - position.top());
                if(tempLargest > largest) largest = tempLargest;
				height.pop();
                int tempPos;
                while(!height.empty() && height.top() > array[arr_i] ) {
                    tempLargest = height.top() * (arr_i - position.top());
                    if(tempLargest > largest) largest = tempLargest;
                    height.pop();
                    tempPos = position.top();
                    position.pop();
                }
				height.push(array[arr_i]);
                position.push(tempPos);
			}
			else {}
		}
	}

	while(!height.empty()) {
		int tempLargest = height.top() * (N - position.top());
		if(tempLargest > largest) largest = tempLargest;
		height.pop();
		position.pop();	
	}

	cout << largest;
    return 0;
}


