#include <iostream>
using namespace std;
class DLinkList
{
	struct node
	{
		struct node *prev;
		int data;
		struct node *next;
	} * head, *tail;

public:
	DLinkList()
	{
		head = NULL;
		tail = NULL;
	}
	void insertbeg(int item)
	{
		struct node *temp = new node;
		temp->next = head;
		temp->data = item;
		temp->prev = NULL;
		if (head == NULL)
		{
			head = temp;
			tail = temp;
			return;
		}
		head->prev = temp;
		head = temp;
	}
	void insertend(int item)
	{
		struct node *temp = tail;
		if (tail == NULL)
		{
			insertbeg(item);
			return;
		}
		temp->next = new node;
		temp = temp->next;
		temp->data = item;
		temp->next = NULL;
		temp->prev = tail;
		tail = temp;
	}
	void display(void)
	{
		struct node *temp = head;
		if (head == NULL)
		{
			cout << "No Element" << endl;
			return;
		}
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	void delbig(void)
	{
		if (head == NULL)
			cout << "no element" << endl;
		else if (head->next == NULL)
		{
			delete head;
			head = tail = NULL;
		}
		else
		{
			head = head->next;
			delete head->prev;
			head->prev = NULL;
		}
	}
	void delend(void)
	{
		if (head == NULL)
			cout << "no element" << endl;
		else if (head->next == NULL)
		{
			delete head;
			head = tail = NULL;
		}
		else
		{
			tail = tail->prev;
			delete tail->next;
			tail->next = NULL;
		}
	}
};
int main(void)
{
	DLinkList l1;
	int option;
	while (1)
	{
		cout << "insertbeg(1) insertend(2) display(3) delbig(4) delend(5)exit(0): ";
		cin >> option;
		switch (option)
		{
		case 0:
			exit(0);
		case 1:
		{
			int data;
			cout << "enter data: ";
			cin >> data;
			l1.insertbeg(data);
			break;
		}
		case 2:
		{
			int data;
			cout << "enter data: ";
			cin >> data;
			l1.insertend(data);
			break;
		}
		case 3:
			l1.display();
			break;
		case 4:
			l1.delbig();
			break;
		case 5:
			l1.delend();
			break;
		default:
			cout << "chose right option" << endl;
		}
	}
	return 0;
}
