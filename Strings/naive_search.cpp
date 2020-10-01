#include<bits/stdc++.h>

using namespace std;

int main()
{
	string str, pat;
	cout << "Enter string and pattern" << endl;
	getline(cin, str);
	getline(cin, pat);
	int n = str.length();
	int m = pat.length();
//	cout << m << " " << n << endl;
	for(int i=0; i<=n-m; i++)
	{
//		cout << "i: " << i << endl;
		int j;
		for(j=0; j<m; j++)
		{//	cout << "j: " << j << " ";
			if(str[i+j]!=pat[j])
			{
				break;
			}
		}
//		cout << endl;
		if(j==m)
		{
			cout << "Pattern found at " << i << endl;
		}
	}
}
