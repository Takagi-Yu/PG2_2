#pragma once
#include "Novice.h"

class PlayerBullet {
public: 

  PlayerBullet(int posX, int posY, int speed, int radius, int isShot);

  int GetPosX() { return posX_; }
  int GetPosY() { return posY_; }
  int Getspeed() { return speed_; }
  int Getradius() { return radius_; }
  int GetisShot() { return isShot_; }
  void SetPosition(int x, int y);
  void SetSpeed(int speed);

  /// 更新
  void Update();

  /// 描画
  void Draw();

  // メンバ変数
  int posX_;
  int posY_;
  int speed_;
  int radius_;
  int isShot_;
};