#pragma once
#include"AbstractScene.h"	

//�V�[���}�l�[�W���[�N���X
//�e�V�[���̐؂�ւ����Ǘ�����B
class SceneManager :public AbstractScene {
private:
	AbstractScene* mScene; //���݂̃V�[��

public:
	//�R���X�g���N�^
	SceneManager(AbstractScene* scene) :mScene(scene) {}

	//�f�X�g���N�^
	~SceneManager() {
		delete mScene;
	}
	//�`��ȊO�̍X�V����������
	AbstractScene* Update() override;

	//�`��Ɋւ��鎖����������
	void Draw()const override;
};
