#ifndef PONG_GAMEHANDLER_H
#define PONG_GAMEHANDLER_H

#include "../MenuHandler/MenuHandler.h"
#include "../NetworkingHandler/NetworkingHandler.h"
#include "SFML/Graphics.hpp"

enum GameState {
  MENU,
  PLAY,
  WAITING_FOR_CONNECTION,
  CONNECTING_TO_PLAYER,
  CONNECT_TO_PLAYER,
};

enum GameType {
  LOCAL,
  ONLINE,
  ONLINE_HOST
};

using namespace sf;
using namespace std;

class GameHandler {
public:
  GameHandler();
  static GameHandler &getInstance();

  RenderWindow *getWindow();
  Font &getFont();

  void setGameState(GameState state);
  GameState getGameState() const;

  void setGameType(GameType type);
  GameType getGameType() const;

  void onlineListen() const;
  void onlineConnect();
  void onlineDisconnect() const;
  NetworkStatus onlineAccept() const;

private:
  RenderWindow window;
  Font main_font;

public:
  // Disable copy and assign
  GameHandler(const GameHandler &) = delete;
  void operator=(const GameHandler &) = delete;
  int window_height;
  int window_width;
  GameState gameState = GameState::MENU;
  GameType gameType = GameType::LOCAL;
  String ipAddress = "127.0.0.1";
  NetworkingHandler *networkingHandler;
  NetworkPayload *gameStateData{};

};

#endif//PONG_GAMEHANDLER_H