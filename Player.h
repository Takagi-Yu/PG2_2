#pragma once
#include "PlayerBullet.h"
#include "Novice.h"
class Player {
public: // メンバ関数

  PlayerBullet *playerBullet_ = new PlayerBullet(30, 70, 6, 10, false);

  Player(int posX, int posY, int speed, int radius,int isAlive);

  int GetPosX() { return posX_; }
  int GetPosY() { return posY_; }
  int Getspeed() { return speed_; }
  int Getradius() { return radius_; }
  void SetPosition(int x, int y);
  void SetSpeed(int speed);
  void SetRadius(int radius);

  /// 更新
  void Update(char *keys, char *preKeys);

  /// 描画
  void Draw();

  // メンバ変数
  int posX_;
  int posY_;
  int speed_;
  int radius_;
  int isAlive_;
};