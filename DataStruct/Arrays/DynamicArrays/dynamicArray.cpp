#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Seq{
	int *array;
	int used;
	int size;
};


void initList(Seq* inSeq, int N){
		for(int arr_i = 0; arr_i < N; arr_i++){
				(*(inSeq + arr_i)).array = (int *) malloc(1 * sizeof(int));
				(*(inSeq + arr_i)).size = 1;
				(*(inSeq + arr_i)).used = 0;
		}
}

void updateList(Seq* inList, int seq, int value){
	if(inList[seq].used >= inList[seq].size){
		inList[seq].array = (int *) realloc (inList[seq].array, sizeof(int) * (inList[seq].size + 1));
		inList[seq].size++;
		*(inList[seq].array +inList[seq].used) = value;
		inList[seq].used++;
	}	
	else{
		*(inList[seq].array +inList[seq].used) = value;
		inList[seq].used++;
	}
}
	
int main() {
   	int N;
   	int Q;
	int lastAns = 0;

	cin >> N >> Q;
	Seq* seqList = (Seq *) malloc(N * sizeof(Seq));

	initList(seqList, N);

	for(int i = 0; i < Q; i++){
			int type, x, y;

			cin >> type >> x >> y;

			if(type == 1){
					int tempSeq = ((x ^ lastAns) % N);
					updateList(seqList, tempSeq, y);
			}
			else{
					int tempSeq = ((x ^ lastAns) % N);
                    //cout << tempSeq << "temp" << endl;
                    //cout << seqList[tempSeq].used << "used";
					lastAns = (seqList[tempSeq].array [y % seqList[tempSeq].used]);
					cout << lastAns << endl;
			}
	
	}
    return 0;
}
