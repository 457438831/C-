/*=============================================================
	文件名称:多态架构 计算机组装
	作    者:小花儿
	编写时间:2021.10.27 10:21
	修改时间:
	内容简介:
	 利用多态 模拟计算机组装
==============================================================*/

#include <iostream>

using namespace std;
//Cpu基类
class CpuBase
{
public:
	virtual void calculate() = 0;
};
//显卡基类
class VideoCardBase
{
public:
	virtual void display() = 0;//纯虚函数 子类必须实现才能实例化
};
//内存基类
class Memory
{
public:
	virtual void storage() = 0;
};
//电脑类
class Computer
{public:
	//初始化成员
	Computer(CpuBase *cpu,VideoCardBase *display,Memory *memory)
	{
		c_cpu = cpu;
		c_display = display;
		c_storage = memory;
	}
	//释放内存空间
	~Computer()
	{
		delete c_cpu;
		delete c_display;
		delete c_storage;
		cout << "Computer memFree" << endl;
	}
	//调用功能
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


//Intel实例
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

//Lenovo实例
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
	//intel调用
	Computer I_computer(new IntelCpu,new IntelDisplay,new IntelMemory);
	I_computer.work();
	cout << "------------------------" << endl;
	//lenovo调用
	Computer L_computer(new LenovoCpu, new LenovoDisplay, new LenovoMemory);
	L_computer.work();
	cout << "------------------------" << endl;
	//lenovo and intel调用
	Computer L_I_computer(new LenovoCpu, new IntelDisplay, new LenovoMemory);
	L_I_computer.work();
	cout << "------------------------" << endl;

}

int main()
{

	test();
	return 0;
}

