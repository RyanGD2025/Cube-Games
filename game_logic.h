// game_logic.h
#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

class GameLogic {
public:
    GameLogic();
    ~GameLogic();

    void reset();
    void update(float deltaTime);
    bool isGameOver();
};

#endif
