#include "PlayerBullet.h"

PlayerBullet::PlayerBullet(int posX,int posY,int speed,int radius,int isShot) {
  posX_ = posX;
  posY_ = posY;
  speed_ = speed;
  radius_ = radius;
  isShot_ = isShot;
}

void PlayerBullet::SetPosition(int x, int y) {
  posX_ = x;
  posY_ = y;
}

void PlayerBullet::SetSpeed(int speed) {
  speed_ = speed;
}

//更新
void PlayerBullet::Update() {

  if (isShot_) {
    posY_ -= speed_;
  }

  if (posY_ <= 0) {
    isShot_ = false;
  }
}

    //描画
void PlayerBullet::Draw() {
  if (isShot_) {
    Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, 0xFF0000FF,
                        kFillModeSolid);
  }
}