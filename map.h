#ifndef _MAP_H_
#define _MAP_H_

#define MAP "map.txt"
#define SQUARE_SIZE 60

class Map{
public:
  Map();
  short map_[12][18];
  
  void charge();
private:
  int width_;
  int height_;
  
};

#endif
