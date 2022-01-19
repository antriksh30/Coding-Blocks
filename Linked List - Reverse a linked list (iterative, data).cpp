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

void insertattail(node*& head,int data){
    if(!head){
        insertathead(head,data);
        return;
    }
    node* tail = gettail(head);
    node* n = new node(data);
    tail->next = n;
}

void printlinkedlist(node* head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

node* reverselist(node* head){
    node* prev = NULL;
    node* cur = head;
    while(cur){
        node* tmp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = tmp;
    }
    return prev;
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
    head = reverselist(head);
    printlinkedlist(head);
    return 0;
}
