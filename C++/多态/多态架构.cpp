/*=============================================================
	�ļ�����:��̬�ܹ� �������װ
	��    ��:С����
	��дʱ��:2021.10.27 10:21
	�޸�ʱ��:
	���ݼ��:
	 ���ö�̬ ģ��������װ
==============================================================*/

#include <iostream>

using namespace std;
//Cpu����
class CpuBase
{
public:
	virtual void calculate() = 0;
};
//�Կ�����
class VideoCardBase
{
public:
	virtual void display() = 0;//���麯�� �������ʵ�ֲ���ʵ����
};
//�ڴ����
class Memory
{
public:
	virtual void storage() = 0;
};
//������
class Computer
{public:
	//��ʼ����Ա
	Computer(CpuBase *cpu,VideoCardBase *display,Memory *memory)
	{
		c_cpu = cpu;
		c_display = display;
		c_storage = memory;
	}
	//�ͷ��ڴ�ռ�
	~Computer()
	{
		delete c_cpu;
		delete c_display;
		delete c_storage;
		cout << "Computer memFree" << endl;
	}
	//���ù���
	void work()
	{
		c_cpu->calculate();
		c_display->display();
		c_storage->storage();
	}
private:
	CpuBase *c_cpu;
	VideoCardBase *c_display;
	Memory* c_storage;
};


//Intelʵ��
class IntelCpu : public CpuBase
{
	void calculate()
	{
		cout << "Intel calculate in run time" << endl;
	}
};
class IntelDisplay : public VideoCardBase
{
	void display()
	{
		cout << "Intel display in run time" << endl;
	}
};
class IntelMemory : public Memory
{
	void storage()
	{
		cout << "Intel storage in run time" << endl;
	}
};

//Lenovoʵ��
class LenovoCpu : public CpuBase
{
	void calculate()
	{
		cout << "Lenovo calculate in run time" << endl;
	}
};
class LenovoDisplay : public VideoCardBase
{
	void display()
	{
		cout << "Lenovo display in run time" << endl;
	}
};
class LenovoMemory : public Memory
{
	void storage()
	{
		cout << "Lenovo storage in run time" << endl;
	}
};


void test()
{
	//intel����
	Computer I_computer(new IntelCpu,new IntelDisplay,new IntelMemory);
	I_computer.work();
	cout << "------------------------" << endl;
	//lenovo����
	Computer L_computer(new LenovoCpu, new LenovoDisplay, new LenovoMemory);
	L_computer.work();
	cout << "------------------------" << endl;
	//lenovo and intel����
	Computer L_I_computer(new LenovoCpu, new IntelDisplay, new LenovoMemory);
	L_I_computer.work();
	cout << "------------------------" << endl;

}

int main()
{

	test();
	return 0;
}

