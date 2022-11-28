#include <iostream>
using namespace std;
class LinkList
{
	struct node
	{
		int data;
		struct node *next;
	} * head;

public:
	LinkList()
	{
		head = '\0';
	}
	void insertbeg(int item)
	{
		struct node *temp = new node;
		temp->next = head;
		temp->data = item;
		head = temp;
	}
	void insertend(int item)
	{
		struct node *temp = head;
		if (temp == NULL)
		{
			insertbeg(item);
			return;
		}
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new node;
		temp = temp->next;
		temp->data = item;
		temp->next = NULL;
	}
	void display(void)
	{
		struct node *temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	void reverse(void)
	{
		struct node *p = head, *q, *r = NULL;
		if (head == NULL)
			return;
		while (p->next != NULL)
		{
			q = p;
			p = p->next;
			q->next = r;
			r = q;
		}
		head = r;
	}
	void delbeg(void)
	{
		if (head != NULL)
		{
			node *temp = head->next;
			delete head;
			head = temp;
		}
	}
	void delend(void)
	{
		if (head != NULL)
		{
			node *temp = head;
			while (temp->next->next != NULL)
				temp = temp->next;
			delete temp->next;
			temp->next = NULL;
		}
	}
	bool search(int item)
	{
		struct node *p = head;
		while (p != NULL)
		{
			if (p->data == item)
				return true;
			p = p->next;
		}
		return false;
	}
	void showheaddata(void)
	{
		if (head != NULL)
			cout << head->data << endl;
		else
			cout << " Empty ";
	}
	node *showhead(void)
	{
		return head;
	}
	void insertsrt(int item)
	{
		node *curr = new node, *temp = head, *prev;
		curr->data = item;
		while (temp != NULL && temp->data <= item)
		{
			prev = temp;
			temp = temp->next;
		}
		if (head == NULL)
		{
			head = curr;
			curr->next = NULL;
		}
		else if (temp == head)
		{
			curr->next = head;
			head = curr;
		}
		else
		{
			prev->next = curr;
			curr->next = temp;
		}
	}
	void rev_display(void)
	{
		if (head == NULL)
			cout << "no element" << endl;
		else
		{
			// moving temp1 to tail;
			node *temp1 = head;
			while (temp1->next != NULL)
				temp1 = temp1->next;
			node *temp2 = head;
			while (temp2 != temp1)
			{
				while (temp2->next != temp1)
					temp2 = temp2->next;
				cout<<temp1->data<< " ";
				temp1=temp2;
			}
			cout<<temp2->data<<endl;
		}
	}
};
