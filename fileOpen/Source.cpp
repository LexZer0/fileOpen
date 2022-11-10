#include <iostream>
#include <fstream>
using namespace std;

void file1()
{
	int n, m, w;
	fstream a("text.txt", ios::out);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			a << i << " ";
	}
	a.close();
	fstream b;
	b.open("text.txt", ios::in);
	cin >> m;
	if (b)
	{
		for (int i = 0; i < m; i++)
		{
			b >> w;
			cout << w << " ";
		}
		b.close();
	}
	cout << endl;
}

void SumChet()
{
	int w, chet = 0;
	fstream c;
	c.open("N2.txt", ios::in);
	if (c)
	{
		for (int i = 0; c >> w; i++)
		{
			if (w % 2 == 0)
			{
				chet += w;
			}
		}
		cout << chet;
		c.close();
	}
	cout << endl;
}

void Min()
{
	int w, min = 1000;
	fstream c;
	c.open("N3.txt", ios::in);
	if (c)
	{
		for (int i = 0; c >> w; i++)
		{
			if (w > -1 && w < min)
			{
				min = w;
			}
		}
		cout << min;
		c.close();
	}
	cout << endl;
}

void polindrom()
{
	int x, x2, k = 0, l, r, a, e;
	fstream q("N4.txt", ios::out | ios::binary);
	cin >> e;
	q.write((char*)&e, sizeof(int));
	q.close();
	fstream b("N4.txt", ios::in | ios::binary);
	if (b)
	{
		b.read((char*)&x, sizeof(int));
		x2 = x;
		for (int i = 0; x > 0; i++)
		{
			x = x / 10;
			k++;
		}
		if (k == 4)
		{
			l = x2 / 100;
			r = x2 % 100;
			a = r / 10;
			r = r % 10 * 10 + a;
			if (l == r)
			{
				cout << "polindrom";
			}
			else
			{
				cout << "not";
			}
		}
		else if (k == 3)
		{
			l = x2 / 100;
			r = x2 % 10;
			if (l == r)
			{
				cout << "polindrom";
			}
			else
			{
				cout << "not";
			}
		}
		else if (k == 2)
		{
			l = x2 / 10;
			r = x2 % 10;
			if (l == r)
			{
				cout << "polindrom";
			}
			else
			{
				cout << "not";
			}
		}
		else if (k > 4)
		{
			cout << "Wrong number";
		}
		else
		{
			cout << "polindrom";
		}
	}
	b.close();
	cout << endl;
}

int main()
{
	file1();
	SumChet();
	Min();
	polindrom();
	

	return 0;
}