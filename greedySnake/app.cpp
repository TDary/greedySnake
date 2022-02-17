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
		//����ͼƬ
		this->open(L"man.jpg");
	}

	void onUpdate()
	{
		//onUpdate ����
		if (Input::isDown(KeyCode::Up)) {
			//�ϼ�����
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
	if (Game::init()) {             //��ʼ����Ϸ

		Window::setTitle(L"Moving Man");
		Window::setSize(800, 800);
		auto scene = gcnew Scene;    //����һ������
		SceneManager::enter(scene);  //����ó���

		auto hero = gcnew Man;
		hero->setAnchor(0.5, 0.5);
		hero->setPos(Window::getWidth() / 2, Window::getHeight() / 2);

		scene->addChild(hero);

		Game::start();                        //��ʼ��Ϸ

	}
	Game::destroy();
	return 0;
}