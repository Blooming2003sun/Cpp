#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t, n;
	cin >> t;
	while (t--)
	{
		int n, c1 = 0, c2 = 0, temp, zero = 0, one = 0;
		cin >> n;
		string s;
		cin >> s;
		if (n % 2 == 0)
		{
			for (int i = 0; i < n ; i++)
			{
				if (s[i] =='0')
				{
					zero++;
				}
				else
				{
					one++;
				}
			}
			if (one==0 || zero== 0 || one ==zero)
			{
				cout <<"YES"<< "\n";
			}
			else
			{
				cout <<"NO"<< "\n";
			}
		}
		else
		{
			for (int i = 0; i < n ; i++)
			{
				if (s[i] =='0')
				{
					zero++;
				}
				else
				{
					one++;
				}
			}
			if (abs(one - zero) % 2 == 1)
			{
				cout << "YES"<< "\n";
			}
			else if(one==0 || zero == 0)
			{
			    cout<<"YES"<<endl;
			}
			else
			{
				cout << "NO"<< "\n";
			}
		}
	}
	return 0;
}

