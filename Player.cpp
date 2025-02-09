#include "Player.h"
#include "PlayerBullet.h"

Player::Player(int posX, int posY, int speed, int radius, int isAlive) {
  posX_ = posX;
  posY_ = posY;
  speed_ = speed;
  radius_ = radius;
  isAlive_ = isAlive;
}

void Player::SetPosition(int posX, int posY) {
  posX_ = posX;
  posY_ = posY;
}

void Player::SetSpeed(int speed) { speed_ = speed; }

void Player::SetRadius(int radius) { radius_ = radius; }

void Player::Update(char *keys, char *preKeys) {

  // 移動処理
  if (keys[DIK_W]) {
    posY_ -= speed_;
  }

  if (keys[DIK_A]) {
    posX_ -= speed_;
  }

  if (keys[DIK_S]) {
    posY_ += speed_;
  }

  if (keys[DIK_D]) {
    posX_ += speed_;
  }

  // 画面外にいかぬよう
  if (posX_ <= 0 + radius_) {
    posX_ = 0 + radius_;
  }

  if (posX_ >= 960 - radius_) {
    posX_ = 960 - radius_;
  }

  if (posY_ <= 0 + radius_) {
    posY_ = 0 + radius_;
  }

  if (posY_ >= 640 - radius_) {
    posY_ = 640 - radius_;
  }

  // 弾を撃つときの弾の初期位置
  if (!playerBullet_->isShot_) {
    if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
      playerBullet_->isShot_ = true;
      playerBullet_->posX_ = posX_;
      playerBullet_->posY_ = posY_;
    }
  }

  // 弾の更新処理
  playerBullet_->Update();
}

void Player::Draw() {
  // 弾の描画
  playerBullet_->Draw();

  // 自機の描画
  if (isAlive_) {
    Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, 0xFFFFFFFF,
                        kFillModeSolid);
  }
}