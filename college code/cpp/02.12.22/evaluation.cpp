#include<iostream>
#include<stdio.h>
#include"stack.cpp"
using namespace std;
char arr[50];
intstack oparand;
int isOparand(char ch)
{
	return (ch <= 57 && ch >= 48) || (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122);
}

int precedence(char ch)
{
	if (ch == '^')
		return 3;
	else if (ch == '/' || ch == '*')
		return 2;
	else if (ch == '+' || ch == '-')
		return 1;
	else
		return -1;
}
int compute(int a,int b,char x){
    switch(x){
        case '*':
            return a*b;
        case '/':
            return a/b;
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '^':
            return a^b;
    }
}
int expr[100];
//input postfix expression
//output result
int num(char x){
    return (x-48);
}
int evaluate(){
    int i=0,a,b,result;
    while(arr[i]!='\0'){
        if(arr[i]==' '){
            //ignore
        }
        else if(isOparand(arr[i])&&isOparand(arr[i+1]))
        {
            oparand.push(num(arr[i])*10 + num(arr[i+1]));
            i=i+1;
        }
        else if(isOparand(arr[i]))
            oparand.push(num(arr[i]));
        else{
            a=oparand.peek();
            oparand.pop();
            b=oparand.peek();
            oparand.pop();
            result=compute(b,a,arr[i]);
            oparand.push(result);
        }
    i=i+1;
    }
    return oparand.peek();
}
int main(void)
{
	cout << "enter postfix expression : ";
	gets(arr);
	cout<<"result is : "<<evaluate();
	return 0;
}
