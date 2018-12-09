#ifndef _MAP_H_
#define _MAP_H_

#define MAP "basic.txt"
#define SQUARE_SIZE 30
#define MAP_SIZE_X 36
#define MAP_SIZE_Y 24

class Map{
public:
  Map();
  short map_[MAP_SIZE_Y][MAP_SIZE_X];
  
  void charge();
private:
  int width_;
  int height_;
  
};

#endif
