#pragma once
#include "Novice.h"
#include <stdlib.h>
#include <time.h>

class Enemy {
public:

  int isAlive_ = false;
  int respawnTimer_ = 60;

  Enemy(int posX, int posY, int speedX, int speedY, int radius, int isAlive,
        int respawnTimer);

  int GetPosX() { return posX_; }
  int GetPosY() { return posY_; }
  int GetspeedX() { return speedX_; }
  int Getspeed() { return speedY_; }
  int Getradius() { return radius_; }
  void SetPosition(int x, int y);
  void SetSpeed(int x, int y);
  void SetRadius(int r);

  /// 更新
  void Update();

  /// 描画
  void Draw();

private:
  int posX_;
  int posY_;
  int speedX_;
  int speedY_;
  int radius_;
};