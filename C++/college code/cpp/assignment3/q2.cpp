#include<iostream>
#include<stdlib.h>
#define N 5
using namespace std;
class Queue{
	int arr[N];
	int front,rear;
public:
	Queue(){
		front=rear=-1;
	}
	void enque(void);
	int isFull(void);
	int isEmpty(void);
	int peek(void);
	int deque(void);
	void display(void);
};



int main(void)
{
	Queue q1,q2,q4;
	while(1)
	{
		int option;
		cout<<"enque(1) deque(2) display(3) peek(4) isFull(5) isEmpty(6) exit(0): ";
		cin>>option;
		switch(option)
		{
		case 0:
			exit(0);
		case 1:
			q1.enque();
			break;
		case 2:
			cout<<"dequed element : "<<q1.deque()<<endl;
			break;
		case 3:
			q1.display();
			break;
		case 4:
			cout<<q1.peek()<<endl;
			break;
		case 5:
			cout<<q1.isFull()<<endl;
			break;
		case 6:
			cout<<q1.isEmpty()<<endl;
			break;
		default:
			cout<<"chose right option"<<endl;
			}
	}
	return 0;
}
int Queue::isFull(void){
	if(rear==N-1)
		return 1;
	else
		return 0;
}
void Queue::enque(void){
	if(isFull()){
		cout<<"overflow"<<endl;
		return;
	}
	int a;
	cout<<"enter element: ";
	cin>>a;
	if(front==-1)front=0;
	rear++;
	arr[rear]=a;	
}
int Queue::isEmpty(void){
	if(rear==-1)
		return 1;
	else
		return 0;
}
int Queue::peek(void){
	if(!isEmpty())
		return arr[front];
	else
		return -999999;
}
int Queue::deque(void){
	if(isEmpty()){
		cout<<"ERROR:underflow"<<endl;
		return -999999;
	}
	else if(front ==rear){
		int x=arr[front];
		front=rear=-1;
		return x;
	}
	else{
		int x=arr[front];
		front++;
		return x;
	}	
}
void Queue::display(void){
	if(isEmpty())
		cout<<"Queue empty"<<endl;
	else{
		for(int i=front;i<=rear;i++)
			cout<<arr[i]<<endl;
	}
}

