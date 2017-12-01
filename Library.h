#pragma once
#include <iostream>
#ifdef O_EXPORTS   
#define O_API __declspec(dllexport)    
#else   
#define O_API __declspec(dllimport)    
#endif   

using namespace std;

namespace lib
{

	

	class Point
	{
	protected:
		double x;
		double y;
	public:

		Point()
		{
			x = INT_MIN;
			y = INT_MIN;
		}

		Point(const Point& _point)
		{
			x = _point.x;
			y = _point.y;
		}

		Point(double _x, double _y) :x(_x), y(_y)
		{

		}

		double get_x()const
		{
			return x;
		}

		double get_y()const
		{
			return y;
		}

		void set_x(double _x)
		{
			x = _x;
		}

		void set_y(double _y)
		{
			y = _y;
		}

		Point& operator=(const Point& object)
		{
			x = object.x;
			y = object.y;
			return *this;
		}

		Point& operator+=(const Point& rizn)
		{
			x += rizn.x;
			y += rizn.y;
			return *this;
		}

		Point operator+(const Point& rizn)
		{
			Point result(x, y);
			result += rizn;
			return result;;
		}

		Point& operator-=(const Point& rizn)
		{
			x -= rizn.x;
			y -= rizn.y;
			return *this;
		}

		Point operator-(const Point& rizn)
		{
			Point result(x, y);
			result -= rizn;
			return result;
		}

		friend Point& operator * (double koef, Point& rizn)
		{
			rizn.x *= koef;
			rizn.y *= koef;
			return rizn;
		}

		~Point()
		{

		}

		void print()
		{
			if (x != INT_MIN && y != INT_MIN)
			{
				cout << '(' << x << "," << y << ") ";
			}
			else
			{
				cout << "NULL" << endl;
			}
		}
	};

	struct Node
	{
		Point point;
		Node *next;
		Node *previous;
		void print()
		{
			point.print();
		}
		Node(Point _point)
		{
			point.set_x(_point.get_x());
			point.set_y(_point.get_y());

			next = NULL;
			previous = NULL;
		}
		Point& get_point()
		{
			return point;
		}
	};

	class Poly
	{
	protected:
		Node* head;
		Node* tail;
	public:
		Poly()
		{
			head = NULL;
			tail = NULL;
		}

		Poly(const Poly& object)
		{
			Node* ptr = object.head;
			head = NULL;
			tail = NULL;
			while (ptr != NULL)
			{
				pushback(ptr->get_point());
				ptr = ptr->next;
			}
		}

		~Poly()
		{
			if (head == NULL)
			{
				return;
			}

			Node* ptr = head;
			while (ptr != NULL)
			{
				head = head->next;
				delete ptr;
				ptr = head;
			}
		}

		Poly& operator = (const Poly& object)
		{
			Node* ptr = head;
			while (ptr != NULL)
			{
				head = head->next;
				delete ptr;
				ptr = head;
			}

			ptr = object.head;
			while (ptr != NULL)
			{
				pushback(ptr->get_point());
				ptr = ptr->next;
			}

			return *this;
		}

		Poly& operator *= (double index)
		{
			if (index > 0)
			{
				Point mass_centr(0, 0);
				int size = 0;
				Node* ptr = head;

				while (ptr != NULL)
				{

					mass_centr += ptr->get_point();
					ptr = ptr->next;
					size++;
				}

				if (size != 0)//finding center
				{
					mass_centr.set_x(mass_centr.get_x() / size);
					mass_centr.set_y(mass_centr.get_y() / size);

					cout << "Center of mass ";
					mass_centr.print();
					cout << endl;

					ptr = head;

					while (ptr != NULL)
					{
						ptr->get_point() = mass_centr + index*(ptr->get_point() - mass_centr);
						ptr = ptr->next;
					}

				}

			}
			return *this;
		}

		Poly operator * (double ind)
		{
			Poly result(*this);
			result *= ind;
			return result;

		}

		Poly& operator +=(const Point& rizn)
		{

			Node* ptr = head;
			while (ptr != NULL)
			{
				ptr->get_point() += rizn;
				ptr = ptr->next;

			}

			return *this;
		}

		Poly operator +(const Point& object)
		{
			Poly result(*this);
			result += object;
			return result;
		}

		void  pushback(Point& _point)
		{
			if (head != NULL)
			{
				tail->next = new Node(_point);
				tail->next->previous = tail;
				tail = tail->next;
			}
			else
			{
				head = new Node(_point);
				tail = head;
			}
		}

		//void  push_begin(Point& _point)
		//{
		//	if (head != NULL)
		//	{
		//		Node* ptr = new Node(_point);
		//		ptr->next = head;
		//		head->previous = ptr;
		//		head = ptr;
		//	}
		//	else
		//	{
		//		head = new Node(_point);
		//		tail = head;
		//	}
		//}

		void  pop_begin()
		{
			if (tail != NULL)
			{
				if (tail == head)
				{
					delete head;
					head = NULL;
					tail = NULL;
				}
				else
				{
					tail = tail->previous;
					delete tail->next;
					tail->next = NULL;
				}
			}
		}


		void clear()
		{
			while (head != NULL)
			{
				pop_begin();
			}
		}

		void  print()const
		{
			if (head == NULL)
			{
				cout << "Poly is empty." << endl;
				return;
			}

			Node* ptr = head;
			while (ptr != NULL)
			{
				ptr->point.print();
				ptr = ptr->next;
			}
			cout << endl;
		}


	};


}