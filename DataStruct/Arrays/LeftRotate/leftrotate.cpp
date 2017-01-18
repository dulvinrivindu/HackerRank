#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node{

		int value;
		Node *next = NULL;
};

int main() {

	int digits, rotations;
    cin >> digits >> rotations;
	Node* head = new Node;
    
	for(int arr_i = 0; arr_i < digits; arr_i++){
            
			if(head->next == NULL){
			 
					cin >> head->value;
					head->next = new Node;
                
            }
			else{
					Node* temp = head;
					while(temp->next != NULL){
							temp = temp->next;
					}

					temp->next = new Node; 
       				cout << "here " << arr_i;
                    cin >> temp->value;
			}
	}

	for(int arr_i = 0; arr_i < rotations; arr_i++){

			Node* temp = head;

			while(temp->next != NULL){
				temp = temp->next;
			}

			temp->next = head;
			head = head->next;
	}

	for(int arr_i = 0; arr_i < digits; arr_i++){
	
			Node* temp = head;
            while(temp->next != NULL){
                cout << temp->value << " ";
                temp = temp->next;
            }
        
            cout << temp->value;
	}
    return 0;
}
