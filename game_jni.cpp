#include <jni.h>
#include "game_logic.h"
#include "renderer.h"
#include "input.h"

static GameLogic* gameLogic = nullptr;
static Renderer* renderer = nullptr;
static Input* input = nullptr;

extern "C" JNIEXPORT void JNICALL
Java_com_cubegames_app_GameLibrary_initGame(JNIEnv* env, jobject /* this */) {
    if (!gameLogic) gameLogic = new GameLogic();
    if (!renderer) renderer = new Renderer();
    if (!input) input = new Input();
    gameLogic->reset();
}

extern "C" JNIEXPORT void JNICALL
Java_com_cubegames_app_GameLibrary_updateGame(JNIEnv* env, jobject /* this */, jfloat deltaTime) {
    if (gameLogic) gameLogic->update(deltaTime);
    if (renderer) {
        renderer->clearScreen();
        // Exemplo de desenhar
        renderer->drawSprite(0, 100, 150);
        renderer->present();
    }
}

extern "C" JNIEXPORT void JNICALL
Java_com_cubegames_app_GameLibrary_processTouch(JNIEnv* env, jobject /* this */, jfloat x, jfloat y, jint action) {
    if (input) input->processTouch(x, y, action);
}

extern "C" JNIEXPORT jboolean JNICALL
Java_com_cubegames_app_GameLibrary_isGameOver(JNIEnv* env, jobject /* this */) {
    return gameLogic ? gameLogic->isGameOver() : true;
}
