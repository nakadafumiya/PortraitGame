#include "Title.h"
#include "KeyManager.h"



Title::Title()
{
	//���j���[�̓���
	MenuNum = 0;
	//�^�C�g���̉摜
	GameTitleImage = LoadGraph("images/GameTitleImage.png");
	
	

}

AbstractScene*Title::Update()
{
	

	return this;
}

void Title::Draw() const
{
	//�^�C�g���摜�̕\��
	DrawGraph(0, 0, GameTitleImage, FALSE);
	
}