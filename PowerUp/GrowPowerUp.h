#ifndef PONG_GROWPOWERUP_H
#define PONG_GROWPOWERUP_H

#include "PowerUp.h"
#include "SFML/Graphics.hpp"

using namespace sf;

class GrowPowerUp : public PowerUp {
public:
  GrowPowerUp()
      : PowerUp("../assets/power_ups/grow.png", seconds(15.0f)) {
    printf("Power up: Created grow power-up with lifetime of %i seconds\n", (int) this->m_duration.asSeconds());
    m_effect = PowerUpEffect::GOOD;
  }

  void applyTo(Player *player) override {
    // increase the player's height
    player->setHeight(player->initialHeight * 1.5f);
  }

  void revert(Player *player) override {
    // decrease the player's height
    player->setHeight(player->initialHeight);
  }
};

#endif//PONG_GROWPOWERUP_H
