#include "SceneManager.h"
#include "KeyManager.h"

AbstractScene* SceneManager::Update() {

    //�L�[���͂̍X�V
    KeyManager::Update();

    //���݃V�[���̃A�b�v�f�[�g�����s
    AbstractScene* NextScene = mScene->Update();

    //���̃V�[�������݂̃V�[���ƈႤ�ꍇ�؂�ւ���
    if (NextScene != mScene) {
        delete mScene;
        mScene = NextScene;
    }
    return NextScene;
}
void SceneManager::Draw()const {
    mScene->Draw();
}
