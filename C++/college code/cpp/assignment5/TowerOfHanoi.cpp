// #include <iostream>
// using namespace std;
// void TOH(int n, char src, char aux, char dest)
// {
// 	if (n == 1)
// 	{
// 		cout << "Move " << n << " th disk from " << src << " to " << dest << endl;
// 	}
// 	else
// 	{
// 		TOH(n - 1, src, dest, aux);
// 		cout << "Move " << n << " th disk from " << src << " to " << dest << endl;
// 		TOH(n - 1, aux, src, dest);
// 	}
// }
// int main()
// {
// 	int n;
// 	cin >> n;
// 	TOH(n, 'A', 'B', 'C');
// 	return 0;
// }

#include <iostream>
using namespace std;
void TOH(int n, char src, char aux, char dest)
{
	if (n == 1)
	{
		cout <<  src << " -> " << dest << endl;
	}
	else
	{
		TOH(n - 1, src, dest, aux);
		cout <<  src << " -> " << dest << endl;
		TOH(n - 1, aux, src, dest);
	}
}
int main()
{
	int n;
	cin >> n;
	TOH(n, 'A', 'B', 'C');
	return 0;
}
