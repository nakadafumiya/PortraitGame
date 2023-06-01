#include "Title.h"
#include "KeyManager.h"



Title::Title()
{
	//メニューの入力
	MenuNum = 0;
	//タイトルの画像
	GameTitleImage = LoadGraph("images/GameTitleImage.png");
	
	

}

AbstractScene*Title::Update()
{
	

	return this;
}

void Title::Draw() const
{
	//タイトル画像の表示
	DrawGraph(0, 0, GameTitleImage, FALSE);
	
}