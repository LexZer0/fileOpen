#include <iostream>
#include <fstream>
using namespace std;

void file1()
{
	int n, m, w;
	fstream a("text.txt", ios::out);
	cout << "N=";
	cin >> n;
	for (int i = 0; i < n * 2; i++)
	{
		if (i % 2 == 0)
			a << i << " ";
	}
	a.close();
	fstream b;
	b.open("text.txt", ios::in);
	cout << "Numbers output: ";
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
	cout << "Sum=";
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
	cout << "Minimal=";
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

void SumChetBinary(int a[])
{
	int w, chet = 0, q;
	fstream b;
	b.open("N4.txt", ios::out | ios::binary);
	for (int i = 0; i < 10; i++)
	{
		b.write((char*)&a[i], sizeof(int));
	}
	b.close();
	fstream c;
	c.open("N4.txt", ios::in | ios::binary);
	cout << "Sum=";
	if (c)
	{
		for (int i = 0; i < 10; i++)
		{
			c.read((char*)&w, sizeof(int));
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

void MinBinary(int a[])
{
	int w, min = 1000;
	fstream b;
	b.open("N5.txt", ios::out | ios::binary);
	for (int i = 0; i < 10; i++)
	{
		b.write((char*)&a[i], sizeof(int));
	}
	b.close();
	fstream c;
	c.open("N5.txt", ios::in | ios::binary);
	cout << "Minimal=";
	if (c)
	{
		for (int i = 0; i < 10; i++)
		{
			c.read((char*)&w, sizeof(int));
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

void vector(int a[])
{
	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		a[i] = rand() % 100;
	}
}

int main()
{
	int input;
	int a[50];
	vector(a);
	cout << "1. Task 1\n";
	cout << "2. Task 2\n";
	cout << "3. Task 3\n";
	cout << "4. Task 4\n";
	cout << "5. Task 5\n";
	cout << "6. Exit\n";
	cout << "Selection: ";
	cin >> input;
	while (input != 6)
	{
		switch (input)
		{
		case 1:
			file1();
			break;
		case 2:
			SumChet();
			break;
		case 3:
			Min();
			break;
		case 4:
			SumChetBinary(a);
			break;
		case 5:
			MinBinary(a);
			break;
		case 6:
			break;
		default:
			cout << "Error, bad input, quitting\n";
			break;
		}
		cout << endl << "Selection: ";
		cin >> input;
	}
	return 0;
}