#ifndef _PERSO_H_
#define _PERSO_H_

#include <SDL/SDL.h>
#include <cmath>
#include <iostream>

class Perso{
public:
  Perso();
  
  void setDirX(int dir);
  void setDirY(int dir);
  void setSpeedx(int speed);
  void setSpeedy(float speed);
  void fall();
  void jump();
  void setX(int x);
  void setY(int y);
  
  int getSpeedx();
  float getSpeedy();
  int getX();
  int getY();
  int getDirX();
  int getDirY();
  int getWidth();
  int getHeight();
  
  bool collide();
  void draw();
private:
  int posx_;
  int posy_;
  int width_;
  int height_;
  int speedx_;
  float speedy_;
  int dirx_;
  int diry_;
  
};

#endif
