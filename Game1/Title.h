#pragma once
#include"DxLib.h"
#include"AbstractScene.h"
#include"SceneManager.h"

class Title:public AbstractScene
{
private:
	int GameTitleImage;//ゲームタイトル画像

	int MenuNum;//メニュー

public:
	Title();
	virtual ~Title() {};
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;
};

