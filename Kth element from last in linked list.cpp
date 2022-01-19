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

int elementfromlast(node* head, int k){
    node* fast = head;
    while(k-- && fast){
        fast = fast->next;
    }
    node* slow = head;
    while(fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow->data;
}


int main() {

    node* head = NULL;
    int data;
    while(true){
        cin >> data;
        if(data == -1) break;
        insertattail(head,data);
    }
    int k;
    cin >> k;
    cout << elementfromlast(head,k) << endl;

    return 0;
}
