#ifndef _MAP_H_
#define _MAP_H_

class Map{
public:
  Map();
  short map_[12][18];
  
  int charge();
private:
  int width_;
  int height_;
  
};

#endif
