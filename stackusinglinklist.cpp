#include<iostream>
#include"linklist.cpp"
#include<stdlib.h>
class Stack{
	LinkList l1;
public:
	void push(int item)
	{
		l1.insertbeg(item);
	}
	void pop(void){
		if(showhead()==NULL)
			cout<<"underflow"<<endl;
		else
			l1.delbeg();
	}		
	int peek(void){
		l1.showheaddata();
	}
	int isEmpty(void){
		if(l1.showhead()==NULL)
			return 1;
		return 0;
	}
	void isFull(void){
	}
	void display(void){
		l1.display();
	}
	
};
int main(void)
{
	Stack s1;
	while(1)
	{
		int option;
		cout<<"push(1) pop(2) display(3)isEmpty(4) exit(0): ";
		cin>>option;
		switch(option)
		{
		case 0:
			exit(0);
		case 1:
			{
				int item;
				cout<<"enter item: ";
				cin>>item;
				s1.push(item);
				break;
			}
		case 2:
			s1.pop();
			break;
		case 3:
			s1.display();
			break;
		case 4:
			cout<<s1.isEmpty()<<endl;
			break;
		default:
			cout<<"chose right option"<<endl;
			}
	}
	return 0;
}
