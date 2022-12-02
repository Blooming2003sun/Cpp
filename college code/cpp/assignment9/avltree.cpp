#include <iostream>
#include <stdlib.h>
using namespace std;
struct node
{
	struct node *lchild;
	int data;
	struct node *rchild;
	int height;
};
class AVL
{
	struct node *root;

public:
	node *getroot() { return root; }
	// constructor
	AVL()
	{
		root = NULL;
	}
	AVL(int x)
	{
		root = new node{NULL, x, NULL, 0};
	}
	// height
	int getheight(node *p)
	{
		int hl, hr;
		hl = p && p->lchild ? p->lchild->height : 0;
		hr = p && p->rchild ? p->rchild->height : 0;

		return hl > hr ? hl + 1 : hr + 1;
	}
	// treversal
	void inorder(void)
	{
		in_order(root);
		cout << endl;
	}
	void preorder(void)
	{
		pre_order(root);
		cout << endl;
	}
	void postorder(void)
	{
		post_order(root);
		cout << endl;
	}
	void in_order(struct node *r)
	{
		if (r == NULL)
			return;
		in_order(r->lchild);
		cout << r->data << " ";
		in_order(r->rchild);
	}
	void pre_order(struct node *r)
	{
		if (r == NULL)
			return;
		cout << r->data << " ";
		pre_order(r->lchild);
		pre_order(r->rchild);
	}
	void post_order(struct node *r)
	{
		if (r == NULL)
			return;
		post_order(r->lchild);
		post_order(r->rchild);
		cout << r->data << " ";
	}
	// search
	bool search(int key)
	{
		node *temp = root;
		while (temp != NULL)
		{
			if (temp->data == key)
				return 1;
			else if (key < temp->data)
				temp = temp->lchild;
			else if (key > temp->data)
				temp = temp->rchild;
		}
		return 0;
	}

	int getbalance(node *p)
	{
		int hl, hr;
		hl = p && p->lchild ? getheight(p->lchild) : 0;
		hr = p && p->rchild ? getheight(p->rchild): 0;

		return hl - hr;
	}
	node *leftrotate(node *x)
	{
		node *y, *temp;
		y = x->rchild;
		temp = y->lchild;
		y->lchild = x;
		x->rchild = temp;
		x->height = max(getheight(x->lchild), getheight(x->rchild)) + 1;
		y->height = max(getheight(y->lchild), getheight(y->rchild)) + 1;
		if (x == root)
			root = y;
		return y;
	}
	node *rightrotate(node *x)
	{
		node *y, *temp;
		y = x->lchild;
		temp = y->rchild;
		y->rchild = x;
		x->lchild = temp;
		x->height = max(getheight(x->lchild), getheight(x->rchild)) + 1;
		y->height = max(getheight(y->lchild), getheight(y->rchild)) + 1;
		if (x == root)
			root = y;
		return y;
	}
	node *newnode(int key)
	{
		node *ptr;
		ptr = new node;
		ptr->data = key;
		ptr->lchild = NULL;
		ptr->rchild = NULL;
		ptr->height = 0;
		return ptr;
	}
	node *insert(node * &r, int key)
	{
		if (r == NULL)
		{
			r = newnode(key);
			return r;
		}
		if (key < r->data)
			r->lchild = insert(r->lchild, key);
		else if (key > r->data)
			r->rchild = insert(r->rchild, key);
		else
			return r;

		r->height = getheight(r);
		int balance = getbalance(r);

		if (balance > 1 && key < r->lchild->data)
			return rightrotate(r);
		if (balance < -1 && key > r->rchild->data)
			return leftrotate(r);
		if (balance > 1 && key > r->lchild->data)
		{
			r->lchild = leftrotate(r->lchild);
			return rightrotate(r);
		}
		if (balance < -1 && key < r->lchild->data)
		{
			r->rchild = rightrotate(r->lchild);
			return leftrotate(r);
		}
		return r;
	}
};
int main()
{
	AVL n1;
	node *headroot = n1.getroot();
	n1.insert(headroot, 10);
	n1.insert(headroot, 20);
	n1.insert(headroot, 30);
	n1.insert(headroot, 15);
	n1.insert(headroot, 40);


	n1.pre_order(headroot);
	n1.in_order(headroot);


	return 0;
}
// int main(void)
// {
// 	AVL l1(50);
// 	node* root = l1.getroot();
// 	int option;
// 	while(1){
// 		cout<<"pre_trev(1) post_trev(2) in_trev(3) search(4) insert(8)  exit(0) : ";
// 		cin>>option;
// 		switch(option)
// 		{
// 		case 0:
// 			exit(0);
// 		case 1:
// 			l1.preorder();
// 			break;
// 		case 2:
// 			l1.postorder();
// 			break;
// 		case 3:
// 			l1.inorder();
// 			break;
// 		case 4:{
// 			int key;
// 			cout<<"enter key : ";
// 			cin>>key;
// 			l1.search(key);
// 			break;
// 			}
// 		case 8:{
// 			int data;
// 			cout<<"enter data: ";
// 			cin>>data;
// 			l1.insert(root,data);
// 			break;
// 			}

// 		default:
// 			cout<<"chose right option"<<endl;
// 			}
// 		}
// 	return 0;
// }
