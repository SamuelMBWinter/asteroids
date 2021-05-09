#ifndef SHIP_H
#define SHIP_H

class Ship {
  public:
    Ship(float x_pos=5, float y_pos=5, float theta_pos=0)
      : x(x_pos), y(y_pos), theta(theta_pos) {
      }
    float x;
    float y;
    float theta;
};

#endif
