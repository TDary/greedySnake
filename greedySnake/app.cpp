#include <iostream>
#include <string>
#include <easy2d/easy2d.h>
#pragma comment(lib, "libeasy2d.lib")

using namespace std;
using namespace easy2d;

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



		//auto text = gcnew Text(L"Hello Easy2D!");  //����һ���ı�
		//auto rotate = gcnew RotateTo(3, 180);
		//auto rotate = gcnew RotateBy(1, 60);
		//auto action = gcnew Loop(rotate);
		//auto button = gcnew Button;
		/*auto sprite = gcnew Sprite(L"test.jpg");
		float width = Window::getWidth();
		float height = Window::getHeight();*/
		/*sprite->setAnchor(0.5, 0.5);
		sprite->setPos(width / 2, height / 2);*/
		//sprite->setSize(1000, 800);
		//text->setAnchor(0.5, 0.5);                  //�����ı����ĵ�
		//text->setPos(Window::getSize() / 2);        //������ı�����
		//scene->addChild(text);                      //������ı���ӵ�������
		//text->runAction(action);
		//scene->addChild(button);
		//scene->addChild(sprite);

		Game::start();                        //��ʼ��Ϸ

	}
	Game::destroy();
	return 0;
}