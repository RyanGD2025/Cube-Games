package com.cubegames.app;

public class GameLibrary {
    static {
        System.loadLibrary("game"); // nome da lib gerada no CMake
    }

    public native String getGameName();
}
