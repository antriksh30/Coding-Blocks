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

void k_append(node*& head, int n, int k){
    if(!head || !(head->next) || k==0) return;

    node* tail = gettail(head);
    node* prev = NULL;
    node* cur = head;
    for(int i=0; i<n-k; i++){
        prev = cur;
        cur = cur->next;
    }
    tail->next = head;
    prev->next = NULL;
    head = cur;
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
    int k;
    cin >> k;
    k_append(head,n,k%n);
    printlinkedlist(head);

    return 0;
}
