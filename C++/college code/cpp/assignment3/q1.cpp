#include<iostream>
#include<stdlib.h>
#define N 5
using namespace std;
int arr[N];
int top=-1;
void push(void);
int isFull(void);
int isEmpty(void);
int peek(void);
int pop(void);
void display(void);
int main(void)
{
	while(1)
	{
		int option;
		cout<<"push(1) pop(2) display(3) peek(4) isFull(5) isEmpty(6) exit(0): ";
		cin>>option;
		switch(option)
		{
		case 0:
			exit(0);
		case 1:
			push();
			break;
		case 2:
			cout<<"popped element : "<<pop()<<endl;
			break;
		case 3:
			display();
			break;
		case 4:
			cout<<peek()<<endl;
			break;
		case 5:
			cout<<isFull()<<endl;
			break;
		case 6:
			cout<<isEmpty()<<endl;
			break;
		default:
			cout<<"chose right option"<<endl;
			}
	}
	return 0;
}
int isFull(void){
	if(top==N-1)
		return 1;
	else
	return 0;
}
void push(void){
	if(isFull()){
		cout<<"overflow"<<endl;
		return;
	}
	int a;
	cout<<"enter element: ";
	cin>>a;
	top++;
	arr[top]=a;	
}
int isEmpty(void){
	if(top==-1)
		return 1;
	else
		return 0;
}
int peek(void){
	if(!isEmpty())
		return arr[top];
	else
		return -999999;
}
int pop(void){
	if(isEmpty()){
		cout<<"ERROR:underflow"<<endl;
		return -999999;
	}
	else{
		top--;
		return arr[top+1];
	}	
}
void display(void){
	if(isEmpty())
		cout<<"stack empty"<<endl;
	else{
		for(int i=top;i>=0;i--)
			cout<<arr[i]<<endl;
	}
}

