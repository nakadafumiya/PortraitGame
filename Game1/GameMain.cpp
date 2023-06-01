#include"Dxlib.h"
#include"AbstractScene.h"
#include"SceneManager.h"
#include"common.h"
#include"Title.h"


/***
 * プログラムの開始
 **/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{


    SetMainWindowText("シューティングゲーム");

    ChangeWindowMode(TRUE);        // ウィンドウモードで起動

    SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLOR_BIT_16);

    if (DxLib_Init() == -1) return -1;    // DXライブラリの初期化処理


    SetDrawScreen(DX_SCREEN_BACK);    // 描画先画面を裏にする

    SetFontSize(20);        // 文字サイズを設定

    SceneManager sceneMng((AbstractScene*)new Title());
    // ゲームループ
    while (ProcessMessage() == 0 && sceneMng.Update() != nullptr) {

        //ESCAPEキーで終了
        if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) DxLib_End();
    
        ClearDrawScreen();  //画面の初期化

        sceneMng.Draw();     // 裏画面の内容を表画面に反映
        
        ScreenFlip();

    }

    DxLib_End();    // DXライブラリ使用の終了処理

    return 0;    // ソフトの終了
}