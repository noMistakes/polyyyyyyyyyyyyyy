#include "Header.h"
#include <iostream>
#include <string>
using namespace lib;
void main()
{
	string comands;
	Poly test;
	while (true)
	{
		cin >> comands;
		if (comands == "new")
		{
			int N;
			cout << "size:";
			cin >> N;
			double x, y;
			for (int i = 0; i < N; i++)
			{
				cout << "x,y:";
				cin >> x; cin >> y;
				Point f(x, y);
				test.pushback(Point(x, y));
			}
			test.print();
		}
		
		else if (comands == "move")
		{
			double x, y;
			cout << "x,y:";
			cin >> x >> y;
			Point A(x, y);
			test += A;
			test.print();
		}
		else if (comands == "expand")
		{
			double C;
			cout << "Koef:";
			cin >> C;
			test *= C;
			test.print();
		}

		else
		{
			cout << "\n\n\n\n\n\n\n\n\\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			/*polygon.draw();*/
		}
	}
		
	system("pause");
	}