#include <iostream>
using namespace std;
class Node{
	public:
	int data;
	Node *next;
};
void beg(Node** head,int newdata){
	Node *newnode=new Node();
	newnode->data=newdata;
	newnode->next=*head;
	*head=newnode;
}
void mid(Node *prev,int newdata){
	if(prev== NULL){
		cout<<"prev node can't be NULL";
		return;
	}
	Node *newnode=new Node();
	newnode->data=newdata;
	newnode->next=prev->next;
	prev->next=newnode;
}
void end(Node** head,int newdata){
	Node *last= *head;
	Node *newnode=new Node();
	newnode->data=newdata;
	newnode->next=NULL;
	if(*head==NULL){
		*head=newnode;
		return;
	}
	while(last->next!=NULL){
		last=last->next;
	}
	last->next=newnode;
	return;
}
void print(Node *n){
	while(n!=NULL){
		cout<<n->data<<" ";
		n=n->next;
	}
}
int main(){
	Node *head=NULL;
	beg(&head,9);

	beg(&head,6);
	end(&head,2);
	end(&head,1);
	mid(head->next,7);
	mid(head->next->next,8);
	print(head);
	return 0;
}
