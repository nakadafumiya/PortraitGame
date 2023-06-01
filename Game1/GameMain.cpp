#include"Dxlib.h"
#include"AbstractScene.h"
#include"SceneManager.h"
#include"common.h"
#include"Title.h"


/***
 * �v���O�����̊J�n
 **/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{


    SetMainWindowText("�V���[�e�B���O�Q�[��");

    ChangeWindowMode(TRUE);        // �E�B���h�E���[�h�ŋN��

    SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLOR_BIT_16);

    if (DxLib_Init() == -1) return -1;    // DX���C�u�����̏���������


    SetDrawScreen(DX_SCREEN_BACK);    // �`����ʂ𗠂ɂ���

    SetFontSize(20);        // �����T�C�Y��ݒ�

    SceneManager sceneMng((AbstractScene*)new Title());
    // �Q�[�����[�v
    while (ProcessMessage() == 0 && sceneMng.Update() != nullptr) {

        //ESCAPE�L�[�ŏI��
        if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) DxLib_End();
    
        ClearDrawScreen();  //��ʂ̏�����

        sceneMng.Draw();     // ����ʂ̓��e��\��ʂɔ��f
        
        ScreenFlip();

    }

    DxLib_End();    // DX���C�u�����g�p�̏I������

    return 0;    // �\�t�g�̏I��
}