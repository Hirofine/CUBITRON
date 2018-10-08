#include "elements.h"

	/* init */
Point::Point() : x_(0),y_(0){}

Point::Point(int x, int y) : x_(x), y_(y){}

Point::Point(const Point &p): x_(0),y_(0){
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

void Point::move(int x, int y){
	x_ += x;
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
Segment::Segment():p1_(Point()), p2_(Point()){
}
Segment::Segment(Point p1, Point p2): p1_(Point()), p2_(Point()){
	p1_ = p1;
	p2_ = p2;
}
Segment::Segment(const Segment &s):p1_(Point()), p2_(Point()){
	p1_= s.p1_;
	p2_= s.p2_;
}


	/* all setters */
void Segment::setP1(int x, int y){
	p1_.setX(x);
	p1_.setY(y);
}

void Segment::setP2(int x, int y){
	p2_.setX(x);
	p2_.setY(y);
}


void Segment::transpose(int x, int y){
	p1_.move(x,0);
	p2_.move(x,0);
	p1_.move(0,y);
	p2_.move(0,y);
}

	/* all getters */
Point Segment::getP1(){return p1_;}

Point Segment::getP2(){return p2_;}

	/*destroy*/
Segment::~Segment(){}

// Triangle
	/* init */
Triangle::Triangle():p1_(Point()), p2_(Point()), p3_(Point()){
	p1_.setX(0);
	p1_.setY(0);
	p2_.setX(0);
	p2_.setY(0);
	p3_.setX(0);
	p3_.setY(0);
}
Triangle::Triangle(Point p1, Point p2, Point p3):p1_(Point()), p2_(Point()), p3_(Point()){
	p1_ = p1;
	p2_ = p2;
	p3_ = p3;
}
Triangle::Triangle(Segment s, Point p):p1_(Point()), p2_(Point()), p3_(Point()){
	p1_ = s.getP1();
	p2_ = s.getP2();
	p3_ = p;
}
Triangle::Triangle(const Triangle &t):p1_(Point()), p2_(Point()), p3_(Point()){
	p1_ = t.p1_;
	p2_ = t.p2_;
	p3_ = t.p3_;
}

	/*setters*/
void Triangle::transpose(int x, int y){
	p1_.move(x,0);
	p2_.move(x,0);
	p3_.move(x,0);
	p1_.move(0,y);
	p2_.move(0,y);
	p3_.move(0,y);
}

	/*getters*/
Point Triangle::getP1(){
	return p1_;
}
Point Triangle::getP2(){
	return p2_;
}
Point Triangle::getP3(){
	return p3_;
}
