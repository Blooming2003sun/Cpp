#include<iostream>
using namespace std;
class CirLinkList{
	struct node{
		int data;
		struct node * next;
	}*tail;
public:
	CirLinkList(){
	tail=NULL;
	}
	void insertbeg(int item){
		struct node*temp=new node;
		if(tail==NULL){
			temp->next=temp;
			temp->data=item;
			tail=temp;
			return;
		}
		temp->next=tail->next;
		temp->data=item;
		tail->next=temp;
	}
	void insertend(int item){
		struct node*temp=tail,*curr;
			if(tail==NULL)
				insertbeg(item);
		curr=new node;
		curr->next=tail->next;
		curr->data=item;
		tail->next=curr;
		tail=curr;	
	}
	void display(void){
		if(tail==NULL){
			cout<<"No Element"<<endl;
			return;
		}
		if(tail->next==tail){
			cout<<tail->data<<endl;
			return;
		}
		struct node*temp=tail->next;
		while(temp->next!=tail){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<temp->data<<" "<<tail->data<<endl;
	}
	void delbig(void){
		if(tail==NULL)
			cout<<"no element"<<endl;
		else if(tail->next==tail){
			delete tail;
			tail=NULL;
		}
		else{
		node *temp=tail->next;
		tail->next=temp->next;
		delete temp;
		}		
	}
	void delend(void){
		if(tail==NULL)
			cout<<"no element"<<endl;
		else if(tail->next==tail){
			delete tail;
			tail=NULL;
		}
		else{
		struct node*temp=tail->next;
		while(temp->next!=tail){
			temp=temp->next;
		}
		temp->next=tail->next;
		delete tail;
		tail=temp;
		}
	}	
};

int main(void)
{
	CirLinkList l1;
	int option;
	while(1){
		cout<<"insertbeg(1) insertend(2) display(3) delbig(4) delend(5)exit(0): ";
		cin>>option;
		switch(option)
		{
		case 0:
			exit(0);
		case 1:{
			int data;
			cout<<"enter data: ";
			cin>>data;
			l1.insertbeg(data);
			break;
			}
		case 2:
			{
			int data;
			cout<<"enter data: ";
			cin>>data;
			l1.insertend(data);
			break;
			}
		case 3:
			l1.display();
			break;
		case 4:
			l1.delbig();
			break;
		case 5:{
			l1.delend();	
			break;}
		default:
			cout<<"chose right option"<<endl;
			}
		}
	return 0;
}
temp->next
