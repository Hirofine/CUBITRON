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

int main(){
    Point p1(5,25),p2(10,80);
    afficher(p1);
    cout<<"\n";
    afficher(p2);
    cout<<"\n";
    Segment s = Segment();
    afficher(s);
    s.transpose(20,0);
    afficher(s);
    p1.move(80,0);
    afficher(s);
    afficher(p1);
    return 0;
}
