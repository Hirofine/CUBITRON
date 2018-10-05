#ifndef _ELEMENTS_
#define _ELEMENTS_


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
		Segment(Point *p1, Point *p2);
		Segment(const Segment &s);
		~Segment();

		void setP1(int x, int y);
		void setP2(int x, int y);
		void transpose(int x, int y);


		Point getP1();
		Point getP2();

	private:
		Point *p1_;
		Point *p2_;

};

#endif
