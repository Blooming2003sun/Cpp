#include<iostream>
using namespace std;
//wrapper
int fibonacci(int);
//non tail recursion
int rec_fibonacci(int,int,int);
int main(void){
	int n;
	cout<<"enter a number"<<endl;
	cin>>n; 
	cout<<fibonacci(n);	
	return 0;
}
int fibonacci(int n){
	return rec_fibonacci(n-1,0,1);
}
int rec_fibonacci(int n,int a,int b){
	if (n==0)return a;
	else if(n==1)return b;
	else return rec_fibonacci(n-1,b,a+b);
}

