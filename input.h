// input.h
#ifndef INPUT_H
#define INPUT_H

class Input {
public:
    Input();
    ~Input();

    void processTouch(float x, float y, int action);
    bool isKeyPressed(int keyCode);
};

#endif
