// renderer.h
#ifndef RENDERER_H
#define RENDERER_H

class Renderer {
public:
    Renderer();
    ~Renderer();

    void clearScreen();
    void drawSprite(int spriteId, float x, float y);
    void present();
};

#endif
