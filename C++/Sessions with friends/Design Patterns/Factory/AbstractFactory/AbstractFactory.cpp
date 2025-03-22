#include <iostream>

//####################### abstract classes for Products #######################

class IButton
{
public:
	virtual void Paint() = 0;
};

class ICheckbox
{
public:
	virtual void Paint() = 0;
};

//####################### Concreate classes for Products #######################

class WinButton : public IButton
{
public:
	virtual void Paint() {
		std::cout << "WinButton::Paint" << std::endl;
	}
};

class MacButton : public IButton
{
public:
	virtual void Paint() {
		std::cout << "MacButton::Paint" << std::endl;
	}
};

class WinCheckbox : public ICheckbox
{
public:
	virtual void Paint() {
		std::cout << "WinCheckbox::Paint" << std::endl;
	}
};

class MacCheckbox : public ICheckbox
{
public:
	virtual void Paint() {
		std::cout << "MacCheckbox::Paint" << std::endl;
	}
};


//####################### abstract factory class  #######################

class IGUIFactory
{
public:
	virtual std::shared_ptr<IButton> createButton() = 0;
	virtual std::shared_ptr<ICheckbox> createCheckbox() = 0;
};

//####################### concreate factory class #######################

class WinFactory : public IGUIFactory
{
public:
	std::shared_ptr<IButton> createButton() {
		return std::make_unique<WinButton>();
	}

	std::shared_ptr<ICheckbox> createCheckbox() {
		return std::make_unique<WinCheckbox>();
	}
};

class MacFactory : public IGUIFactory
{
public:
	std::shared_ptr<IButton> createButton() {
		return std::make_unique<MacButton>();
	}

	std::shared_ptr<ICheckbox> createCheckbox() {
		return std::make_unique<MacCheckbox>();
	}
};


//####################### Client class #######################

class Application
{
	IGUIFactory* m_gui{ nullptr };
	std::shared_ptr<IButton> m_button{ nullptr };
	std::shared_ptr<ICheckbox> m_checkbox{ nullptr };
public:

	Application(IGUIFactory* gui) : m_gui(gui) {

	}
	void createGUI() {
		m_button = m_gui->createButton();
		m_checkbox = m_gui->createCheckbox();
	}
	void paint() {
		m_button->Paint();
		m_checkbox->Paint();
	}
	~Application() { delete m_gui; m_gui = nullptr; }
};

int main()
{
	std::string os = "windows";
	IGUIFactory* gui{ nullptr };

	if ("windows" == os) {
		gui = new WinFactory;
	} 
	else if ("macintosh" == os) {
		gui = new MacFactory;
	}

	Application* app = new Application(gui);
	app->createGUI();
	app->paint();

	delete app;
}