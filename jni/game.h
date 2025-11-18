#ifndef GAME_H
#define GAME_H

class Game {
public:
    Game();
    ~Game();

    void start();
    void update(float deltaTime);
    void stop();

    const char* getName();
};

#endif // GAME_H
