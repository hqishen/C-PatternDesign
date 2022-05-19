#include <iostream>
#include <mutex>
/*
饿汉式
*/
#if 0
template<typename T>
class Singleton {
private:
	Singleton() {}
public:

	~Singleton() {}
	friend void Data(Singleton &obj);

	static T* Instance() {
		if (m_instance) {
			return m_instance;
		} else {
			return new T();
		}
	}

	static void Destroy() {
		if (m_instance) {
			delete m_instance;
			m_instance = NULL;
		}
	}

private:
	static T* m_instance;
};

template<typename T>
T* Singleton<T>::m_instance = new T();
#else
template<typename T>
class Singleton {
private:
	Singleton() {}
public:
	friend void Data(Singleton<T>& obj); //测试使用

	static T* Instance() {
		std::lock_guard<std::recursive_mutex> lock(m_mutex);
		if (nullptr == m_instance) {
			m_instance = new T();
		}
		return m_instance;
	}
	static void Destroy() {
		std::lock_guard<std::recursive_mutex> lock(m_mutex);
		if (m_instance) {
			delete m_instance;
			m_instance = nullptr;
		}
	}

private:
	static T* m_instance;
	static std::recursive_mutex m_mutex;
};

template<class T>
std::recursive_mutex Singleton<T>::m_mutex;
template<class T>
T* Singleton<T>::m_instance = NULL;

#endif

template<typename T>
void Data(Singleton<T> &obj) {
	if (nullptr == obj.m_instance) {
		obj.m_instance = new T();
	}
}

class A {
public:

	int getA() { return a; }
	int getB() { return b; }
private:
	int a = 20;
	int b = 10;
};

int main()
{
	
	std::cout << Singleton<A>::Instance()->getA() << std::endl;
	std::cout << Singleton<A>::Instance()->getB() << std::endl;

	return 0;
}
