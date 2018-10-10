#include "elements.h"
#include <iostream>

using namespace std;

void afficher(Point p){
	cout<<"x : "<<p.getX()<<" , y : "<<p.getY()<<" ";
}

void afficher(Segment s){
	cout<<"Coordonnee du Segment : ";
	cout<<"\n";
	cout<<"P1 : ";
	afficher(s.getP1());
	cout<<"\nP2 : ";
	afficher(s.getP2());
	cout<<"\n";
}

void afficher(Triangle t){
	cout<<"P1 : ";
	afficher(t.getP1());
	cout<<"\nP2 : ";
	afficher(t.getP2());
	cout<<"\nP3 : ";
	afficher(t.getP3());
	cout<<"\n";
}

void afficher(Polygone p){
	for (int i = 0; i < p.getNbrePts(); ++i)
	{
		cout<<"P"<< i+1 <<" : ";
		afficher(p.getP(i));
	}
}


int main(){
    Segment s = Segment();
    afficher(s);
    Triangle t = Triangle(Point(10,50), Point(100,70), Point(90,60));
    afficher(t);
    Polygone p = Polygone(4, Point(60,50), Point(10,70), Point(25,60), Point(75,50));
    afficher(p);
    p.addP(Point(89, 70));
    afficher(p);
    p.deleteP(2);
    afficher(p);
}
