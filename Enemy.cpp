#include "Enemy.h"
#include "PlayerBullet.h"

Enemy::Enemy(int posX, int posY, int speedX, int speedY, int radius,
             int isAlive, int respawnTimer) {
  posX_ = posX;
  posY_ = posY;
  speedX_ = speedX;
  speedY_ = speedY;
  radius_ = radius;
  isAlive_ = isAlive;
  respawnTimer_ = respawnTimer;
  // ランダム
  srand(static_cast<unsigned int>(time(nullptr)));
}

void Enemy::SetPosition(int x, int y) {
  posX_ = x;
  posY_ = y;
}

void Enemy::SetSpeed(int x, int y) {
  speedX_ = x;
  speedY_ = y;
}

void Enemy::SetRadius(int r) { radius_ = r; }

// 更新
void Enemy::Update() {

  if (isAlive_) {
    posX_ += speedX_;
    posY_ += speedY_;

    if (posX_ <= 0+radius_) {
      speedX_ *= -1;
    }
    if (posX_ >= 960 - radius_) {
      speedX_ *= -1;
    }
    if (posY_ <= 0 + radius_) {
      speedY_ *= -1;
    }
    if (posY_ >= 640 - radius_) {
      speedY_ *= -1;
    }
  }

  if (!isAlive_) {
    respawnTimer_--;
  }

  if (respawnTimer_ <= 0) {
    respawnTimer_ = 60;
    posX_ = rand() % 440 + 20;
    posY_ = 100;
    speedX_ = rand() % 3 + 3;
    speedY_ = rand() % 3 + 2;
    isAlive_ = true;
  }
}

// 描画
void Enemy::Draw() {
  if (isAlive_) {
    Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, 0xFFFFFFFF,
                        kFillModeSolid);
  }
}