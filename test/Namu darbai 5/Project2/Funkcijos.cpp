#include "Funkcijos.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;
int A[256][256];
int a, b = 0;
int c, d = 0;
int n = 0;
int m = 0;
int o = 0;
string u = "";
ofstream fs("rez.txt");
void skait(int A[][256], int &e, int &f)
{
	ifstream fd("data.txt");
	fd >> c >> d;
	while (a < d)
	{
		while (b < c)
		{
			fd >> n;
			A[a][b] = n;
			b++;
		}
		b = 0;
		a++;
	}
	e = c;
	f = d;
}
void calc(int A[][256], int b, double &m)
{
	int l = 0;
	int k = 0;
	double p = 0;
	int r = 0;
	while (l < c) {
		k = A[b][l];
		if (k < 0)
		{
			p += k;
			r++;
		}
		l++;
	}
	m = (p / r) * 1.0;
}
void calc2(int A[][256], int &b)
{
	int l = 0;
	int k = 0;
	while (l < d) {
		k = A[b][l];
		if (k > m) m = k;
		o = l;
		l++;
	}
}
void keit(int A[][256], int b, double m)
{
	A[b][o] = m;
}
void rodyti(string &text, int A[][256], int a, int b)
{
	text = "";
	int y = 0;
	int j = 0;
	while (j < a)
	{
		y = A[b][j];
		u = to_string(y);
		text = text + " " + u;
		j++;
	}
}
void spausd(int A[][256], ofstream &fs)
{
	a = 0;
	b = 0;
	fs << setw(7);
	while (b < c)
	{
		fs << setw(5) << b + 1;
		b++;
	}
	fs << endl;
	b = 0;
	while (a < d)
	{

		fs << "  ";
		while (b < (c * 5) + 1)
		{
			fs << "-";
			b++;
		}
		fs << endl;
		b = 0;
		fs << a + 1;
		fs << " |";
		while (b < c)
		{
			fs << setw(3) << A[a][b] << setprecision(2) << setw(2) << "|";
			b++;
		}
		fs << endl;
		b = 0;
		a++;
	}
	fs << "  ";
	while (b < (c * 5)+1)
	{
		fs << "-";
		b++;
	}
	fs << endl;
}