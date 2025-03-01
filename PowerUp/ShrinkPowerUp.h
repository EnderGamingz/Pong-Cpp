#ifndef PONG_SHRINKPOWERUP_H
#define PONG_SHRINKPOWERUP_H

#include "PowerUp.h"
#include "SFML/Graphics.hpp"

using namespace sf;

class ShrinkPowerUp : public PowerUp {
public:
  ShrinkPowerUp()
      : PowerUp("../assets/power_ups/shrink.png",
                seconds(15.0f)) {
    printf("Power up: Created shrink power-up with lifetime of %i seconds\n", (int) this->m_duration.asSeconds());
    m_effect = PowerUpEffect::BAD;
  }

  void applyTo(Player *player) override {
    // decrease the player's height
    player->setHeight(player->initialHeight * 0.5f);
  }

  void revert(Player *player) override {
    // increase the player's height
    player->setHeight(player->initialHeight);
  }
};

#endif//PONG_SHRINKPOWERUP_H
