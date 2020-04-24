#include<iostream>
#include<string>
#include<cstdlib>
#include<cmath>
using namespace std;




void X(string polygons, string x[], int & v)
{
	x[0] = ";";
	v = 1;
	for (int i = 0; i<polygons.length(); i++)
	{

		if (polygons[i] == '(')
		{

			x[v] = polygons.substr(i + 1, polygons.find(',', i) - i - 1);
			v++;

		}
		if (polygons[i] == ';')
		{
			x[v] = ";";
			v++;
		}
	}
	x[v] = ";";
}
void Y(string polygons, string y[], int & a)
{
	y[0] = ";";
	a = 1;
	for (int i = 0; i<polygons.length(); i++)
	{

		if (polygons[i] == ',')
		{
			if (polygons[i + 1] == '(')
			{

			}
			else
			{
				y[a] = polygons.substr(i + 1, polygons.find(')', i) - i - 1);
				a++;
			}
		}
		if (polygons[i] == ';')
		{
			y[a] = ";";
			a++;
		}
	}
	y[a] = ";";
}
void Redr(string polygons, string r[], int & q)
{
	float d, g, h, k, slope, slope1;
	string x[10000], y[10000];
	int v, a, red1[1000], red2[1000], rr1 = 0, rr2 = 0;
	X(polygons, x, v);
	Y(polygons, y, a);
	q = 0;
	for (int i = 0; i<v; i++)
	{
		if (x[i] == ";")
		{
			continue;
		}
		if (x[i] == x[i + 1] && y[i] == y[i + 1])
		{
			red1[rr1] = i + 1;
			rr1++;
		}
	}
	for (int i = 0; i <= v; i++)
	{
		if (x[i] == ";" && y[i] == ";")
		{

			for (int j = i + 1; j <= v; j++)
			{

				if (x[j] == ";")
				{

					if (x[i + 1] == x[j - 1] && y[i + 1] == y[j - 1])
					{
						red1[rr1] = j - 1;
						rr1++;
					}
				}
			}

		}
	}
	for (int i = 0; i <= v; i++)
	{
		for (int j = 0; j<rr1; j++)
		{
			if (red1[j] == i)
			{
				x[i].erase();
				y[i].erase();
			}
		}
	}
	int vv = v;
	int aa = a;
	for (int i = 0; i <= v; i++)
	{
		if (x[i] == "")
		{
			x[i] = x[i + 1];
			y[i] = y[i + 1];

			for (int j = i + 1; j <= v; j++)
			{
				if (j + 1>v)
				{
					x[j + 1] = ";";
					y[j + 1] = ";";
				}
				else
				{
					x[j] = x[j + 1];
					y[j] = y[j + 1];
				}
			}
			vv--;
			aa--;
			i = 0;
		}
	}
	for (int i = 0; i <= vv; i++)
	{
		if (x[i] == ";")
		{

		}
		else
		{
			d = atof(x[i].c_str());
			g = atof(x[i + 1].c_str());
			h = atof(y[i].c_str());
			k = atof(y[i + 1].c_str());
			slope = (float)(k - h) / (g - d);

			d = atof(x[i + 1].c_str());
			g = atof(x[i + 2].c_str());
			h = atof(y[i + 1].c_str());
			k = atof(y[i + 2].c_str());
			slope1 = (float)(k - h) / (g - d);
			if (x[i + 1] == ";" || x[i + 2] == ";")
			{
				continue;
			}
			if (slope == slope1)
			{
				red2[rr2] = i + 1;
				rr2++;
			}
		}
	}
	for (int i = 0; i <= vv; i++)
	{
		if (x[i] == ";")
		{
			for (int j = i + 1; j <= vv; j++)
			{
				if (x[j] == ";")
				{
					d = atof(x[i + 1].c_str());
					g = atof(x[j - 1].c_str());
					h = atof(y[i + 1].c_str());
					k = atof(y[j - 1].c_str());
					slope = (float)(k - h) / (g - d);

					d = atof(x[j - 1].c_str());
					g = atof(x[j - 2].c_str());
					h = atof(y[j - 1].c_str());
					k = atof(y[j - 2].c_str());
					slope1 = (float)(k - h) / (g - d);
					if (slope == slope1)
					{
						red2[rr2] = j - 1;
						rr2++;
					}
					break;
				}
			}

		}
	}
	for (int i = 0; i <= vv; i++)
	{
		if (x[i] == ";" && y[i] == ";")
		{

			for (int j = i + 1; j <= vv; j++)
			{
				if (x[j] == ";")
				{

					d = atof(x[i + 1].c_str());
					g = atof(x[j - 1].c_str());
					h = atof(y[i + 1].c_str());
					k = atof(y[j - 1].c_str());
					slope = (float)(k - h) / (g - d);

					d = atof(x[i + 1].c_str());
					g = atof(x[i + 2].c_str());
					h = atof(y[i + 1].c_str());
					k = atof(y[i + 2].c_str());
					slope1 = (float)(k - h) / (g - d);
					if (slope == slope1)
					{
						red2[rr2] = i + 1;
						rr2++;
					}
					break;
				}

			}

		}
	}
	for (int i = 0; i<vv; i++)
	{
		for (int j = 0; j<rr2; j++)
		{
			if (red2[j] == i)
			{
				x[i].erase();
				y[i].erase();
			}
		}
	}
	int vvv = vv;
	int aaa = aa;
	for (int i = 0; i <= vv; i++)
	{
		if (x[i] == "")
		{
			x[i] = x[i + 1];
			y[i] = y[i + 1];

			for (int j = i + 1; j <= vv; j++)
			{
				if (j + 1>vv)
				{
					x[j + 1] = ";";
					y[j + 1] = ";";
				}
				else
				{
					x[j] = x[j + 1];
					y[j] = y[j + 1];
				}
			}
			vvv--;
			aaa--;
			i = 0;
		}
	}
	for (int i = 0; i <= vvv; i++)
	{

		if (x[i] == "")
		{
			if (x[i] == ""&&x[i + 1] == "")
			{
				q++;
			}

		}
		else
		{
			if (x[i] == ";" && y[i] == ";")
			{

			}

			else
			{
				r[q] = r[q] + "(" + x[i] + "," + y[i] + ")" + ",";
				if (x[i + 1] == ";")
				{
					q++;
				}
				if (x[i + 1] == ""&&x[i + 2] == ";")
				{
					q++;
				}
			}
		}
	}
	for (int i = 0; i<q; i++)
	{
		r[i] = r[i].erase(r[i].length() - 1, r[i].length());
	}
}
void Redp(string polygons, string px[100][100], string py[100][100])
{
	string r[100];
	int q, px1, py1;
	Redr(polygons, r, q);
	for (int i = 0; i<q; i++)
	{
		px1 = 0;
		for (int j = 0; j<r[i].length(); j++)
		{
			if (r[i][j] == '(')
			{
				px[i][px1] = r[i].substr(j + 1, r[i].find(',', j) - j - 1);
				px1++;
			}
		}
	}
	for (int i = 0; i<q; i++)
	{
		py1 = 0;
		for (int j = 0; j<r[i].length(); j++)
		{
			if (r[i][j] == ',')
			{
				if (r[i][j + 1] == '(')
				{

				}
				else
				{
					py[i][py1] = r[i].substr(j + 1, r[i].find(')', j) - j - 1);
					py1++;
				}
			}
		}
	}
}
void Redxy(string polygons, string x1[], string y1[], int & re)
{
	float d, g, h, k, slope, slope1;
	string x[10000], y[10000];
	int v, a, red1[1000], rr1 = 0, red2[1000], rr2 = 0;
	X(polygons, x, v);
	Y(polygons, y, a);
	for (int i = 0; i<v; i++)
	{
		if (x[i] == ";")
		{
			continue;
		}
		if (x[i] == x[i + 1] && y[i] == y[i + 1])
		{
			red1[rr1] = i + 1;
			rr1++;
		}
	}
	for (int i = 0; i<v; i++)
	{
		if (x[i] == ";" && y[i] == ";")
		{

			for (int j = i + 1; j<v; j++)
			{

				if (x[j] == ";")
				{

					if (x[i + 1] == x[j - 1] && y[i + 1] == y[j - 1])
					{
						red1[rr1] = j - 1;
						rr1++;
					}
				}
			}

		}
	}
	for (int i = 0; i<v; i++)
	{
		for (int j = 0; j<rr1; j++)
		{
			if (red1[j] == i)
			{
				x[i].erase();
				y[i].erase();
			}
		}
	}
	int vv = v;
	int aa = a;
	for (int i = 0; i<v; i++)
	{
		if (x[i] == "")
		{
			x[i] = x[i + 1];
			y[i] = y[i + 1];

			for (int j = i + 1; j<v; j++)
			{
				if (j + 1>v)
				{
					x[j + 1] = ";";
					y[j + 1] = ";";
				}
				else
				{
					x[j] = x[j + 1];
					y[j] = y[j + 1];
				}
			}
			vv--;
			aa--;
			i = 0;
		}
	}
	for (int i = 0; i<vv; i++)
	{
		if (x[i] == ";")
		{

		}
		else
		{
			d = atof(x[i].c_str());
			g = atof(x[i + 1].c_str());
			h = atof(y[i].c_str());
			k = atof(y[i + 1].c_str());
			slope = (float)(k - h) / (g - d);

			d = atof(x[i + 1].c_str());
			g = atof(x[i + 2].c_str());
			h = atof(y[i + 1].c_str());
			k = atof(y[i + 2].c_str());
			slope1 = (float)(k - h) / (g - d);
			if (x[i + 1] == ";" || x[i + 2] == ";")
			{
				continue;
			}
			if (slope == slope1)
			{
				red2[rr2] = i + 1;
				rr2++;
			}
		}
	}
	for (int i = 0; i<vv; i++)
	{
		if (x[i] == ";")
		{
			for (int j = i + 1; j<vv; j++)
			{
				if (x[j] == ";")
				{
					d = atof(x[i + 1].c_str());
					g = atof(x[j - 1].c_str());
					h = atof(y[i + 1].c_str());
					k = atof(y[j - 1].c_str());
					slope = (float)(k - h) / (g - d);

					d = atof(x[j - 1].c_str());
					g = atof(x[j - 2].c_str());
					h = atof(y[j - 1].c_str());
					k = atof(y[j - 2].c_str());
					slope1 = (float)(k - h) / (g - d);
					if (slope == slope1)
					{
						red2[rr2] = j - 1;
						rr2++;
					}
					break;
				}
			}

		}
	}
	for (int i = 0; i<vv; i++)
	{
		if (x[i] == ";" && y[i] == ";")
		{

			for (int j = i + 1; j<vv; j++)
			{
				if (x[j] == ";")
				{

					d = atof(x[i + 1].c_str());
					g = atof(x[j - 1].c_str());
					h = atof(y[i + 1].c_str());
					k = atof(y[j - 1].c_str());
					slope = (float)(k - h) / (g - d);

					d = atof(x[i + 1].c_str());
					g = atof(x[i + 2].c_str());
					h = atof(y[i + 1].c_str());
					k = atof(y[i + 2].c_str());
					slope1 = (float)(k - h) / (g - d);
					if (slope == slope1)
					{
						red2[rr2] = i + 1;
						rr2++;
					}
					break;
				}

			}

		}
	}
	for (int i = 0; i<vv; i++)
	{
		for (int j = 0; j<rr2; j++)
		{
			if (red2[j] == i)
			{
				x[i].erase();
				y[i].erase();
			}
		}
	}
	int  vvv = vv;
	int aaa = aa;
	for (int i = 0; i<vv; i++)
	{
		if (x[i] == "")
		{
			x[i] = x[i + 1];
			y[i] = y[i + 1];

			for (int j = i + 1; j<vv; j++)
			{
				if (j + 1>vv)
				{
					x[j + 1] = ";";
					y[j + 1] = ";";
				}
				else
				{
					x[j] = x[j + 1];
					y[j] = y[j + 1];
				}
			}
			vvv--;
			aaa--;
			i = 0;
		}
	}
	re = 0;
	for (int i = 0; i<vvv; i++)
	{
		if (x[i] == "")
		{

		}
		else
		{
			x1[re] = x[i];
			y1[re] = y[i];
			re++;
		}
	}
}
void Number_Polygons(string polygons)
{
	int count = 0;
	for (int i = 0; i < polygons.length(); i++)
	{
		if (polygons[i] == ';')
		{
			count = count + 1;
		}
	}
	cout << count + 1;
}
void Total_Number_Points(string polygons)
{
	int count = 0;
	for (int i = 0; i < polygons.length(); i++)
	{
		if (polygons[i] == '(')
		{
			count = count + 1;
		}
	}
	cout << count;
}
float Minimum_X(string polygons)
{
	int v;
	string x[10000];
	X(polygons, x, v);
	float f, minX = atof(x[1].c_str());
	for (int i = 2; i<v; i++)
	{
		if (x[i] == ";")
		{

		}
		else
		{

			f = atof(x[i].c_str());

			if (f<minX)
			{
				minX = f;
			}

		}
	}
	return minX;
}
float Maximum_X(string polygons)
{
	int v;
	string x[10000];
	X(polygons, x, v);
	float f, maxX = atof(x[1].c_str());
	for (int i = 2; i<v; i++)
	{
		if (x[i] == ";")
		{

		}
		else
		{

			f = atof(x[i].c_str());

			if (f>maxX)
			{
				maxX = f;
			}

		}
	}
	return maxX;
}
float Minimum_Y(string polygons)
{
	int a;
	string y[10000];
	Y(polygons, y, a);
	float f, minY = atof(y[1].c_str());
	for (int i = 2; i<a; i++)
	{
		if (y[i] == ";")
		{

		}
		else
		{

			f = atof(y[i].c_str());

			if (f<minY)
			{
				minY = f;
			}

		}
	}
	return minY;
}
float Maximum_Y(string polygons)
{
	int a;
	string y[10000];
	Y(polygons, y, a);
	float f, maxY = atof(y[1].c_str());
	for (int i = 2; i<a; i++)
	{
		if (y[i] == ";")
		{

		}
		else
		{

			f = atof(y[i].c_str());

			if (f>maxY)
			{
				maxY = f;
			}

		}
	}
	return maxY;
}
int Total_Redundant_Points(string polygons)
{
	int v, a, n = 0;
	float d, g, h, k, slope, slope1;
	string x[10000], y[10000];
	X(polygons, x, v);
	Y(polygons, y, a);
	for (int i = 0; i<v; i++)
	{
		if (x[i] == x[i + 1] && y[i] == y[i + 1])
		{
			n++;
		}
	}
	for (int i = 0; i<v; i++)
	{

		if (x[i] == ";" || x[i + 1] == ";")
		{

		}
		else
		{

			d = atof(x[i].c_str());
			g = atof(x[i + 1].c_str());
			h = atof(y[i].c_str());
			k = atof(y[i + 1].c_str());
			slope = (float)(k - h) / (g - d);

			d = atof(x[i + 1].c_str());
			g = atof(x[i + 2].c_str());
			h = atof(y[i + 1].c_str());
			k = atof(y[i + 2].c_str());
			slope1 = (float)(k - h) / (g - d);

			if (slope == slope1)
			{
				n++;
			}
		}
	}
	for (int i = 0; i <= v; i++)
	{
		if (x[i] == ";" && y[i] == ";")
		{

			for (int j = i + 1; j <= v; j++)
			{

				if (x[j] == ";")
				{

					if (x[i + 1] == x[j - 1] && y[i + 1] == y[j - 1])
					{
						n++;
					}
				}
			}

		}
	}
	for (int i = 0; i <= v; i++)
	{
		if (x[i] == ";" && y[i] == ";")
		{
			for (int j = i + 1; j <= v; j++)
			{
				if (x[j] == ";")
				{
					if (x[i + 1] == x[j - 1] && y[i + 1] == y[j - 1])
					{
						d = atof(x[i + 1].c_str());
						g = atof(x[j - 2].c_str());
						h = atof(y[i + 1].c_str());
						k = atof(y[j - 2].c_str());
						slope = (float)(k - h) / (g - d);

						d = atof(x[j - 2].c_str());
						g = atof(x[j - 3].c_str());
						h = atof(y[j - 2].c_str());
						k = atof(y[j - 3].c_str());
						slope1 = (float)(h - k) / (d - g);
						if (slope == slope1)
						{
							n++;
						}
					}
					else
					{
						d = atof(x[i + 1].c_str());
						g = atof(x[j - 1].c_str());
						h = atof(y[i + 1].c_str());
						k = atof(y[j - 1].c_str());
						slope = (float)(k - h) / (g - d);

						d = atof(x[j - 1].c_str());
						g = atof(x[j - 2].c_str());
						h = atof(y[j - 1].c_str());
						k = atof(y[j - 2].c_str());
						slope1 = (float)(h - k) / (d - g);
						if (slope == slope1)
						{
							n++;
						}
					}
					break;
				}

			}
		}
	}
	for (int i = 0; i <= v; i++)
	{
		if (x[i] == ";" && y[i] == ";")
		{

			for (int j = i + 1; j <= v; j++)
			{
				if (x[j] == ";")
				{
					d = atof(x[i + 1].c_str());
					g = atof(x[j - 1].c_str());
					h = atof(y[i + 1].c_str());
					k = atof(y[j - 1].c_str());
					slope = (float)(k - h) / (g - d);

					d = atof(x[i + 1].c_str());
					g = atof(x[i + 2].c_str());
					h = atof(y[i + 1].c_str());
					k = atof(y[i + 2].c_str());
					slope1 = (float)(k - h) / (g - d);
					if (slope == slope1)
					{
						n++;
					}
					break;

				}
			}

		}
	}
	return n;
}
void Polygon_Points(string polygons, int o)
{
	int q;
	string r[100];
	Redr(polygons, r, q);
	for (int i = 1; i <= q; i++)
	{
		if (o == i)
		{
			cout << r[i - 1];
		}
	}
}
void Point_Polygons(string polygons, string s)
{
	int v, a;
	string x[10000], y[10000];
	string sx, sy;
	X(polygons, x, v);
	Y(polygons, y, a);
	sx = s.substr(1, s.find(",") - 1);
	int r = s.find(","), o = 1, f = 1, u = 0;
	sy = s.substr(r + 1, s.find(")") - r - 1);
	for (int i = 1; i<v; i++)
	{
		if (x[i] == ";")
		{
			o++;
		}
		else if (x[i] == sx&&y[i] == sy)
		{
			if (f == 1)
			{
				u++;
				cout << o;
				f = 0;
			}
			else
			{
				u++;
				cout << "," << o;
			}
			for (int j = i + 1; j<v; j++)
			{
				if (x[j] == ";")
				{
					i = j - 1;
					break;
				}
			}
		}

	}
	if (u == 0)
	{
		cout << "none";
	}
}
void List_Polygons_PointsMore(string polygons, int o)
{
	int q;
	string r[100];
	Redr(polygons, r, q);
	int f = 1, cc = 0;
	int m = 0, u = 0;
	for (int i = 0; i<q; i++)
	{
		m = 0, u = 0;
		for (int j = 0; j<r[i].length(); j++)
		{
			if (r[i][j] == '(')
			{
				m = m + 1;
				u = m;

			}

		}
		if (u>o)
		{
			cc++;
			if (f == 1)
			{
				cout << i + 1;
				f = 0;
			}
			else
				cout << "," << i + 1;
		}

	}
	if (cc == 0)
	{
		cout << "none";
	}
}
void List_Polygons_PointsLess(string polygons, int o)
{
	int q;
	string r[100];
	Redr(polygons, r, q);
	int f = 1, cc = 0;
	for (int i = 0; i<q; i++)
	{
		int m = 0, e;
		for (int j = 0; j<r[i].length(); j++)
		{
			if (r[i][j] == '(')
			{
				m = m + 1;
				e = m;

			}

		}
		if (e<o)
		{
			cc++;
			if (f == 1)
			{
				cout << i + 1;
				f = 0;
			}
			else
				cout << "," << i + 1;
		}

	}
	if (cc == 0)
	{
		cout << "none";
	}
}
void List_Polygons_PointsEqual(string polygons, int o)
{
	int q;
	string r[100];
	Redr(polygons, r, q);
	int f = 1, cc = 0;
	for (int i = 0; i<q; i++)
	{
		int m = 0, e;
		for (int j = 0; j<r[i].length(); j++)
		{
			if (r[i][j] == '(')
			{
				m = m + 1;
				e = m;

			}

		}
		if (e == o)
		{
			cc++;
			if (f == 1)
			{
				cout << i + 1;
				f = 0;
			}
			else
				cout << "," << i + 1;
		}

	}
	if (cc == 0)
	{
		cout << "none";
	}
}
void List_Points_PolygonsMore(string polygons, int o)
{
	string x[10000], y[10000];
	int v, a;
	X(polygons, x, v);
	Y(polygons, y, a);
	int rp[10000], pr = 1;
	string point[10000];
	rp[0] = 0;
	point[0] = "";
	for (int i = 1; i<v; i++)
	{
		int count = 0;
		for (int j = 1; j<v; j++)
		{
			if (x[i] == ";")
			{
				continue;
			}
			else if (x[i] == x[j] && y[i] == y[j])
			{
				for (int k = j + 1; k<v; k++)
				{
					if (x[k] == ";")
					{
						break;
					}
					if (x[k] == x[i] && y[k] == y[i])
					{
						j = k;
					}
				}
				count++;
			}

		}
		if (x[i] == ";")
		{
			continue;
		}
		else
		{
			rp[pr] = count;
			point[pr] = "(" + x[i] + "," + y[i] + ")";
			pr++;
		}

	}
	int f = 1, u = 0, mn = 0, mm = 0;
	for (int i = 1; i<pr; i++)
	{
		if (rp[i]>o)
		{
			if (point[mn] == point[i])
			{
				continue;
			}
			if (point[mm] == point[i])
			{
				continue;
			}
			if (f == 1)
			{
				mn = i;
				u++;
				cout << point[i];
				f = 0;
			}
			else
			{
				mm = i;
				u++;
				cout << "," << point[i];
			}

		}

	}
	if (u == 0)
	{
		cout << "none";
	}

}
void List_Points_PolygonsLess(string polygons, int o)
{
	string x[10000], y[10000];
	int v, a;
	X(polygons, x, v);
	Y(polygons, y, a);
	int rp[10000], pr = 1;
	string point[10000];
	rp[0] = 0;
	point[0] = "";
	for (int i = 1; i<v; i++)
	{
		int count = 0;
		for (int j = 1; j<v; j++)
		{
			if (x[i] == ";")
			{
				continue;
			}
			else if (x[i] == x[j] && y[i] == y[j])
			{
				for (int k = j + 1; k<v; k++)
				{
					if (x[k] == ";")
					{
						break;
					}
					if (x[k] == x[i] && y[k] == y[i])
					{
						j = k;
					}
				}
				count++;
			}

		}
		if (x[i] == ";")
		{
			continue;
		}
		else
		{
			rp[pr] = count;
			point[pr] = "(" + x[i] + "," + y[i] + ")";
			pr++;
		}

	}
	int f = 1, u = 0, mn = 0, mm = 0;
	for (int i = 1; i<pr; i++)
	{
		if (rp[i]<o)
		{
			if (point[mn] == point[i])
			{
				continue;
			}
			if (point[mm] == point[i])
			{
				continue;
			}
			if (f == 1)
			{
				mn = i;
				u++;
				cout << point[i];
				f = 0;
			}
			else
			{
				mm = i;
				u++;
				cout << "," << point[i];
			}

		}

	}
	if (u == 0)
	{
		cout << "none";
	}
}
void List_Points_PolygonsEqual(string polygons, int o)
{
	string x[10000], y[10000];
	int v, a;
	X(polygons, x, v);
	Y(polygons, y, a);
	int rp[10000], pr = 1;
	string point[10000];
	rp[0] = 0;
	point[0] = "";
	for (int i = 1; i<v; i++)
	{
		int count = 0;
		for (int j = 1; j<v; j++)
		{
			if (x[i] == ";")
			{
				continue;
			}
			else if (x[i] == x[j] && y[i] == y[j])
			{
				for (int k = j + 1; k<v; k++)
				{
					if (x[k] == ";")
					{
						break;
					}
					if (x[k] == x[i] && y[k] == y[i])
					{
						j = k;
					}
				}
				count++;
			}

		}
		if (x[i] == ";")
		{
			continue;
		}
		else
		{
			rp[pr] = count;
			point[pr] = "(" + x[i] + "," + y[i] + ")";
			pr++;
		}

	}
	int f = 1, u = 0, mn = 0, mm = 0;
	for (int i = 1; i<pr; i++)
	{
		if (rp[i] == o)
		{
			if (point[mn] == point[i])
			{
				continue;
			}
			if (point[mm] == point[i])
			{
				continue;
			}
			if (f == 1)
			{
				mn = i;
				u++;
				cout << point[i];
				f = 0;
			}
			else
			{
				mm = i;
				u++;
				cout << "," << point[i];
			}

		}

	}
	if (u == 0)
	{
		cout << "none";
	}
}
void Polygon_Perimeter(string polygons, int o)
{
	string px[100][100], py[100][100];
	Redp(polygons, px, py);
	float per = 0;
	for (int k = 0; k<100; k++)
	{
		if (px[o - 1][k] == "")
		{
			break;
		}
		else
		{
			if (px[o - 1][k + 1] == "")
			{
				float  f1 = atof(px[o - 1][k].c_str());
				float  f2 = atof(px[o - 1][0].c_str());
				float  p1 = atof(py[o - 1][k].c_str());
				float  p2 = atof(py[o - 1][0].c_str());
				per = per + sqrt(pow(f2 - f1, 2) + pow(p2 - p1, 2));
			}
			else
			{
				float  f1 = atof(px[o - 1][k].c_str());
				float  f2 = atof(px[o - 1][k + 1].c_str());
				float  p1 = atof(py[o - 1][k].c_str());
				float  p2 = atof(py[o - 1][k + 1].c_str());
				per = per + sqrt(pow(f2 - f1, 2) + pow(p2 - p1, 2));
			}
		}
	}
	cout << per;
}
void List_Triangles(string polygons)
{
	string r[100];
	int q;
	Redr(polygons, r, q);
	int f = 1, cc = 0;
	for (int i = 0; i<q; i++)
	{
		int e = 0;
		for (int j = 0; j<r[i].length(); j++)
		{
			if (r[i][j] == '(')
			{

				e = e + 1;

			}

		}
		if (e == 3)
		{
			if (f == 1)
			{
				cc++;
				cout << i + 1;
				f = 0;
			}
			else
			{
				cc++;
				cout << "," << i + 1;
			}

		}
	}
	if (cc == 0)
	{
		cout << "none";
	}
}
void List_Rectangles(string polygons)
{
	string r[100], x1[10000], y1[10000];
	int q, re, nn = 0;
	Redr(polygons, r, q);
	Redxy(polygons, x1, y1, re);
	int f = 1, m[100], u = 0;
	for (int i = 0; i<q; i++)
	{
		int e = 0;
		for (int j = 0; j<r[i].length(); j++)
		{
			if (r[i][j] == '(')
			{

				e = e + 1;

			}

		}
		if (e == 4)
		{
			m[u] = i + 1;
			u++;
		}
	}
	int l = 0, yu = 1;
	for (int k = 0; k<re; k++)
	{
		if (x1[k] == ";")
		{
			l++;
			for (int j = 0; j<u; j++)
			{
				if (l == m[j])
				{
					float    d1 = atof(x1[k + 1].c_str());
					float    g2 = atof(x1[k + 2].c_str());
					float    h1 = atof(y1[k + 1].c_str());
					float    k2 = atof(y1[k + 2].c_str());
					float    d3 = atof(x1[k + 3].c_str());
					float    g4 = atof(x1[k + 4].c_str());
					float    h3 = atof(y1[k + 3].c_str());
					float    k4 = atof(y1[k + 4].c_str());
					float distance = sqrt(pow(d3 - d1, 2) + pow(h3 - h1, 2));
					float distance1 = sqrt(pow(g4 - g2, 2) + pow(k4 - k2, 2));
					if (distance1 == distance)
					{
						nn++;
						if (yu == 1)
						{
							cout << l;
							yu = 0;
						}
						else
							cout << "," << l;
					}
				}
			}
		}
	}
	if (nn == 0)
	{
		cout << "none";
	}
}
void List_Trapezoid(string polygons)
{
	float slope, slope1, slope2, slope3;
	string r[100], x1[10000], y1[10000];
	int q, re;
	Redr(polygons, r, q);
	Redxy(polygons, x1, y1, re);
	int m[100], u = 0;
	for (int i = 0; i<q; i++)
	{
		int e = 0;
		for (int j = 0; j<r[i].length(); j++)
		{
			if (r[i][j] == '(')
			{

				e = e + 1;

			}

		}
		if (e == 4)
		{
			m[u] = i + 1;
			u++;
		}
	}
	int l = 0, yu = 1;
	for (int k = 0; k<re; k++)
	{
		if (x1[k] == ";")
		{
			l++;
			for (int j = 0; j<u; j++)
			{
				if (l == m[j])
				{
					float   d1 = atof(x1[k + 1].c_str());
					float   g1 = atof(x1[k + 2].c_str());
					float   h1 = atof(y1[k + 1].c_str());
					float   k1 = atof(y1[k + 2].c_str());
					slope = (float)(k1 - h1) / (g1 - d1);

					float    d2 = atof(x1[k + 3].c_str());
					float    g2 = atof(x1[k + 4].c_str());
					float    h2 = atof(y1[k + 3].c_str());
					float    k2 = atof(y1[k + 4].c_str());
					slope1 = (float)(k2 - h2) / (g2 - d2);

					float    d3 = atof(x1[k + 1].c_str());
					float    g3 = atof(x1[k + 4].c_str());
					float    h3 = atof(y1[k + 1].c_str());
					float    k3 = atof(y1[k + 4].c_str());
					slope2 = (float)(k3 - h3) / (g3 - d3);

					float    d4 = atof(x1[k + 2].c_str());
					float    g4 = atof(x1[k + 3].c_str());
					float    h4 = atof(y1[k + 2].c_str());
					float    k4 = atof(y1[k + 3].c_str());
					slope3 = (float)(k4 - h4) / (g4 - d4);
					if (slope == slope1 && slope2 != slope3 || slope != slope1 && slope2 == slope3)
					{
						if (yu == 1)
						{
							cout << l;
							yu = 0;
						}
						else
							cout << "," << l;
					}
				}
			}
		}
	}
}
void Inside_Rectangle(string polygons, string rectangle)
{
	string px[100][100], py[100][100];
	Redp(polygons, px, py);
	string xrec[4], yrec[4];
	int recx = 0, recy = 0;
	for (int i = 0; i<rectangle.length(); i++)
	{
		if (rectangle[i] == '(')
		{

			xrec[recx] = rectangle.substr(i + 1, rectangle.find(',', i) - i - 1);
			recx++;
		}
	}
	for (int i = 0; i<rectangle.length(); i++)
	{

		if (rectangle[i] == ',')
		{
			if (rectangle[i + 1] == '(')
			{

			}
			else
			{
				yrec[recy] = rectangle.substr(i + 1, rectangle.find(')', i) - i - 1);
				recy++;
			}
		}
	}
	float slope, slope1, d, g, h;
	int f = 1, ffff = 1, cc, no = 0, ee, ww, cp = 0, kkk;
	float dd, hh, kk, gg, ff, minx, maxx, miny, maxy;
	for (int ii = 0; ii<100; ii++)
	{
		no = 0;
		if (px[ii][0] == "")
		{
			break;
		}
		for (kkk = 0; kkk<100; kkk++)
		{
			if (px[ii][kkk] == "")
			{
				break;
			}
			ee = 0;
			ww = 0;
			cc = 0;
			g = atof(px[ii][kkk].c_str());
			ff = atof(py[ii][kkk].c_str());
			minx = 1000000000000000000;
			maxx = -100000000000000000;
			miny = 1000000000000000000;
			maxy = -100000000000000000;
			for (int u = 0; u<recx; u++)
			{
				for (int i = 0; i<recx; i++)
				{
					if (atof(xrec[i].c_str())<minx)
					{
						minx = atof(xrec[i].c_str());
					}
					if (atof(xrec[i].c_str())>maxx)
					{
						maxx = atof(xrec[i].c_str());
					}
					if (atof(yrec[i].c_str())<miny)
					{
						miny = atof(yrec[i].c_str());
					}
					if (atof(yrec[i].c_str())>maxy)
					{
						maxy = atof(yrec[i].c_str());
					}
				}
				if (g<minx)
				{
					break;
				}
				if (g>maxx)
				{
					break;
				}
				if (ff<miny)
				{
					break;
				}
				if (ff>maxy)
				{
					break;
				}
				if (u == 3)
				{
					d = atof(xrec[u].c_str());
					h = atof(yrec[u].c_str());
					slope = (float)(h - ff) / (d - g);

					d = atof(xrec[0].c_str());
					h = atof(yrec[0].c_str());
					slope1 = (float)(h - ff) / (d - g);
				}
				else
				{
					d = atof(xrec[u].c_str());
					h = atof(yrec[u].c_str());
					slope = (float)(h - ff) / (d - g);

					d = atof(xrec[u + 1].c_str());
					h = atof(yrec[u + 1].c_str());
					slope1 = (float)(h - ff) / (d - g);
				}
				if (u == 3)
				{
					dd = atof(xrec[u].c_str());
					hh = atof(yrec[u].c_str());
					gg = atof(xrec[0].c_str());
					kk = atof(yrec[0].c_str());
				}
				else
				{
					dd = atof(xrec[u].c_str());
					hh = atof(yrec[u].c_str());
					gg = atof(xrec[u + 1].c_str());
					kk = atof(yrec[u + 1].c_str());
				}
				if (xrec[u] == px[ii][kkk] && yrec[u] == py[ii][kkk])
				{
					no++;
					ee++;
					break;
				}
				else if (hh>kk && dd>gg)
				{
					if (slope == slope1 && hh>ff && kk<ff)
					{
						no++;
						ww++;
						break;
					}

					else if (hh >= ff && kk <= ff && gg>g)
					{
						if (hh == ff || kk == ff)
						{
							if (ffff == 1)
							{
								cc++;
								ffff = 0;
							}

						}
						else
						{
							cc++;
						}

					}
					else if (hh >= ff && kk <= ff && gg == g && slope1>slope)
					{
						if (hh == ff || kk == ff)
						{
							if (ffff == 1)
							{
								cc++;
								ffff = 0;
							}

						}
						else
						{
							cc++;
						}
					}
					else if (hh>ff && kk<ff && dd>g && gg<g && slope1>slope)
					{
						cc++;
					}
				}
				else if (kk>hh && gg>dd)
				{
					if (slope == slope1 && kk>ff && hh<ff)
					{
						ww++;
						no++;
						break;
					}
					else if (hh <= ff && kk >= ff && dd>g)
					{
						if (hh == ff || kk == ff)
						{
							if (ffff == 1)
							{
								cc++;
								ffff = 0;
							}

						}
						else
						{
							cc++;
						}
					}
					else if (hh <= ff && kk >= ff && dd == g && slope1<slope)
					{
						if (hh == ff || kk == ff)
						{
							if (ffff == 1)
							{
								cc++;
								ffff = 0;
							}

						}
						else
						{
							cc++;
						}
					}
					else if (hh<ff && kk>ff && dd<g && gg>g && slope1<slope)
					{
						cc++;
					}
				}
				else if (hh>kk && gg>dd)
				{
					if (slope == slope1 && hh>ff && kk<ff)
					{
						ww++;
						no++;
						break;
					}
					else if (hh >= ff && kk <= ff && dd>g)
					{
						if (hh == ff || kk == ff)
						{
							if (ffff == 1)
							{
								cc++;
								ffff = 0;
							}

						}
						else
						{
							cc++;
						}
					}
					else if (hh >= ff && kk <= ff && dd == g && slope>slope1)
					{
						if (hh == ff || kk == ff)
						{
							if (ffff == 1)
							{
								cc++;
								ffff = 0;
							}

						}
						else
						{
							cc++;
						}
					}
					else if (hh>ff && kk<ff && dd<g && gg>g && slope1>slope)
					{
						cc++;
					}
				}
				else if (kk>hh && dd>gg)
				{
					if (slope == slope1 && kk>ff && hh<ff)
					{
						ww++;
						no++;
						break;
					}
					else if (hh <= ff && kk >= ff && gg>g)
					{
						if (hh == ff || kk == ff)
						{
							if (ffff == 1)
							{
								cc++;
								ffff = 0;
							}

						}
						else
						{
							cc++;
						}
					}
					else if (hh <= ff && kk >= ff && gg == g && slope<slope1)
					{
						if (hh == ff || kk == ff)
						{
							if (ffff == 1)
							{
								cc++;
								ffff = 0;
							}

						}
						else
						{
							cc++;
						}
					}
					else if (hh<ff && kk>ff && dd>g && gg<g && slope1<slope)
					{
						cc++;
					}
				}
				else if (hh>kk && dd == gg)
				{
					if (hh>ff && kk<ff && dd == g)
					{
						ww++;
						no++;
						break;
					}
					else if (hh >= ff && kk <= ff && dd>g)
					{
						if (hh == ff || kk == ff)
						{
							if (ffff == 1)
							{
								cc++;
								ffff = 0;
							}

						}
						else
						{
							cc++;
						}
					}
				}
				else if (kk>hh && dd == gg)
				{
					if (hh<ff && kk>ff && dd == g)
					{
						ww++;
						no++;
						break;
					}
					else if (hh <= ff && kk >= ff && dd>g)
					{
						if (hh == ff || kk == ff)
						{
							if (ffff == 1)
							{
								cc++;
								ffff = 0;
							}

						}
						else
						{
							cc++;
						}
					}
				}
				else if (kk == hh && dd>gg)
				{
					if (slope == slope1)
					{
						ww++;
						no++;
						break;
					}
				}
				else if (kk == hh && gg>dd)
				{
					if (slope == slope1)
					{
						ww++;
						no++;
						break;
					}
				}
			}
			if ((cc - 1) % 2 == 0)
			{
				if (ww == 0 && ee == 0)
				{
					no++;
				}
			}
		}
		if (no == kkk)
		{
			if (f == 1)
			{
				cp++;
				cout << ii + 1;
				f = 0;

			}
			else
			{
				cp++;
				cout << "," << ii + 1;
			}
		}
	}
	if (cp == 0)
	{
		cout << "none";
	}
}
void Inside_Circle(string polygons, string circle)
{
	string x1[10000], y1[10000];
	int re;
	Redxy(polygons, x1, y1, re);
	float cx = atof(circle.substr(circle.find(" ") + 2, circle.find(",") - circle.find(" ") - 2).c_str());
	float cy = atof(circle.substr(circle.find(",") + 1, circle.find(")") - circle.find(",") - 1).c_str());
	float cr = atof(circle.substr(circle.find(")") + 2).c_str());
	int cp = 0, f = 1, cc, no = 0;
	for (int i = 0; i<re; i++)
	{
		if (x1[i] == ";")
		{
			cc = 0;
			cp++;
			for (int j = i + 1; j <= re; j++)
			{
				if (x1[j] == "")
				{
					break;
				}
				if (x1[j] == ";")
				{
					break;
				}
				float px = atof(x1[j].c_str());
				float py = atof(y1[j].c_str());
				float distance = sqrt(pow(px - cx, 2) + pow(py - cy, 2));
				if (distance <= cr)
				{
					cc++;
				}
				else
				{
					cc = 0;
					break;
				}
			}
			if (cc>1)
			{
				if (f == 1)
				{
					no++;
					cout << cp;
					f = 0;

				}
				else
				{
					no++;
					cout << "," << cp;
				}
			}
		}
	}
	if (no == 0)
	{
		cout << "none";
	}
}
void Polygon_Area(string polygons, int o)
{
	string px[100][100], py[100][100];
	Redp(polygons, px, py);
	float area = 0;
	for (int k = 0; k<100; k++)
	{
		if (px[o - 1][k] == "")
		{
			break;
		}
		else
		{
			if (px[o - 1][k + 1] == "")
			{
				float  f1 = atof(px[o - 1][k].c_str());
				float  f2 = atof(px[o - 1][0].c_str());
				float  p1 = atof(py[o - 1][k].c_str());
				float  p2 = atof(py[o - 1][0].c_str());
				area = area + (f2*p1 - p2*f1);
			}
			else
			{
				float  f1 = atof(px[o - 1][k].c_str());
				float  f2 = atof(px[o - 1][k + 1].c_str());
				float  p1 = atof(py[o - 1][k].c_str());
				float  p2 = atof(py[o - 1][k + 1].c_str());
				area = area + (f2*p1 - p2*f1);
			}
		}
	}

	cout << fabs(area / 2);
}
void Polygons_Area_Range(string polygons, string s)
{
	string px[100][100], py[100][100];
	Redp(polygons, px, py);
	float minarea = atof(s.substr(s.find(" ") + 1, s.find(",") - s.find(" ") - 1).c_str());
	float maxarea = atof(s.substr(s.find(",") + 1).c_str());
	float area;
	int f = 1, cc = 0;
	for (int i = 0; i<100; i++)
	{
		if (px[i][0] == "")
		{
			break;
		}
		area = 0;
		for (int k = 0; k<100; k++)
		{
			if (px[i][k] == "")
			{
				break;
			}
			else
			{
				if (px[i][k + 1] == "")
				{
					float  f1 = atof(px[i][k].c_str());
					float  f2 = atof(px[i][0].c_str());
					float  p1 = atof(py[i][k].c_str());
					float  p2 = atof(py[i][0].c_str());
					area = area + (f2*p1 - p2*f1);
				}
				else
				{
					float  f1 = atof(px[i][k].c_str());
					float  f2 = atof(px[i][k + 1].c_str());
					float  p1 = atof(py[i][k].c_str());
					float  p2 = atof(py[i][k + 1].c_str());
					area = area + (f2*p1 - p2*f1);
				}
			}
		}
		if (fabs((area / 2)) >= minarea && fabs((area / 2)) <= maxarea)
		{
			if (f == 1)
			{
				cc++;
				cout << i + 1;
				f = 0;

			}
			else
			{
				cc++;
				cout << "," << i + 1;
			}
		}
	}
	if (cc == 0)
	{
		cout << "none";
	}
}
void Polygons_Enclosing_Point(string polygons, string s)
{
	float d, g, h, slope, slope1;
	string px[100][100], py[100][100];
	Redp(polygons, px, py);
	string sx, sy;
	sx = s.substr(s.find(' ') + 2, s.find(",") - s.find(' ') - 2);
	sy = s.substr(s.find(",") + 1, s.find(")") - s.find(",") - 1);
	float sx1 = atof(sx.c_str());
	float sy1 = atof(sy.c_str());
	int f = 1, ffff = 1, cc, no = 0, ee, ww;
	float dd, hh, kk, gg, minx, maxx, miny, maxy;
	float ddd, hhh, kkk, ggg;
	for (int jj = 0; jj<100; jj++)
	{
		if (px[jj][0] == "")
		{
			break;
		}
		ee = 0;
		ww = 0;
		cc = 0;
		ffff = 1;
		minx = 1000000000000000000;
		maxx = -100000000000000000;
		miny = 1000000000000000000;
		maxy = -100000000000000000;
		for (int i = 0; i<100; i++)
		{
			if (px[jj][i] == "")
			{
				break;
			}
			if (atof(px[jj][i].c_str())<minx)
			{
				minx = atof(px[jj][i].c_str());
				ddd = atof(py[jj][i].c_str());
			}
			if (atof(px[jj][i].c_str())>maxx)
			{
				maxx = atof(px[jj][i].c_str());
				ggg = atof(py[jj][i].c_str());
			}
			if (atof(py[jj][i].c_str())<miny)
			{
				miny = atof(py[jj][i].c_str());
				hhh = atof(px[jj][i].c_str());
			}
			if (atof(py[jj][i].c_str())>maxy)
			{
				maxy = atof(py[jj][i].c_str());
				kkk = atof(px[jj][i].c_str());
			}

		}
		for (int u = 0; u<100; u++)
		{
			if (px[jj][u] == "")
			{
				break;
			}
			if (sx1<minx)
			{
				break;
			}
			if (sx1>maxx)
			{
				break;
			}
			if (sy1<miny)
			{
				break;
			}
			if (sy1>maxy)
			{
				break;
			}
			if (px[jj][u + 1] == "")
			{
				d = atof(px[jj][u].c_str());
				h = atof(py[jj][u].c_str());
				slope = (float)(h - sy1) / (d - sx1);

				d = atof(px[jj][0].c_str());
				h = atof(py[jj][0].c_str());
				slope1 = (float)(h - sy1) / (d - sx1);
			}
			else
			{
				d = atof(px[jj][u].c_str());
				h = atof(py[jj][u].c_str());
				slope = (float)(h - sy1) / (d - sx1);

				d = atof(px[jj][u + 1].c_str());
				h = atof(py[jj][u + 1].c_str());
				slope1 = (float)(h - sy1) / (d - sx1);
			}
			if (px[jj][u + 1] == "")
			{
				dd = atof(px[jj][u].c_str());
				hh = atof(py[jj][u].c_str());
				gg = atof(px[jj][0].c_str());
				kk = atof(py[jj][0].c_str());
			}
			else
			{
				dd = atof(px[jj][u].c_str());
				hh = atof(py[jj][u].c_str());
				gg = atof(px[jj][u + 1].c_str());
				kk = atof(py[jj][u + 1].c_str());
			}
			if (px[jj][u] == sx && py[jj][u] == sy)
			{
				ee++;
				if (f == 1)
				{
					no++;
					cout << jj + 1;
					f = 0;

				}
				else
				{
					no++;
					cout << "," << jj + 1;
				}
				break;
			}

			else if (hh>kk && dd>gg)
			{
				if (slope == slope1 && hh>sy1 && kk<sy1)
				{
					ww++;
					if (f == 1)
					{
						no++;
						cout << jj + 1;
						f = 0;

					}
					else
					{
						no++;
						cout << "," << jj + 1;
					}
					break;
				}

				else if (hh >= sy1 && kk <= sy1 && gg>sx1)
				{
					if (hh == sy1 || kk == sy1)
					{
						if (ffff == 1)
						{
							cc++;
							ffff = 0;
						}

					}
					else
					{
						cc++;
					}

				}
				else if (hh >= sy1 && kk <= sy1 && gg == sx1 && slope1>slope)
				{
					if (hh == sy1 || kk == sy1)
					{
						if (ffff == 1)
						{
							cc++;
							ffff = 0;
						}

					}
					else
					{
						cc++;
					}
				}
				else if (hh>sy1 && kk<sy1 && dd>sx1 && gg<sx1 && slope1>slope)
				{
					cc++;
				}
			}
			else if (kk>hh && gg>dd)
			{
				if (slope == slope1 && kk>sy1 && hh<sy1)
				{
					ww++;
					if (f == 1)
					{
						no++;
						cout << jj + 1;
						f = 0;

					}
					else
					{
						no++;
						cout << "," << jj + 1;
					}
					break;
				}
				else if (hh <= sy1 && kk >= sy1 && dd>sx1)
				{
					if (hh == sy1 || kk == sy1)
					{
						if (ffff == 1)
						{
							cc++;
							ffff = 0;
						}

					}
					else
					{
						cc++;
					}
				}
				else if (hh <= sy1 && kk >= sy1 && dd == sx1 && slope1<slope)
				{
					if (hh == sy1 || kk == sy1)
					{
						if (ffff == 1)
						{
							cc++;
							ffff = 0;
						}

					}
					else
					{
						cc++;
					}
				}
				else if (hh<sy1 && kk>sy1 && dd<sx1 && gg>sx1 && slope1<slope)
				{
					cc++;
				}
			}
			else if (hh>kk && gg>dd)
			{


				if (slope == slope1 && hh>sy1 && kk <= sy1)
				{
					if (f == 1)
					{
						no++;
						cout << jj + 1;
						f = 0;

					}
					else
					{
						no++;
						cout << "," << jj + 1;
					}
					ww++;
					break;
				}
				else if (hh>sy1 && kk <= sy1 && gg>sx1 && dd<sx1 && slope1>slope)
				{
					if (hh == sy1 || kk == sy1)
					{
						if (ffff == 1)
						{
							cc++;
							ffff = 0;
						}

					}
					else
					{
						cc++;
					}
				}
				else if (hh>sy1 && kk <= sy1 && dd == sx1 && slope1>slope)
				{
					if (hh == sy1 || kk == sy1)
					{
						if (ffff == 1)
						{
							cc++;
							ffff = 0;
						}

					}
					else
					{
						cc++;
					}
				}
				else if (hh>sy1 && kk<sy1 && dd<sx1 && gg>sx1 && slope1>slope)
				{
					cc++;
				}
			}
			else if (kk>hh && dd>gg)
			{
				if (slope == slope1 && kk>sy1 && hh <= sy1)
				{
					if (f == 1)
					{
						no++;
						cout << jj + 1;
						f = 0;

					}
					else
					{
						no++;
						cout << "," << jj + 1;
					}
					ww++;
					break;
				}
				else if (hh <= sy1 && kk>sy1 && dd>sx1 && gg<sx1 && slope>slope1)
				{
					if (hh == sy1 || kk == sy1)
					{
						if (ffff == 1)
						{
							cc++;
							ffff = 0;
						}

					}
					else
					{
						cc++;
					}
				}
				else if (hh <= sy1 && kk>sy1 && gg == sx1 && slope>slope1)
				{
					if (hh == sy1 || kk == sy1)
					{
						if (ffff == 1)
						{
							cc++;
							ffff = 0;
						}

					}
					else
					{
						cc++;
					}
				}
				else if (hh<sy1 && kk>sy1 && dd>sx1 && gg<sx1 && slope1<slope)
				{
					cc++;
				}
			}
			else if (hh>kk && dd == gg)
			{
				if (hh>sy1 && kk<sy1 && dd == sx1)
				{
					ww++;
					if (f == 1)
					{
						no++;
						cout << jj + 1;
						f = 0;

					}
					else
					{
						no++;
						cout << "," << jj + 1;
					}
					break;
				}
				else if (hh >= sy1 && kk <= sy1 && dd>sx1)
				{
					if (hh == sy1 || kk == sy1)
					{
						if (ffff == 1)
						{
							cc++;
							ffff = 0;
						}

					}
					else
					{
						cc++;
					}
				}
			}
			else if (kk>hh && dd == gg)
			{
				if (hh<sy1 && kk>sy1 && dd == sx1)
				{
					ww++;
					if (f == 1)
					{
						no++;
						cout << jj + 1;
						f = 0;

					}
					else
					{
						no++;
						cout << "," << jj + 1;
					}
					break;
				}
				else if (hh <= sy1 && kk >= sy1 && dd>sx1)
				{
					if (hh == sy1 || kk == sy1)
					{
						if (ffff == 1)
						{
							cc++;
							ffff = 0;
						}

					}
					else
					{
						cc++;
					}
				}
				else if (kk == hh && dd>gg)
				{
					if (slope == slope1)
					{
						ww++;
						if (f == 1)
						{
							no++;
							cout << jj + 1;
							f = 0;

						}
						else
						{
							no++;
							cout << "," << jj + 1;
						}
						break;
					}
				}
				else if (kk == hh && gg>dd)
				{
					if (slope == slope1)
					{
						if (f == 1)
						{
							no++;
							cout << jj + 1;
							f = 0;

						}
						else
						{
							no++;
							cout << "," << jj + 1;
						}
						ww++;
						break;
					}
				}
			}
		}
		if (jj == 8)
		{
			cout << endl << cc;
		}
		if ((cc - 1) % 2 == 0)
		{
			if (ww == 0 && ee == 0)
			{
				if (f == 1)
				{
					no++;
					cout << jj + 1;
					f = 0;

				}
				else
				{
					no++;
					cout << "," << jj + 1;
				}
			}
		}

	}
	if (no == 0)
	{
		cout << "none";
	}
}
int Is_Intersecting(string polygons, string s)
{
	float d, g, h, slope, slope1;
	string px[100][100], py[100][100];
	Redp(polygons, px, py);
	int ffff = 1, cc, no = 0, ee, ww;
	float dd, hh, kk, gg, ff, minx, maxx, miny, maxy;
	float ddd, ggg, hhh, kkk;
	int ii, jj;
	string ss[2];
	ss[0] = s.substr(s.find(" ") + 1, s.find(",") - s.find(" ") - 1);
	ss[1] = s.substr(s.find(",") + 1);
	ii = atof(ss[0].c_str()) - 1;
	jj = atof(ss[1].c_str()) - 1;
	for (int k = 0; k<100; k++)
	{
		if (px[ii][k] == "")
		{
			break;
		}
		ee = 0;
		ww = 0;
		cc = 0;
		g = atof(px[ii][k].c_str());
		ff = atof(py[ii][k].c_str());
		minx = 1000000000000000000;
		maxx = -100000000000000000;
		miny = 1000000000000000000;
		maxy = -100000000000000000;
		for (int u = 0; u<100; u++)
		{
			if (px[jj][u] == "")
			{
				break;
			}
			for (int i = 0; i<100; i++)
			{
				if (px[jj][i] == "")
				{
					break;
				}
				if (atof(px[jj][i].c_str())<minx)
				{
					minx = atof(px[jj][i].c_str());
					ddd = atof(py[jj][i].c_str());
				}
				if (atof(px[jj][i].c_str())>maxx)
				{
					maxx = atof(px[jj][i].c_str());
					ggg = atof(py[jj][i].c_str());
				}
				if (atof(py[jj][i].c_str())<miny)
				{
					miny = atof(py[jj][i].c_str());
					hhh = atof(px[jj][i].c_str());
				}
				if (atof(py[jj][i].c_str())>maxy)
				{
					maxy = atof(py[jj][i].c_str());
					kkk = atof(px[jj][i].c_str());
				}

			}
			for (int u = 0; u<100; u++)
			{
				if (px[jj][u] == "")
				{
					break;
				}
				if (g<minx)
				{
					break;
				}
				if (g>maxx)
				{
					break;
				}
				if (ff<miny)
				{
					break;
				}
				if (ff>maxy)
				{
					break;
				}
				if (ff >= miny && ff<ggg && g >= minx && g<hhh)
				{
					break;
				}
				if (ff <= maxy && ff>ddd && g >= minx && g<kkk)
				{
					break;
				}
				if (px[jj][u + 1] == "")
				{
					d = atof(px[jj][u].c_str());
					h = atof(py[jj][u].c_str());
					slope = (float)(h - ff) / (d - g);

					d = atof(px[jj][0].c_str());
					h = atof(py[jj][0].c_str());
					slope1 = (float)(h - ff) / (d - g);
				}
				else
				{
					d = atof(px[jj][u].c_str());
					h = atof(py[jj][u].c_str());
					slope = (float)(h - ff) / (d - g);

					d = atof(px[jj][u + 1].c_str());
					h = atof(py[jj][u + 1].c_str());
					slope1 = (float)(h - ff) / (d - g);
				}
				if (px[jj][u + 1] == "")
				{
					dd = atof(px[jj][u].c_str());
					hh = atof(py[jj][u].c_str());
					gg = atof(px[jj][0].c_str());
					kk = atof(py[jj][0].c_str());
				}
				else
				{
					dd = atof(px[jj][u].c_str());
					hh = atof(py[jj][u].c_str());
					gg = atof(px[jj][u + 1].c_str());
					kk = atof(py[jj][u + 1].c_str());
				}
				if (px[jj][u] == px[ii][k] && py[jj][u] == py[ii][k])
				{
					no++;
					ee++;
					break;
				}
				else if (hh>kk && dd>gg)
				{
					if (slope == slope1 && hh>ff && kk<ff)
					{
						no++;
						ww++;
						break;
					}

					else if (hh >= ff && kk <= ff && gg>g)
					{
						if (hh == ff || kk == ff)
						{
							if (ffff == 1)
							{
								cc++;
								ffff = 0;
							}

						}
						else
						{
							cc++;
						}

					}
					else if (hh >= ff && kk <= ff && gg == g && slope1>slope)
					{
						if (hh == ff || kk == ff)
						{
							if (ffff == 1)
							{
								cc++;
								ffff = 0;
							}

						}
						else
						{
							cc++;
						}
					}
					else if (hh>ff && kk<ff && dd>g && gg<g && slope1>slope)
					{
						cc++;
					}
				}
				else if (kk>hh && gg>dd)
				{
					if (slope == slope1 && kk>ff && hh<ff)
					{
						ww++;
						no++;
						break;
					}
					else if (hh <= ff && kk >= ff && dd>g)
					{
						if (hh == ff || kk == ff)
						{
							if (ffff == 1)
							{
								cc++;
								ffff = 0;
							}

						}
						else
						{
							cc++;
						}
					}
					else if (hh <= ff && kk >= ff && dd == g && slope1<slope)
					{
						if (hh == ff || kk == ff)
						{
							if (ffff == 1)
							{
								cc++;
								ffff = 0;
							}

						}
						else
						{
							cc++;
						}
					}
					else if (hh<ff && kk>ff && dd<g && gg>g && slope1<slope)
					{
						cc++;
					}
				}
				else if (hh>kk && gg>dd)
				{
					if (slope == slope1 && hh>ff && kk<ff)
					{
						ww++;
						no++;
						break;
					}
					else if (hh >= ff && kk <= ff && dd>g)
					{
						if (hh == ff || kk == ff)
						{
							if (ffff == 1)
							{
								cc++;
								ffff = 0;
							}

						}
						else
						{
							cc++;
						}
					}
					else if (hh >= ff && kk <= ff && dd == g && slope>slope1)
					{
						if (hh == ff || kk == ff)
						{
							if (ffff == 1)
							{
								cc++;
								ffff = 0;
							}

						}
						else
						{
							cc++;
						}
					}
					else if (hh>ff && kk<ff && dd<g && gg>g && slope1>slope)
					{
						cc++;
					}
				}
				else if (kk>hh && dd>gg)
				{
					if (slope == slope1 && kk>ff && hh<ff)
					{
						ww++;
						no++;
						break;
					}
					else if (hh <= ff && kk >= ff && gg>g)
					{
						if (hh == ff || kk == ff)
						{
							if (ffff == 1)
							{
								cc++;
								ffff = 0;
							}

						}
						else
						{
							cc++;
						}
					}
					else if (hh <= ff && kk >= ff && gg == g && slope<slope1)
					{
						if (hh == ff || kk == ff)
						{
							if (ffff == 1)
							{
								cc++;
								ffff = 0;
							}

						}
						else
						{
							cc++;
						}
					}
					else if (hh<ff && kk>ff && dd>g && gg<g && slope1<slope)
					{
						cc++;
					}
				}
				else if (hh>kk && dd == gg)
				{
					if (hh>ff && kk<ff && dd == g)
					{
						ww++;
						no++;
						break;
					}
					else if (hh >= ff && kk <= ff && dd>g)
					{
						if (hh == ff || kk == ff)
						{
							if (ffff == 1)
							{
								cc++;
								ffff = 0;
							}

						}
						else
						{
							cc++;
						}
					}
				}
				else if (kk>hh && dd == gg)
				{
					if (hh<ff && kk>ff && dd == g)
					{
						ww++;
						no++;
						break;
					}
					else if (hh <= ff && kk >= ff && dd>g)
					{
						if (hh == ff || kk == ff)
						{
							if (ffff == 1)
							{
								cc++;
								ffff = 0;
							}

						}
						else
						{
							cc++;
						}
					}
					else if (kk == hh && dd>gg)
					{
						if (slope == slope1)
						{
							ww++;
							no++;
							break;
						}
					}
					else if (kk == hh && gg>dd)
					{
						if (slope == slope1)
						{
							ww++;
							no++;
							break;
						}
					}
				}
			}
			if ((cc - 1) % 2 == 0)
			{
				if (ww == 0 && ee == 0)
				{
					no++;
					break;
				}
			}
		}
	}
	ffff = 1;
	for (int k = 0; k<100; k++)
	{
		if (px[ii][k] == "")
		{
			break;
		}
		ee = 0;
		ww = 0;
		cc = 0;
		g = atof(px[jj][k].c_str());
		ff = atof(py[jj][k].c_str());
		minx = 1000000000000000000;
		maxx = -100000000000000000;
		miny = 1000000000000000000;
		maxy = -100000000000000000;
		for (int u = 0; u<100; u++)
		{
			if (px[jj][u] == "")
			{
				break;
			}
			for (int i = 0; i<100; i++)
			{
				if (px[jj][i] == "")
				{
					break;
				}
				if (atof(px[jj][i].c_str())<minx)
				{
					minx = atof(px[jj][i].c_str());
					ddd = atof(py[jj][i].c_str());
				}
				if (atof(px[jj][i].c_str())>maxx)
				{
					maxx = atof(px[jj][i].c_str());
					ggg = atof(py[jj][i].c_str());
				}
				if (atof(py[jj][i].c_str())<miny)
				{
					miny = atof(py[jj][i].c_str());
					hhh = atof(px[jj][i].c_str());
				}
				if (atof(py[jj][i].c_str())>maxy)
				{
					maxy = atof(py[jj][i].c_str());
					kkk = atof(px[jj][i].c_str());
				}

			}
			for (int u = 0; u<100; u++)
			{
				if (px[jj][u] == "")
				{
					break;
				}
				if (g<minx)
				{
					break;
				}
				if (g>maxx)
				{
					break;
				}
				if (ff<miny)
				{
					break;
				}
				if (ff>maxy)
				{
					break;
				}
				if (ff >= miny && ff<ggg && g >= minx && g<hhh)
				{
					break;
				}
				if (ff <= maxy && ff>ddd && g >= minx && g<kkk)
				{
					break;
				}
				if (px[ii][u + 1] == "")
				{
					d = atof(px[ii][u].c_str());
					h = atof(py[ii][u].c_str());
					slope = (float)(h - ff) / (d - g);

					d = atof(px[ii][0].c_str());
					h = atof(py[ii][0].c_str());
					slope1 = (float)(h - ff) / (d - g);
				}
				else
				{
					d = atof(px[ii][u].c_str());
					h = atof(py[ii][u].c_str());
					slope = (float)(h - ff) / (d - g);

					d = atof(px[ii][u + 1].c_str());
					h = atof(py[ii][u + 1].c_str());
					slope1 = (float)(h - ff) / (d - g);
				}
				if (px[jj][u + 1] == "")
				{
					dd = atof(px[ii][u].c_str());
					hh = atof(py[ii][u].c_str());
					gg = atof(px[ii][0].c_str());
					kk = atof(py[ii][0].c_str());
				}
				else
				{
					dd = atof(px[ii][u].c_str());
					hh = atof(py[ii][u].c_str());
					gg = atof(px[ii][u + 1].c_str());
					kk = atof(py[ii][u + 1].c_str());
				}
				if (px[ii][u] == px[jj][k] && py[ii][u] == py[jj][k])
				{
					no++;
					ee++;
					break;
				}
				else if (hh>kk && dd>gg)
				{
					if (slope == slope1 && hh>ff && kk<ff)
					{
						no++;
						ww++;
						break;
					}

					else if (hh >= ff && kk <= ff && gg>g)
					{
						if (hh == ff || kk == ff)
						{
							if (ffff == 1)
							{
								cc++;
								ffff = 0;
							}

						}
						else
						{
							cc++;
						}

					}
					else if (hh >= ff && kk <= ff && gg == g && slope1>slope)
					{
						if (hh == ff || kk == ff)
						{
							if (ffff == 1)
							{
								cc++;
								ffff = 0;
							}

						}
						else
						{
							cc++;
						}
					}
					else if (hh>ff && kk<ff && dd>g && gg<g && slope1>slope)
					{
						cc++;
					}
				}
				else if (kk>hh && gg>dd)
				{
					if (slope == slope1 && kk>ff && hh<ff)
					{
						ww++;
						no++;
						break;
					}
					else if (hh <= ff && kk >= ff && dd>g)
					{
						if (hh == ff || kk == ff)
						{
							if (ffff == 1)
							{
								cc++;
								ffff = 0;
							}

						}
						else
						{
							cc++;
						}
					}
					else if (hh <= ff && kk >= ff && dd == g && slope1<slope)
					{
						if (hh == ff || kk == ff)
						{
							if (ffff == 1)
							{
								cc++;
								ffff = 0;
							}

						}
						else
						{
							cc++;
						}
					}
					else if (hh<ff && kk>ff && dd<g && gg>g && slope1<slope)
					{
						cc++;
					}
				}
				else if (hh>kk && gg>dd)
				{
					if (slope == slope1 && hh>ff && kk<ff)
					{
						ww++;
						no++;
						break;
					}
					else if (hh >= ff && kk <= ff && dd>g)
					{
						if (hh == ff || kk == ff)
						{
							if (ffff == 1)
							{
								cc++;
								ffff = 0;
							}

						}
						else
						{
							cc++;
						}
					}
					else if (hh >= ff && kk <= ff && dd == g && slope>slope1)
					{
						if (hh == ff || kk == ff)
						{
							if (ffff == 1)
							{
								cc++;
								ffff = 0;
							}

						}
						else
						{
							cc++;
						}
					}
					else if (hh>ff && kk<ff && dd<g && gg>g && slope1>slope)
					{
						cc++;
					}
				}
				else if (kk>hh && dd>gg)
				{
					if (slope == slope1 && kk>ff && hh<ff)
					{
						ww++;
						no++;
						break;
					}
					else if (hh <= ff && kk >= ff && gg>g)
					{
						if (hh == ff || kk == ff)
						{
							if (ffff == 1)
							{
								cc++;
								ffff = 0;
							}

						}
						else
						{
							cc++;
						}
					}
					else if (hh <= ff && kk >= ff && gg == g && slope<slope1)
					{
						if (hh == ff || kk == ff)
						{
							if (ffff == 1)
							{
								cc++;
								ffff = 0;
							}

						}
						else
						{
							cc++;
						}
					}
					else if (hh<ff && kk>ff && dd>g && gg<g && slope1<slope)
					{
						cc++;
					}
				}
				else if (hh>kk && dd == gg)
				{
					if (hh>ff && kk<ff && dd == g)
					{
						ww++;
						no++;
						break;
					}
					else if (hh >= ff && kk <= ff && dd>g)
					{
						if (hh == ff || kk == ff)
						{
							if (ffff == 1)
							{
								cc++;
								ffff = 0;
							}

						}
						else
						{
							cc++;
						}
					}
				}
				else if (kk>hh && dd == gg)
				{
					if (hh<ff && kk>ff && dd == g)
					{
						ww++;
						no++;
						break;
					}
					else if (hh <= ff && kk >= ff && dd>g)
					{
						if (hh == ff || kk == ff)
						{
							if (ffff == 1)
							{
								cc++;
								ffff = 0;
							}

						}
						else
						{
							cc++;
						}
					}
					else if (kk == hh && dd>gg)
					{
						if (slope == slope1)
						{
							ww++;
							no++;
							break;
						}
					}
					else if (kk == hh && gg>dd)
					{
						if (slope == slope1)
						{
							ww++;
							no++;
							break;
						}
					}
				}
			}
			if ((cc - 1) % 2 == 0)
			{
				if (ww == 0 && ee == 0)
				{
					no++;
					break;
				}
			}
		}
	}
	return no;
}
void Intersecting_Group(string polygons, string s)
{
	int aa[2], aaa = 0, e = 0, no;
	string ss[3];
	for (int i = 0; i<s.length(); i++)
	{
		if (s[i] == ',')
		{
			aa[aaa] = i;
			aaa++;
		}
	}
	ss[0] = s.substr(s.find(' ') + 1, s.find(",") - s.find(' ') - 1);
	ss[1] = s.substr(aa[0] + 1, aa[1] - aa[0] - 1);
	ss[2] = s.substr(aa[1] + 1);
	string sss = "Intersecting_Group " + ss[0] + "," + ss[1];
	string ssss = "Intersecting_Group " + ss[0] + "," + ss[2];
	string sssss = "Intersecting_Group " + ss[1] + "," + ss[2];
	no = Is_Intersecting(polygons, sss);
	if (no>0)
	{
		e++;
	}
	no = Is_Intersecting(polygons, ssss);
	if (no>0)
	{
		e++;
	}
	no = Is_Intersecting(polygons, sssss);
	if (no>0)
	{
		e++;
	}
	if (e == 3)
	{
		cout << "True";
	}
	else
	{
		cout << "False";
	}

}
void Largest_Intersecting_Pair(string polygons)
{
	float d, g, h, slope, slope1;
	string px[100][100], py[100][100];
	Redp(polygons, px, py);
	string x1[10000], y1[10000];
	int re;
	Redxy(polygons, x1, y1, re);
	float area[100];
	int ar = 0;
	for (int i = 0; i<re; i++)
	{
		if (x1[i] == "")
		{

		}
		else if (x1[i] == ";")
		{
			for (int j = i + 1; j<re; j++)
			{
				if (x1[j] == ";")
				{
					float  f1 = atof(x1[i + 1].c_str());
					float  f2 = atof(x1[j - 1].c_str());
					float  p1 = atof(y1[i + 1].c_str());
					float  p2 = atof(y1[j - 1].c_str());
					area[ar] = area[ar] + (f2*p1 - p2*f1);
					break;
				}
			}
		}
		else
		{
			float  f1 = atof(x1[i].c_str());
			float  f2 = atof(x1[i + 1].c_str());
			float  p1 = atof(y1[i].c_str());
			float  p2 = atof(y1[i + 1].c_str());
			if (x1[i + 1] == ";")
			{
				ar++;
				continue;
			}
			area[ar] = area[ar] + (f1*p2 - p1*f2);
		}
	}
	for (int i = 0; i<ar; i++)
	{
		area[i] = fabs(area[i] / 2);
	}

	int ty, yu;
	float largest, larg = -100000000000000;
	int ii, jj;
	float dd, hh, kk, gg, ff, ffff, minx, maxx, miny, maxy;
	float ddd, ggg, hhh, kkk;
	int cc, no = 0, ee, ww;
	for (ii = 0; ii<100; ii++)
	{
		if (px[ii][0] == "")
		{
			break;
		}
		for (jj = 0; jj<100; jj++)
		{
			if (px[jj][0] == "")
			{
				break;
			}
			no = 0;
			if (jj == ii)
			{
				continue;
			}
			for (int k = 0; k<100; k++)
			{
				if (px[ii][k] == "")
				{
					break;
				}
				ee = 0;
				ww = 0;
				cc = 0;
				g = atof(px[ii][k].c_str());
				ff = atof(py[ii][k].c_str());
				minx = 1000000000000000000;
				maxx = -100000000000000000;
				miny = 1000000000000000000;
				maxy = -100000000000000000;
				for (int u = 0; u<100; u++)
				{
					if (px[jj][u] == "")
					{
						break;
					}
					for (int i = 0; i<100; i++)
					{
						if (px[jj][i] == "")
						{
							break;
						}
						if (atof(px[jj][i].c_str())<minx)
						{
							minx = atof(px[jj][i].c_str());
							ddd = atof(py[jj][i].c_str());
						}
						if (atof(px[jj][i].c_str())>maxx)
						{
							maxx = atof(px[jj][i].c_str());
							ggg = atof(py[jj][i].c_str());
						}
						if (atof(py[jj][i].c_str())<miny)
						{
							miny = atof(py[jj][i].c_str());
							hhh = atof(px[jj][i].c_str());
						}
						if (atof(py[jj][i].c_str())>maxy)
						{
							maxy = atof(py[jj][i].c_str());
							kkk = atof(px[jj][i].c_str());
						}

					}

					if (g<minx)
					{
						break;
					}
					if (g>maxx)
					{
						break;
					}
					if (ff<miny)
					{
						break;
					}
					if (ff>maxy)
					{
						break;
					}
					if (ff >= miny && ff<ggg && g >= minx && g<hhh)
					{
						break;
					}
					if (ff <= maxy && ff>ddd && g >= minx && g<kkk)
					{
						break;
					}
					if (px[jj][u + 1] == "")
					{
						d = atof(px[jj][u].c_str());
						h = atof(py[jj][u].c_str());
						slope = (float)(h - ff) / (d - g);

						d = atof(px[jj][0].c_str());
						h = atof(py[jj][0].c_str());
						slope1 = (float)(h - ff) / (d - g);
					}
					else
					{
						d = atof(px[jj][u].c_str());
						h = atof(py[jj][u].c_str());
						slope = (float)(h - ff) / (d - g);

						d = atof(px[jj][u + 1].c_str());
						h = atof(py[jj][u + 1].c_str());
						slope1 = (float)(h - ff) / (d - g);
					}
					if (px[jj][u + 1] == "")
					{
						dd = atof(px[jj][u].c_str());
						hh = atof(py[jj][u].c_str());
						gg = atof(px[jj][0].c_str());
						kk = atof(py[jj][0].c_str());
					}
					else
					{
						dd = atof(px[jj][u].c_str());
						hh = atof(py[jj][u].c_str());
						gg = atof(px[jj][u + 1].c_str());
						kk = atof(py[jj][u + 1].c_str());
					}
					if (px[jj][u] == px[ii][k] && py[jj][u] == py[ii][k])
					{
						no++;
						ee++;
						break;
					}
					else if (hh>kk && dd>gg)
					{
						if (slope == slope1 && hh>ff && kk<ff)
						{
							no++;
							ww++;
							break;
						}

						else if (hh >= ff && kk <= ff && gg>g)
						{
							if (hh == ff || kk == ff)
							{
								if (ffff == 1)
								{
									cc++;
									ffff = 0;
								}

							}
							else
							{
								cc++;
							}

						}
						else if (hh >= ff && kk <= ff && gg == g && slope1>slope)
						{
							if (hh == ff || kk == ff)
							{
								if (ffff == 1)
								{
									cc++;
									ffff = 0;
								}

							}
							else
							{
								cc++;
							}
						}
						else if (hh>ff && kk<ff && dd>g && gg<g && slope1>slope)
						{
							cc++;
						}
					}
					else if (kk>hh && gg>dd)
					{
						if (slope == slope1 && kk>ff && hh<ff)
						{
							ww++;
							no++;
							break;
						}
						else if (hh <= ff && kk >= ff && dd>g)
						{
							if (hh == ff || kk == ff)
							{
								if (ffff == 1)
								{
									cc++;
									ffff = 0;
								}

							}
							else
							{
								cc++;
							}
						}
						else if (hh <= ff && kk >= ff && dd == g && slope1<slope)
						{
							if (hh == ff || kk == ff)
							{
								if (ffff == 1)
								{
									cc++;
									ffff = 0;
								}

							}
							else
							{
								cc++;
							}
						}
						else if (hh<ff && kk>ff && dd<g && gg>g && slope1<slope)
						{
							cc++;
						}
					}
					else if (hh>kk && gg>dd)
					{
						if (slope == slope1 && hh>ff && kk<ff)
						{
							ww++;
							no++;
							break;
						}
						else if (hh >= ff && kk <= ff && dd>g)
						{
							if (hh == ff || kk == ff)
							{
								if (ffff == 1)
								{
									cc++;
									ffff = 0;
								}

							}
							else
							{
								cc++;
							}
						}
						else if (hh >= ff && kk <= ff && dd == g && slope>slope1)
						{
							if (hh == ff || kk == ff)
							{
								if (ffff == 1)
								{
									cc++;
									ffff = 0;
								}

							}
							else
							{
								cc++;
							}
						}
						else if (hh>ff && kk<ff && dd<g && gg>g && slope1>slope)
						{
							cc++;
						}
					}
					else if (kk>hh && dd>gg)
					{
						if (slope == slope1 && kk>ff && hh<ff)
						{
							ww++;
							no++;
							break;
						}
						else if (hh <= ff && kk >= ff && gg>g)
						{
							if (hh == ff || kk == ff)
							{
								if (ffff == 1)
								{
									cc++;
									ffff = 0;
								}

							}
							else
							{
								cc++;
							}
						}
						else if (hh <= ff && kk >= ff && gg == g && slope<slope1)
						{
							if (hh == ff || kk == ff)
							{
								if (ffff == 1)
								{
									cc++;
									ffff = 0;
								}

							}
							else
							{
								cc++;
							}
						}
						else if (hh<ff && kk>ff && dd>g && gg<g && slope1<slope)
						{
							cc++;
						}
					}
					else if (hh>kk && dd == gg)
					{
						if (hh>ff && kk<ff && dd == g)
						{
							ww++;
							no++;
							break;
						}
						else if (hh >= ff && kk <= ff && dd>g)
						{
							if (hh == ff || kk == ff)
							{
								if (ffff == 1)
								{
									cc++;
									ffff = 0;
								}

							}
							else
							{
								cc++;
							}
						}
					}
					else if (kk>hh && dd == gg)
					{
						if (hh<ff && kk>ff && dd == g)
						{
							ww++;
							no++;
							break;
						}
						else if (hh <= ff && kk >= ff && dd>g)
						{
							if (hh == ff || kk == ff)
							{
								if (ffff == 1)
								{
									cc++;
									ffff = 0;
								}

							}
							else
							{
								cc++;
							}
						}
					}
					else if (kk == hh && dd>gg)
					{
						if (slope == slope1)
						{
							ww++;
							no++;
							break;
						}
					}
					else if (kk == hh && gg>dd)
					{
						if (slope == slope1)
						{
							ww++;
							no++;
							break;
						}
					}
				}
				if ((cc - 1) % 2 == 0)
				{
					if (ww == 0 && ee == 0)
					{
						no++;
					}
				}
			}
			if (no>0)
			{
				largest = area[ii] + area[jj];
				if (largest>larg)
				{
					larg = largest;
					ty = ii + 1;
					yu = jj + 1;
				}
			}
		}
	}
	cout << ty << "," << yu;
}






int main()
{
	int n, no;
	float minX, maxX, minY, maxY;
	string polygons, operation, s1, s2;
	polygons = "[(1,1),(2,2),(1,3),(0,2);(0,1),(3,3),(1,6),(-2,4);(2,3),(5,3),(4,8);(7,7),(6,8),(4,11),(3,10),(2,5),(3,3),(3,3),(5,5),(5,5),(7,7);(4,5),(7,8),(6,11),(3,8);(2,6),(5,8),(5,13),(1,11);(0,6),(2,10),(2,12),(-1,13),(-2,11),(-2,7);(-5,5),(-1,5),(-1,10),(-1,10),(-5,12);(-4,4),(-1,8),(-2,10),(-4,4);(-5,3),(-3,3),(-1,3),(-3,7),(-5,6);(-2,-1),(-4,-4),(-4,-7),(-2,-9),(-2,-4),(-2,-1);(-2,-7),(-4,-10),(-1,-12);(-1,-6)(-3,-6),(-2,-9),(1,-11),(3,-6),(0,-6),(-1,-6);(1,-9),(4,-2),(7,-5),(4,-11);(5,-5),(1,-3),(4,1),(7,2),(7,-6);(-1,1),(-2,2),(3,5),(4,4)]";
	while (1)
	{
		getline(cin, operation);
		int i;
		for (i = 0; i<operation.length(); i++)
		{
			if (operation[i] == ' ')
			{
				break;
			}
		}
		if (operation[i] == ' ')
		{
			if (operation[operation.find(" ") + 1] == 'M')
			{
				s1 = operation.substr(0, operation.find(" ") + 5);
			}
			else if (operation[operation.find(" ") + 1] == 'L')
			{
				s1 = operation.substr(0, operation.find(" ") + 5);
			}
			else if (operation[operation.find(" ") + 1] == 'E')
			{
				s1 = operation.substr(0, operation.find(" ") + 6);
			}
			else if (operation[operation.find(" ") + 1] != 'M' || operation[operation.find(" ") + 1] != 'L' || operation[operation.find(" ") + 1] != 'E')
			{
				s1 = operation.substr(0, operation.find(" "));
			}
		}
		else
		{
			s1 = operation;
		}
		if (s1 == "Number_Polygons")
		{

			Number_Polygons(polygons);
			cout << endl;
		}
		else if (s1 == "Total_Number_Points")
		{
			Total_Number_Points(polygons);
			cout << endl;
		}
		else if (s1 == "Minimum_X")
		{
			minX = Minimum_X(polygons);
			cout << minX;
			cout << endl;
		}
		else if (s1 == "Maximum_X")
		{
			maxX = Maximum_X(polygons);
			cout << maxX;
			cout << endl;
		}
		else if (s1 == "Minimum_Y")
		{
			minY = Minimum_Y(polygons);
			cout << minY;
			cout << endl;
		}
		else if (s1 == "Maximum_Y")
		{
			maxY = Maximum_Y(polygons);
			cout << maxY;
			cout << endl;
		}
		else if (s1 == "Enclosing_Rectangle")
		{
			minX = Minimum_X(polygons);
			maxX = Maximum_X(polygons);
			minY = Minimum_Y(polygons);
			maxY = Maximum_Y(polygons);
			cout << "(" << minX << "," << minY << ")" << "," << "(" << maxX << "," << minY << ")" << "," << "(" << maxX << "," << maxY << ")" << "," << "(" << minX << "," << maxY << ")";
			cout << endl;
		}
		else if (s1 == "Total_Redundant_Points")
		{
			n = Total_Redundant_Points(polygons);
			if (n == 0)
			{
				cout << "none";
				cout << endl;
			}
			else
			{
				cout << n;
				cout << endl;
			}
		}
		else if (s1 == "Polygon_Points")
		{
			n = atof(operation.substr(operation.find(" ") + 1).c_str());
			Polygon_Points(polygons, n);
			cout << endl;
		}
		else if (s1 == "Point_Polygons")
		{
			s2 = operation.substr(operation.find(" ") + 1);
			Point_Polygons(polygons, s2);
			cout << endl;
		}
		else if (s1 == "List_Polygons_Points More")
		{
			n = atof(operation.substr(s1.length() + 1).c_str());
			List_Polygons_PointsMore(polygons, n);
			cout << endl;
		}
		else if (s1 == "List_Polygons_Points Less")
		{
			n = atof(operation.substr(s1.length() + 1).c_str());
			List_Polygons_PointsLess(polygons, n);
			cout << endl;
		}
		else if (s1 == "List_Polygons_Points Equal")
		{
			n = atof(operation.substr(s1.length() + 1).c_str());
			List_Polygons_PointsEqual(polygons, n);
			cout << endl;
		}
		else if (s1 == "List_Points_Polygons More")
		{
			n = atof(operation.substr(s1.length() + 1).c_str());
			List_Points_PolygonsMore(polygons, n);
			cout << endl;
		}
		else if (s1 == "List_Points_Polygons Less")
		{
			n = atof(operation.substr(s1.length() + 1).c_str());
			List_Points_PolygonsLess(polygons, n);
			cout << endl;
		}
		else if (s1 == "List_Points_Polygons Equal")
		{
			n = atof(operation.substr(s1.length() + 1).c_str());
			List_Points_PolygonsEqual(polygons, n);
			cout << endl;
		}
		else if (s1 == "Polygon_Perimeter")
		{
			n = atof(operation.substr(operation.find(" ") + 1).c_str());
			Polygon_Perimeter(polygons, n);
			cout << endl;
		}
		else if (s1 == "List_Triangles")
		{
			List_Triangles(polygons);
			cout << endl;
		}
		else if (s1 == "List_Rectangles")
		{
			List_Rectangles(polygons);
			cout << endl;
		}
		else if (s1 == "List_Trapezoid")
		{
			List_Trapezoid(polygons);
			cout << endl;
		}
		else if (s1 == "Inside_Rectangle")
		{
			Inside_Rectangle(polygons, operation);
			cout << endl;
		}
		else if (s1 == "Inside_Circle")
		{
			Inside_Circle(polygons, operation);
			cout << endl;
		}
		else if (s1 == "Polygon_Area")
		{
			n = atof(operation.substr(operation.find(" ") + 1).c_str());
			Polygon_Area(polygons, n);
			cout << endl;
		}
		else if (s1 == "Polygons_Area_Range")
		{
			Polygons_Area_Range(polygons, operation);
			cout << endl;
		}
		else if (s1 == "Polygons_Enclosing_Point")
		{
			Polygons_Enclosing_Point(polygons, operation);
			cout << endl;
		}
		else if (s1 == "Is_Intersecting")
		{
			no = Is_Intersecting(polygons, operation);
			if (no>0)
			{
				cout << "TRUE";
				cout << endl;
			}
			else
			{
				cout << "False";
				cout << endl;
			}
		}
		else if (s1 == "Intersecting_Group")
		{
			Intersecting_Group(polygons, operation);
			cout << endl;
		}
		else if (s1 == "Largest_Intersecting_Pair")
		{
			Largest_Intersecting_Pair(polygons);
			cout << endl;
		}
		else if (operation == "Quit")
		{
			break;
		}
		else;
		{
			continue;
		}

	}
	return 0;
}
