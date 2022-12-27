#include <iostream>
#include <stdio.h>
#include "stack.cpp"
using namespace std;
char arr[50];
stack oparator;
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
char expr[100];
void infixToPost()
{
	int i = 0, j = 0;
	char x;
	while (arr[i] != '\0')
	{
		if (isOparand(arr[i]))
			expr[j++] = arr[i];
		else if (arr[i] == '(')
			oparator.push(arr[i]);
		else if (arr[i] == ')')
		{
			while (oparator.peek() != '(')
			{
				x = oparator.peek();
				expr[j++] = x;
				oparator.pop();
			}
			oparator.pop();
		}
		else
		{
			if (oparator.isEmpty())
				oparator.push(arr[i]);
			else if (oparator.peek() == '(')
				oparator.push(arr[i]);
			else if (precedence(arr[i]) > precedence(oparator.peek()))
				oparator.push(arr[i]);
			else
			{
				while (precedence(arr[i]) <= precedence(oparator.peek()))
				{
					x = oparator.peek();
					expr[j++] = x;
					oparator.pop();
				}
				oparator.push(arr[i]);
			}
		}
		i = i + 1;
	}
	while (!oparator.isEmpty())
	{
		x = oparator.peek();
		expr[j++] = x;
		oparator.pop();
	}
	expr[j] = '\0';
	printf("%s", expr);
}
int main(void)
{
	cout << "enter infix expression : ";
	gets(arr);
	infixToPost();
	return 0;
}
