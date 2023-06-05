#include<iostream>
using namespace std;


//����ͬ�����
//����CPU��

class CPU
{
public:
	//������㺯��
	virtual void calculate() = 0;
};

//����GPU��
class GPU
{
public:
	//������㺯��
	virtual void display() = 0;
};
//�����ڴ�����
class Memory
{
public:
	//������㺯��
	virtual void storage() = 0;
};

//������
class Computer
{
public:
	Computer(CPU* cpu, GPU* gpu, Memory* memory)
	{
		m_cpu = cpu;
		m_gpu = gpu;
		m_memory = memory;
	}

	//�ṩ�������� �ͷŵ������
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

	CPU* m_cpu;//CPU�����ָ��
	GPU* m_gpu;//GPU�����ָ��
	Memory* m_memory;//�ڴ���ָ��
public:
	//�ṩ��������
	void work()
	{
		//���������
		m_cpu->calculate();
		m_gpu->display();
		m_memory->storage();
	}

};

//���峧��
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
	//��һ̨�������
	CPU* intercpu = new Intercpu;
	GPU* intergpu = new Intergpu;
	Memory* intermemory = new Intermemory;

	//������һ̨����
	Computer* computer1 = new Computer(intercpu, intergpu, intermemory);
	computer1->work();
	delete computer1;

	//�ڶ�̨����
	Computer* computer2 = new Computer(new Huaweicpu, new Intergpu, new Huaweimemory); //���������������ø���ָ����գ������õ���̬
	computer2->work();
	delete computer2;
}
int main_polymorphism_example3()
{
	test_computer();
	system("pause");
	return 0;
}