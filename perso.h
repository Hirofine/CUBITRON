#ifndef _PERSO_H_
#define _PERSO_H_

#define GRAVITY -0.01
#define JUMP_SPEED 2.3
#define DASH_VAL 200
#define PERSO_SIZE 50
#define PERSO_SPEED 4

#include <SDL/SDL.h>
#include <cmath>
#include <iostream>
#include <string>
#include "map.h"

using namespace std;

class Perso{
public:
  Perso();
  
  void setDirX(int dir);
  void setDirY(int dir);
  void setSpeedx(int speed);
  void setSpeedy(float speed);
  void fall();
  void jump();
  void dash(Map map);
  void setX(int x);
  void setY(int y);
  void setIsJumping(int val);
  void incIsJumping();
  void setOrientation(int orientation);
  void hit(int damage);
  void animHit();
  void setNom(char nom[]);
  
  int getSpeedx();
  float getSpeedy();
  int getX();
  int getY();
  int getDirX();
  int getDirY();
  int getWidth();
  int getHeight();
  int getOrientation();
  int getHealth();
  char* getNom();
  
  
  bool collide(int posx, int posy);
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
  
  short health_;
  
  Uint32 initJump_;
  Uint32 initFall_;
  int initFallPosy_;
  float initFallSpeedy_;
  int isJumping_;
  bool hasJustLanded_;
  
  char nom_[10];
  
};

#endif
