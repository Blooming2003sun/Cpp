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
    ~LinkList()
    {
        cout<<"deleted"<<endl;
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
            insertbeg(item);
        else
        {
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = new node;
            temp = temp->next;
            temp->data = item;
            temp->next = NULL;
        }
    }
    void display(void)
    {
        if(head==NULL){
            cout<<"no element"<<endl;
            return;
        }
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
        while (p != NULL)
        {
            q = p;
            p = p->next;

            q->next = r;
            r = q;
        }
        head = r;
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
    void delbeg(void)
    {
        node*temp=head;
        head=head->next;
        delete temp;
    }
    void delend(void)
    {
        if(head->next==NULL){
            delbeg();
            return;
        }
        node*temp=head;
        while(temp->next->next!=NULL)
            temp=temp->next;
        delete temp->next;
        temp->next= NULL;
    }
    void rev_display(void)
	{
		if (head == NULL)
			cout << "no element" << endl;
        else if(head->next==NULL)
            cout<<head->data<<endl;
		else
		{
			// moving temp1 to tail;
			node *temp1 = head;
			while (temp1->next != NULL)
				temp1 = temp1->next;
			node *temp2 = head;
			do
			{
				while (temp2->next != temp1)
					temp2 = temp2->next;
				cout<<temp1->data<< " ";
				temp1=temp2;
                temp2 = head;
			}while(temp2!=temp1);
			cout<<temp2->data<<endl;
		}
	}
};
int main(void)
{

    LinkList l1;
    int option;
    while (1)
    {
        cout << "insertbeg (1) insertend (2) display (3) reverse(4) search(5) delbeg(6) delend(7) reversedisplay (8) exit(0) : " << endl;
        cin >> option;
        switch (option)
        {
        case 0:
            exit(0);
        case 1:
        {
            int data;
            cout << "enter data : ";
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
            l1.reverse();
            break;
        case 5:
        {
            int data;
            cout << " enter key: ";
            cin >> data;
            (l1.search(data)) ? (cout << "found") : (cout << "not found");
            cout << endl;
            break;
        }
        case 6:
            l1.delbeg();
            break;
        case 7:
            l1.delend();
            break;
        case 8:
            l1.rev_display();
            break;
        default:
            cout << " chose right option" << endl;
        }
    }

    return 0;
}