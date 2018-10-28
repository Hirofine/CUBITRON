#ifndef _PERSO_H_
#define _PERSO_H_

#define GRAVITY -0.01
#define JUMP_SPEED 2.3
#define DASH_VAL 200
#define PERSO_SIZE 100

#include <SDL/SDL.h>
#include <cmath>
#include <iostream>
#include "map.h"

class Perso{
public:
  Perso();
  
  void setDirX(int dir);
  void setDirY(int dir);
  void setSpeedx(int speed);
  void setSpeedy(float speed);
  void fall(Map map);
  void jump();
  void dash(Map map);
  void setX(int x);
  void setY(int y);
  void setIsJumping(int val);
  void setOrientation(int orientation);
  
  int getSpeedx();
  float getSpeedy();
  int getX();
  int getY();
  int getDirX();
  int getDirY();
  int getWidth();
  int getHeight();
  int getOrientation();
  
  bool collide(Map map, int posx, int posy);
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
  int orientation_;
  
  Uint32 initJump_;
  Uint32 initFall_;
  int initFallPosy_;
  float initFallSpeedy_;
  int isJumping_;
  
};

#endif
