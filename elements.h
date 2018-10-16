#ifndef _ELEMENTS_
#define _ELEMENTS_

#include <vector>
#include "stdarg.h"

class Point{
	public:
        Point();
		Point(int x, int y);
		Point(const Point &p);
		~Point();

		void setX(int x);
		void setY(int y);
		void move(int x, int y);

		int getX();
		int getY();

	private:
		int x_;
		int y_;
};

class Segment{
	public:
		Segment();
		Segment(Point p1, Point p2);
		Segment(const Segment &s);
		~Segment();

		void setP1(int x, int y);
		void setP2(int x, int y);
		void transpose(int x, int y);


		Point getP1();
		Point getP2();

	private:
		Point p1_;
		Point p2_;

};

class Triangle{
	public:
		Triangle();
		Triangle(Point p1, Point p2, Point p3);
		Triangle(Segment s, Point p);
		Triangle(const Triangle &t);
		~Triangle();

		void transpose(int x, int y);

		Point getP1();
		Point getP2();
		Point getP3();
	private:
		Point p1_;
		Point p2_;
		Point p3_;
};

class Polygone{
	public:
		Polygone();
		Polygone(int n, ...);
		Polygone(Point *tab, int taille);

		void addP(Point p);
		void deleteP(unsigned int n);

		Point getP(unsigned int n);
		unsigned int getNbrePts();
	private:
		std::vector<Point> tp;
		int nbreP;
};

#endif
