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
node* midpoint(node* head){

    if(!head) return head;

    node* slow = head;
    node* fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* merge(node* head1, node* head2){
    //base case
    if(!head1) return head2;
    if(!head2) return head1;
    
    //recursive case
    node* head = NULL;
    if(head1->data > head2->data){
        head = head2;
        node* headFromMyFriend = merge(head1, head2->next);
	    head->next = headFromMyFriend;
    }else{
        head = head1;
        node* headFromMyFriend = merge(head1->next, head2);
	    head->next = headFromMyFriend;
    }

	return head;
}

node* mergesort(node* head){
    //base case
    if(!head || !(head->next))  return head;

    //recursive case
    node* mid = midpoint(head);
    node* head1 = head;
    node* head2 = mid->next;
    mid->next = NULL;

    head1 = mergesort(head1);
    head2 = mergesort(head2);

    node* newhead = merge(head1,head2);;

    return newhead;

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

    head = mergesort(head);
    printlinkedlist(head);
    return 0;
}