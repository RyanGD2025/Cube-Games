package com.cubegames.app;

import android.os.Bundle;
import android.webkit.WebSettings;
import android.webkit.WebView;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {
    private WebView webView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        webView = new WebView(this);
        setContentView(webView);

        WebSettings webSettings = webView.getSettings();
        webSettings.setJavaScriptEnabled(true);
        webSettings.setAllowFileAccess(true);

        // Carrega a página home.html que deve estar em assets
        webView.loadUrl("file:///android_asset/home.html");
    }
}
package com.cubegames.app;

public class GameLibrary {
    static {
        System.loadLibrary("game"); // nome da sua lib C++
    }

    public native String getGameName();
}
GameLibrary gameLibrary = new GameLibrary();
String name = gameLibrary.getGameName();
Log.d("CubeGames", "Nome do Jogo: " + name);
