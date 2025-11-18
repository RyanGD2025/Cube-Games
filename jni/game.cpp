#include <jni.h>

extern "C"
JNIEXPORT jstring JNICALL
Java_com_cubegames_app_GameLibrary_getGameName(JNIEnv *env, jobject /* this */) {
    return env->NewStringUTF("Cube Game Nativo em C++");
}
