#include<iostream>
using namespace std;
//wrapper
int factorial(int);
//non tail recursion
int rec_factorial(int,int);
int main(void){
	int n;
	cout<<"enter a number"<<endl;
	cin>>n; 
	cout<<factorial(n);	
	return 0;
}
int factorial(int n){
	return rec_factorial(n,1);
}
int rec_factorial(int n,int b){
	if (n==0)return b;
	else return rec_factorial(n-1,n*b);
}

