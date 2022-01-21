#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertathead(node*& head,int data){
    node* n = new node(data);
    n->next = head;
    head = n;
}

node* gettail(node* head){
    while(head->next){
        head = head->next;
    }
    return head;
}

void insertattail(node*& head, int data){
    if(!head){
        insertathead(head,data);
        return;
    }
    node* n = new node(data);
    node* tail = gettail(head);
    tail->next = n;
}

void printlinkedlist(node* head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


node* bubbleSort(node* head, int n) {

	int i = 1;
	while(i < n) {
		int j = 0; 
		node* cur = head;
		node* prev = NULL;
		node* tmp = head->next;
		while(j < n-i) {
			if(cur->data > tmp->data) {
				// swap the cur node with the tmp node
				cur->next = tmp->next;
				tmp->next = cur;
				if(prev == NULL) {
					head = tmp;
				} else {
					prev->next = tmp;
				}
				prev = tmp;
				tmp = cur->next;
			} else {
				// update the cur to point to the next node
				prev = cur;
				cur = cur->next;
				tmp = cur->next;
			}
			j++;
		}
		i++;
	}

	return head;
}


int main() {
    int n;
    cin >> n;
    node* head = NULL;

    int data;
    for(int i=0; i<n; i++){
        cin >> data;
        insertattail(head,data);
    }

    head = bubbleSort(head,n);
    printlinkedlist(head);

    return 0;
}
