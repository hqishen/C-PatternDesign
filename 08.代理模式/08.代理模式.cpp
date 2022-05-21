// 08.代理模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

class AbstractInterface {
public:
	virtual void run() = 0;
};

class AlgSystem : public AbstractInterface {
public:
	void run() {
		std::cout << "Algorithm system running...." << std::endl;
	}
};

class ProxySystem : public AbstractInterface {
public:
	ProxySystem(std::string name, std::string pass) : m_name(name), m_pass(pass) {
		m_pAlg = new AlgSystem();
	}

	~ProxySystem() {
		delete m_pAlg;
	}

	void run() {
		if (login()) {
			std::cout << "login success..." << std::endl;
			m_pAlg->run();
		}
	}

	bool login() {
		if (m_pass == "pass" && m_name == "admin") {
			return true;
		}
		return false;
	}

private:
	std::string m_name;
	std::string m_pass;
	AlgSystem* m_pAlg;
};



int main() {

	ProxySystem* proxy = new ProxySystem("admin", "pass");
	proxy->run();
	delete proxy;
	return 0;
}
