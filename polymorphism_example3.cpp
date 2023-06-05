#include<iostream>
using namespace std;


//抽象不同零件类
//抽象CPU类

class CPU
{
public:
	//抽象计算函数
	virtual void calculate() = 0;
};

//抽象GPU类
class GPU
{
public:
	//抽象计算函数
	virtual void display() = 0;
};
//抽象内存条类
class Memory
{
public:
	//抽象计算函数
	virtual void storage() = 0;
};

//电脑类
class Computer
{
public:
	Computer(CPU* cpu, GPU* gpu, Memory* memory)
	{
		m_cpu = cpu;
		m_gpu = gpu;
		m_memory = memory;
	}

	//提供析构函数 释放电脑零件
	~Computer()
	{
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}

		if (m_gpu != NULL)
		{
			delete m_gpu;
			m_gpu = NULL;
		}

		if (m_memory != NULL)
		{
			delete m_memory;
			m_memory = NULL;
		}
	}
private:

	CPU* m_cpu;//CPU的零件指针
	GPU* m_gpu;//GPU的零件指针
	Memory* m_memory;//内存条指针
public:
	//提供工作函数
	void work()
	{
		//让零件工作
		m_cpu->calculate();
		m_gpu->display();
		m_memory->storage();
	}

};

//具体厂商
//Inter
class Intercpu :public CPU
{
public:
	virtual void calculate()
	{
		cout << "Inter cpu work!" << endl;
	}
};

class Intergpu :public GPU
{
public:
	virtual void display()
	{
		cout << "Inter gpu work!" << endl;
	}
};

class Intermemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Inter memory work!" << endl;
	}
};

//HUAWEI
class Huaweicpu :public CPU
{
public:
	virtual void calculate()
	{
		cout << "Huawei cpu work!" << endl;
	}
};

class Huaweigpu :public GPU
{
public:
	virtual void display()
	{
		cout << "Huawei gpu work!" << endl;
	}
};

class Huaweimemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Huawei memory work!" << endl;
	}
};

void test_computer()
{
	//第一台电脑零件
	CPU* intercpu = new Intercpu;
	GPU* intergpu = new Intergpu;
	Memory* intermemory = new Intermemory;

	//创建第一台电脑
	Computer* computer1 = new Computer(intercpu, intergpu, intermemory);
	computer1->work();
	delete computer1;

	//第二台电脑
	Computer* computer2 = new Computer(new Huaweicpu, new Intergpu, new Huaweimemory); //传入的是子类对象，用父类指针接收，就是用到多态
	computer2->work();
	delete computer2;
}
int main_polymorphism_example3()
{
	test_computer();
	system("pause");
	return 0;
}