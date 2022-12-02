#include<iostream>
#include<stdlib.h>
#include<climits>
using namespace std;
struct node{;
	struct node*lchild;
	int data;
	struct node*rchild;
};
class BST{
	struct node*root;
public:
	BST(){
	root=NULL;
	}
	BST(int x){
	root=new node{NULL,x,NULL};
	}
	void inorder(void){
		in_order(root);
		cout<<endl;
	}
	void preorder(void){
		pre_order(root);
		cout<<endl;
	}
	void postorder(void){
		post_order(root);
		cout<<endl;
	}
	void in_order(struct node*r){
		if(r==NULL)return;
		in_order(r->lchild);
		cout<<r->data<<" ";
		in_order(r->rchild);
	
	}
	void pre_order(struct node*r){
		if(r==NULL)return;
		cout<<r->data<<" ";
		pre_order(r->lchild);
		pre_order(r->rchild);
	
	}
	void post_order(struct node*r){
		if(r==NULL)return;
		post_order(r->lchild);
		post_order(r->rchild);
		cout<<r->data<<" ";	
	}
	void delnode(int x){
		struct node * temp=root, * parent=NULL;
		while(temp!=NULL && temp->data != x){
			if(x>temp->data)
				temp=temp->rchild;
			else
				temp=temp->lchild;
		}
		if(temp==NULL){
			cout<<"NOT FOUND\n";
			return;
		}
		if(temp->lchild==NULL||temp->rchild==NULL){
			struct node*ptr=NULL;
			if(temp->lchild==NULL)
				ptr=temp->rchild;
			else
				ptr=temp->lchild;
			if(parent==NULL)
				root=ptr;
			else{
				if(temp==parent->lchild)
					parent->rchild=ptr;
				else
					parent->lchild=ptr;
				}
			delete temp;
		}
		else{
			struct node * succ=temp->rchild,*psucc=NULL;
			while(succ->lchild!=NULL){
			psucc=succ;
			succ=succ->lchild;
			}
			temp->data=succ->data;
			if(psucc==NULL)
				temp->lchild=succ->rchild;
			else
				psucc->lchild=succ->rchild; 
			delete succ;
		}
		
	}
	int tot_node(struct node * r){
		if(r==NULL)return 0;
		return tot_node(r->lchild) + tot_node(r->rchild)+1;
	}
	int tot_i_node(struct node * r){
		if(r==NULL)return 0;
		if(r->lchild ==NULL && r-> rchild == NULL)return 0;
		else 
			return (tot_i_node(r->lchild)+tot_i_node(r->rchild)+1);
	}
	int tot_x_node(struct node * r){
		if(r==NULL)return 0;
		if(r->lchild ==NULL && r-> rchild == NULL)return 1;
		else 
			return (tot_x_node(r->lchild)+tot_x_node(r->rchild));
	}
	int _height(struct node* r){
		if(r==NULL)
			return 0;
		else{
			int hl=_height(r->lchild);
			int hr=_height(r->rchild);
			return hl>hr?hl+1:hr+1;		
		}
	}
	bool search(int key){
		node* temp=root;
		while(temp!=NULL){
		if(temp->data==key)
			return 1;
		else if(key<temp->data)
			temp=temp->lchild;
		else if(key>temp->data)
			temp=temp->rchild;
		}
		return 0;
	}
	void insert(int data){
		if(root==NULL){
			root=new node{NULL,data,NULL};
			return;
		}
		else
		{
			node * curr=new node{NULL,data,NULL};
			node * temp=root,*parent=NULL;
			while(temp!=NULL){
				parent=temp;
				if(data==temp->data)
					return;
				else if(data<temp->data){
					temp=temp->lchild;
				}
				else if(data>temp->data){
					temp=temp->rchild;
				}		
			}
			if(parent->data>data)
				parent->lchild=curr;
			else
				parent->rchild=curr;
		}
	}
	int _smallest(struct node*r){
		node*temp=root;
		if(r==NULL){
			cout<<"NO NODE"<<endl;
			return INT_MAX;
			}
		else
		{
			while(temp->lchild=NULL)
				temp=temp->lchild;
		}
		return temp->data;
	}
	int _largest(struct node*r){
		if(r==NULL)
			return INT_MIN;
		if(r->rchild==NULL)
			return r->data;
		else return _largest(r->rchild);
	}
	int largest(){
		_largest(root);
	}
	int smallest(){
		_smallest(root);
	}
	int totalnode(){
		tot_node(root);		
	}
	int totalinternalnode(){
		tot_i_node(root);
	}
	int totalexternalnode(){
		tot_x_node(root);		
	}
		
};
int main(void)
{
	BST l1;
	int option;
	while(1){
		cout<<"pre_trev(1) post_trev(2) in_trev(3) search(4) \ntotalnode(5)totalInternode(6)totalXternode(7) \n insert(8) delete(9) largest(10) smallest(11)\nexit(0)\n";
		cin>>option;
		switch(option)
		{
		case 0:
			exit(0);
		case 1:
			l1.preorder();
		case 2:
			l1.postorder();
		case 3:
			l1.inorder();
			break;
		case 4:{
			int key;
			cout<<"enter key : ";
			cin>>key;
			l1.search(key);
			break;
			}
		case 5:{
			cout<<"total node : "<<l1.totalnode()<<endl;
			break;
			}
		case 6:{
			cout<<"total internal node : "<<l1.totalinternalnode()<<endl;
			break;
			}
		case 7:{
			cout<<"total external node : "<<l1.totalexternalnode()<<endl;
			break;
			}
		case 8:{
			int data;
			cout<<"enter data: ";
			cin>>data;
			l1.insert(data);
			break;
			}
		case 9:{
			int data;
			cout<<"enter data to delete : ";
			cin>>data;
			l1.delnode(data);
			break;
			}
		case 10:{
			cout<<"largest data : "<<l1.largest()<<endl;
			break;
			}
		case 11:{
			cout<<"smallest data : "<<l1.smallest()<<endl;
			break;
			}
		
		default:
			cout<<"chose right option"<<endl;
			}
		}
	return 0;
}
