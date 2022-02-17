#include <iostream>
#include <string>
#include <easy2d/easy2d.h>
#pragma comment(lib, "libeasy2d.lib")

using namespace std;
using namespace easy2d;

void GreedySnake::gs_check_input()
{
	
}
class Man : public Sprite {
public:
	Man()
	{
		//加载图片
		this->open(L"man.jpg");
	}

	void onUpdate()
	{
		//onUpdate 函数
		if (Input::isDown(KeyCode::Up)) {
			//上键按下
			/*float y = this->getPosY();
			this->setPosY(y - 2);*/
			this->movePosY(-2);
		}
		else if (Input::isDown(KeyCode::Down)) {
			this->movePosY(2);
		}
		if (Input::isDown(KeyCode::Left)) {
			this->movePosX(-2);
		}
		else if (Input::isDown(KeyCode::Right)) {
			this->movePosX(2);
		}

	}
};

int main() {
	if (Game::init()) {             //初始化游戏

		Window::setTitle(L"Moving Man");
		Window::setSize(800, 800);
		auto scene = gcnew Scene;    //创建一个场景
		SceneManager::enter(scene);  //进入该场景

		auto hero = gcnew Man;
		hero->setAnchor(0.5, 0.5);
		hero->setPos(Window::getWidth() / 2, Window::getHeight() / 2);

		scene->addChild(hero);

		Game::start();                        //开始游戏

	}
	Game::destroy();
	return 0;
}