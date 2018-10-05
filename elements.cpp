#include "elements.h"

	/* init */
Point::Point() : x_(0),y_(0){}

Point::Point(int x, int y) : x_(x), y_(y){}

Point::Point(const Point &p){
	x_ = p.x_;
	y_ = p.y_;
}

	/* all setters */
void Point::setX(int x){
	x_ = x;
}

void Point::setY(int y){
	y_ = y;
}

void Point::moveX(int x){
	x_ += x;
}

void Point::moveY(int y){
	y_ += y;
}

	/* all getters */
int Point::getX(){
	return x_;
}

int Point::getY(){
	return y_;
}

	/* destroy*/
Point::~Point(){}

// Segment
	/* init */
Segment::Segment(){
	p1_ = new Point();
	p2_ = new Point();
}
Segment::Segment(Point *p1, Point *p2){
	p1_ = p1;
	p2_ = p2;
}
Segment::Segment(const Segment &s){
	p1_ = new Point();
	p2_ = new Point();
	*p1_= *s.p1_;
	*p2_= *s.p2_;
}


	/* all setters */
void Segment::setP1(int x, int y){
	p1_->setX(x);
	p1_->setY(y);
}

void Segment::setP2(int x, int y){
	p2_->setX(x);
	p2_->setY(y);
}


void Segment::transposeX(int x){
	p1_->moveX(x);
	p2_->moveX(x);
}
void Segment::transposeY(int y){
	p1_->moveY(y);
	p2_->moveY(y);
}

	/* all getters */
Point Segment::getP1(){return *p1_;}

Point Segment::getP2(){return *p2_;}

	/*destroy*/
Segment::~Segment(){}
