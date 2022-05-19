// 01.开闭原则.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

/*
传统的写法，一个银行业务员的工作
如之前只做存款、转账，如果要加其他功能的话，就需要修改这个类，就不符合开闭原则
*/
class BanckWorker
{
public:
	BanckWorker();
	~BanckWorker();

	void save() {
		std::cout << "存款" << std::endl;
	}

	void transform() {
		std::cout << "转账.." << std::endl;
	}

	// 新的业务,需要添加代码
	void fund() {
		std::cout << "基金" << std::endl;
	}

private:
};

/*
开闭原则的写法...
*/
/*
有纯虚函数，属于接口类，派生类需要实现纯虚函数
*/
class AbstractBanker {
public:
	virtual void business() = 0;
private:
};
/*
* 派生类
*/
class TransformBanker : public AbstractBanker {
public:
	virtual void business() {
		std::cout << "转账" << std::endl;
	}
private:
};

class SaveBanker : public AbstractBanker {
public:
	virtual void business() {
		std::cout << "存钱业务" << std::endl;
	}
private:
};



int main()
{
	AbstractBanker *banker = NULL;
	banker = new TransformBanker();
	banker->business();
	delete banker;

	banker = new SaveBanker();
	banker->business();
	delete banker;
	return 0;
}
