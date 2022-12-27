#include<iostream>
#define N 50
using namespace std;
class intstack{
	private:
		int arr[N];
	public:
		int top=-1;
		int isFull(void){
		if(top==N-1)
			return 1;
		else
			return 0;
		}
		void push(char a){
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
				return 0;
		}
		int pop(void){
			if(isEmpty()){
				return 0;
			}
			else{
				char ch=arr[top];
				top--;
				return ch;
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
};

