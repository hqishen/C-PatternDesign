#include <iostream>
class HardDisk {
public:
    virtual void work() = 0;
};

class Cpu {
public:
    virtual void work() = 0;
};

class Memory {
public:
    virtual void work() = 0;
};

class Computer {
public:
    Computer(HardDisk* hd, Memory* mem, Cpu* cpu) 
        : m_cpu(cpu), m_hd(hd), m_mem(mem) {
    }

    void work() {
        m_hd->work();
        m_cpu->work();
        m_mem->work();
    }
private:
    HardDisk* m_hd;
    Cpu* m_cpu;
    Memory* m_mem;
};

class AMDCPU : public Cpu {
public:
    void work() {
        std::cout << "Amd cpu and in working order..." << std::endl;
    }
};

class WDHD : public HardDisk {
public:
    void work() {
        std::cout << "WD hard disk, in working order..." << std::endl;
    }
};

class WGMem : public Memory {
public:
    void work() {
        std::cout << "WG memroy , in working order..." << std::endl;
    }
};


int main()
{
    HardDisk * hd = new WDHD();
    Memory* mem = new WGMem();
    Cpu* cpu = new AMDCPU();

    Computer* acer = new Computer(hd, mem, cpu);
    acer->work();
    delete acer;

    Computer* lenove = new Computer(hd, mem, cpu);
    lenove->work();

    delete lenove;
    delete hd;
    delete mem;
    delete cpu;
    return 0;
}

