#include "Enemy.h"
#include "Player.h"
#include "PlayerBullet.h"
#include "math.h"
#include <Novice.h>

const char kWindowTitle[] = "PG2_評価課題2";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

  // ライブラリの初期化
  Novice::Initialize(kWindowTitle, 960, 640);

  enum SCENE { TITLE, GAME, CLEAR, GAMEOVER };
  int scene = 0;

  Enemy *enemyA = new Enemy(480, 100, 4, 3, 20, true, 60);
  Player *player = new Player(480, 400, 6, 15, true);
  PlayerBullet *playerBullet = new PlayerBullet(30, 70, 6, 10, false);

  int score = 0;

  float enemyDistanceX = 0.0f;
  float enemyDistanceY = 0.0f;
  float enemyDistance = 0.0f;

  float playerDistanceX = 0.0f;
  float playerDistanceY = 0.0f;
  float playerDistance = 0.0f;

  // キー入力結果を受け取る箱
  char keys[256] = {0};
  char preKeys[256] = {0};

  // ウィンドウの×ボタンが押されるまでループ
  while (Novice::ProcessMessage() == 0) {
    // フレームの開始
    Novice::BeginFrame();

    // キー入力を受け取る
    memcpy(preKeys, keys, 256);
    Novice::GetHitKeyStateAll(keys);

    ///
    /// ↓更新処理ここから
    ///

    switch (scene) {
    case TITLE:

      scene = 0;

      enemyA = new Enemy(480, 100, 4, 3, 20, true, 120);
      player = new Player(480, 400, 6, 15, true);
      playerBullet = new PlayerBullet(30, 70, 8, 10, false);

      score = 0;

      enemyDistanceX = 0.0f;
      enemyDistanceY = 0.0f;
      enemyDistance = 0.0f;

      playerDistanceX = 0.0f;
      playerDistanceY = 0.0f;
      playerDistance = 0.0f;

      if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
        scene = 1;
      }

      break;
    case GAME:

      enemyA->Update();
      player->Update(keys, preKeys);
      playerBullet->Update();

      // 弾と敵の当たり判定
      enemyDistanceX = static_cast<float>(enemyA->GetPosX() -
                                          player->playerBullet_->GetPosX());
      enemyDistanceY = static_cast<float>(enemyA->GetPosY() -
                                          player->playerBullet_->GetPosY());
      enemyDistance = sqrtf(enemyDistanceX * enemyDistanceX +
                            enemyDistanceY * enemyDistanceY);

      if (player->playerBullet_->isShot_) {
        if (enemyA->isAlive_) {
          if (enemyDistance <=
              static_cast<float>(enemyA->Getradius() +
                                 player->playerBullet_->Getradius())) {
            enemyA->isAlive_ = false;
            player->playerBullet_->isShot_ = false;
            score++;
          }
        }
      }

      // 自機と敵の当たり判定
      playerDistanceX =
          static_cast<float>(enemyA->GetPosX() - player->GetPosX());
      playerDistanceY =
          static_cast<float>(enemyA->GetPosY() - player->GetPosY());
      playerDistance = sqrtf(playerDistanceX * playerDistanceX +
                             playerDistanceY * playerDistanceY);

      if (player->isAlive_) {
        if (enemyA->isAlive_) {
          if (playerDistance <=
              static_cast<float>(enemyA->Getradius() + player->Getradius())) {
            player->isAlive_ = false;
          }
        }
      }

      if (score >= 10) {
        scene = 2;
      }

      if (!player->isAlive_) {
        scene = 3;
      }

      break;
    case CLEAR:

      if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
        scene = 0;
      }

      break;
    case GAMEOVER:

      if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
        scene = 0;
      }

      break;
    }

    ///
    /// ↑更新処理ここまで
    ///

    ///
    /// ↓描画処理ここから
    ///

    switch (scene) {
    case TITLE:

      Novice::ScreenPrintf(10, 10, "Scene:Title");
      Novice::ScreenPrintf(10, 30, "Enter to Game");

      break;
    case GAME:

      enemyA->Draw();
      player->Draw();
      playerBullet->Draw();

      Novice::ScreenPrintf(10, 10, "Scene:Game");

      Novice::ScreenPrintf(10, 30, "score:%d", score);

      break;
    case CLEAR:

      Novice::ScreenPrintf(10, 10, "Scene:Clear");
      Novice::ScreenPrintf(10, 30, "Enter to Title");

      break;
    case GAMEOVER:

      Novice::ScreenPrintf(10, 10, "Scene:Game Over");
      Novice::ScreenPrintf(10, 30, "Enter to Title");

      break;
    }

    ///
    /// ↑描画処理ここまで
    ///

    // フレームの終了
    Novice::EndFrame();

    // ESCキーが押されたらループを抜ける
    if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
      break;
    }
  }

  // ライブラリの終了
  Novice::Finalize();
  return 0;
}