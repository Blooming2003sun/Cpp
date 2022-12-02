#include <iostream>
using namespace std;

struct node
{
	int data;
	int exp;
	struct node *next;
};

class polynomial
{
	node *head;

public:
	polynomial()
	{
		head = NULL;
	}

	polynomial(const polynomial &p)
	{
		head = NULL;
		node *temp = p.head;
		while (temp != NULL)
		{
			addpoly(temp->data, temp->exp);
			temp = temp->next;
		}
	}

	polynomial operator=(const polynomial &p)
	{
		(*this).delpoly();
		node *temp = p.head;
		while (temp != NULL)
		{
			(*this).addpoly(temp->data, temp->exp);
			temp = temp->next;
		}
		return (*this);
	}
	void delpoly(void)
	{
		node * temp = head;
		while (temp!= NULL){
			temp=temp->next;
			delete head;
			head = temp;
		}		
	}
	void addpoly(int d, int e)
	{
		node *curr = new node, *temp = head, *prev = head;
		curr->data = d;
		curr->exp = e;
		curr->next = NULL;
		while (temp != NULL && temp->exp >= e)
		{
			prev = temp;
			temp = temp->next;
		}
		if (head == NULL)
		{
			head = curr;
			return;
		}
		if (prev->exp == e)
		{
			delete curr;
			prev->data = prev->data + d;
			return;
		}
		if (temp == head)
		{
			curr->next = head;
			head = curr;
			return;
		}
		prev->next = curr;
		curr->next = temp;
	}

	void displaypoly(void)
	{
		if (head == NULL)
		{
			cout << " no element" << endl;
			return;
		}
		else if (head->next == NULL)
		{
			printf("%dx^%d\n", head->data, head->exp);
			return;
		}
		else
		{
			struct node *temp = head;
			while (temp->next != NULL)
			{
				if (temp->next->data < 0)
					printf(" %dx^%d ", temp->data, temp->exp);
				else
					printf(" %dx^%d +", temp->data, temp->exp);
				temp = temp->next;
			}
			printf(" %dx^%d \n", temp->data, temp->exp);
		}
	}

	void sumpoly(polynomial &p1, polynomial &p2)
	{
		struct node *temp1 = p1.head, *temp2 = p2.head;
		int c, e;
		while (temp1 != NULL && temp2 != NULL)
		{
			if (temp1->exp > temp2->exp)
			{
				c = temp1->data;
				e = temp2->exp;
				temp1 = temp1->next;
			}
			else if (temp1->exp < temp2->exp)
			{
				c = temp2->data;
				e = temp2->exp;
				temp2 = temp2->next;
			}
			else
			{
				c = temp1->data + temp2->data;
				e = temp2->exp;
				temp1 = temp1->next;
				temp2 = temp2->next;
			}
			(*this).addpoly(c, e);
		}
		while (temp1 != NULL)
		{
			this->addpoly(temp1->data, temp1->exp);
			temp1 = temp1->next;
		}
		while (temp2 != NULL)
		{
			this->addpoly(temp2->data, temp2->exp);
			temp2 = temp2->next;
		}
	}

	polynomial operator+(polynomial &p)
	{
		struct node *temp1 = (*this).head, *temp2 = p.head;
		int c, e;
		polynomial r;
		while (temp1 != NULL && temp2 != NULL)
		{
			if (temp1->exp > temp2->exp)
			{
				c = temp1->data;
				e = temp2->exp;
				temp1 = temp1->next;
			}
			else if (temp1->exp < temp2->exp)
			{
				c = temp2->data;
				e = temp2->exp;
				temp2 = temp2->next;
			}
			else
			{
				c = temp1->data + temp2->data;
				e = temp2->exp;
				temp1 = temp1->next;
				temp2 = temp2->next;
			}
			r.addpoly(c, e);
		}
		while (temp1 != NULL)
		{
			r.addpoly(temp1->data, temp1->exp);
			temp1 = temp1->next;
		}
		while (temp2 != NULL)
		{
			r.addpoly(temp2->data, temp2->exp);
			temp2 = temp2->next;
		}
		return r;
	}

	polynomial operator-(polynomial &p)
	{
		struct node *temp1 = (*this).head, *temp2 = p.head;
		int c, e;
		polynomial r;
		while (temp1 != NULL && temp2 != NULL)
		{
			if (temp1->exp > temp2->exp)
			{
				c = temp1->data;
				e = temp2->exp;
				temp1 = temp1->next;
			}
			else if (temp1->exp < temp2->exp)
			{
				c = -temp2->data;
				e = temp2->exp;
				temp2 = temp2->next;
			}
			else
			{
				c = temp1->data - temp2->data;
				e = temp2->exp;
				temp1 = temp1->next;
				temp2 = temp2->next;
			}
			r.addpoly(c, e);
		}
		while (temp1 != NULL)
		{
			r.addpoly(temp1->data, temp1->exp);
			temp1 = temp1->next;
		}
		while (temp2 != NULL)
		{
			r.addpoly(-temp2->data, temp2->exp);
			temp2 = temp2->next;
		}
		return r;
	}
};
int main(void)
{
	polynomial p1, p2, p3, p4, p5;
	p1.addpoly(2, 3);
	p1.addpoly(3, 2);
	p1.addpoly(2, 4);
	p1.addpoly(2, 3);
	p1.addpoly(3, 2);
	p1.addpoly(2, 4);
	p1.displaypoly();

	p2 = p1;
	p2.displaypoly();
	p3 = p2;
	p3.displaypoly();
	p3 = p1.operator+(p2);
	p3.displaypoly();
	p4 = p1 + p2 + p3;
	p4.displaypoly();
	// p5 = p4 - p1;
	// p5.displaypoly();
	p1.addpoly(2, 4);
	p1.addpoly(2, 3);
	p1.addpoly(2, 3);
	p1.addpoly(3, 2);
	p1.addpoly(3, 2);
	p1.addpoly(2, 3);
	p1.displaypoly();

	return 0;
}
