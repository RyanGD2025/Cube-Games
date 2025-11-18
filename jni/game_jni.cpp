#include <jni.h>
#include "game.h"

static Game* game = nullptr;

extern "C" JNIEXPORT void JNICALL
Java_com_cubegames_app_GameLibrary_startGame(JNIEnv *env, jobject obj) {
    if (!game) game = new Game();
    game->start();
}

extern "C" JNIEXPORT void JNICALL
Java_com_cubegames_app_GameLibrary_updateGame(JNIEnv *env, jobject obj, jfloat deltaTime) {
    if (game) game->update(deltaTime);
}

extern "C" JNIEXPORT void JNICALL
Java_com_cubegames_app_GameLibrary_stopGame(JNIEnv *env, jobject obj) {
    if (game) {
        game->stop();
        delete game;
        game = nullptr;
    }
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_cubegames_app_GameLibrary_getGameName(JNIEnv *env, jobject obj) {
    if (!game) game = new Game();
    return env->NewStringUTF(game->getName());
}
