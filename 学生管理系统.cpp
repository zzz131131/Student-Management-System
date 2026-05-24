#include<iostream>
#include<string>
using namespace std;
#define MAX 1000

//设计学生结构体
struct Person
{
	//姓名
	string m_Name;
	//性别 1 男 2 女
	int m_Sex;
	//年龄
	int m_Age;
	//电话
	string m_Phone;
	//住址
	string m_Addr;
};

//设计系统结构体
struct System
{
	//系统保存的学生数组
	struct Person personArray[MAX];

	//系统当前记录学生个数
	int m_Size;
};

//1.添加学生函数
void addStudent(System* abs)
{
	//判断系统是否已满，如果满了就不添加
	if (abs->m_Size == MAX)
	{
		cout << "系统已满，无法添加！" << endl;
		return;
	}
	else
	{
		//添加具体学生

		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//性别
		cout << "请输入性别：" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}

		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//电话
		cout << "请输入电话：" << endl;
		string  phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//住址
		cout << "请输入住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//更新系统人数
		abs->m_Size++;
		cout << "添加成功！" << endl;

		system("pause");
		system("cls");//清屏
	}
}


//显示学生信息函数
void showPerson(System* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			cout << "性别：" <<(abs->personArray[i].m_Sex ==1?"男":"女") << "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << "\t";
			cout << "住址：" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");//清屏
}


//检测学生是否存在函数，如果存在，返回学生所在数组中具体位置，不存在返回-1
//参数1 系统 参数2 对比姓名
int isExist(System* abs,string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;//找到了返回下标编号
		}
	}
	return -1;//没找到返回-1
}


//3.删除制定学生函数
void deletePerson(System* abs)
{
	cout << "请输入你要删除的学生" << endl;
	string name;
	cin >> name;
	
	//ret==-1未查到
	//ret!=-1查到了
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			//数据前移
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;//更新系统人数
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}


//4.查找指定学生信息函数
void findPerson(System* abs)
{
	cout << "请输入你要查找的学生" << endl;
	string name;
	cin >> name;

	//判断指定学生是否存在
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别：" << abs->personArray[ret].m_Sex << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
		cout << "住址：" << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");
}


void modifyPerson(System* abs)
{
	cout << "请输入你要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//性别
		cout << "请输入性别：" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}

		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//电话
		cout << "请输入电话：" << endl;
		string  phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//住址
		cout << "请输入住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;
		cout << "修改成功！" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}


void cleanPerson(System* abs)
{
	int choice;
	cout << "1---确认清空" << endl;
	cout << "2--返回系统" << endl;
	cin >> choice;
	if (choice == 1) {
		abs->m_Size = 0;//将人数重置为0
		cout << "系统已清空" << endl;
	}
	system("pause");
	system("cls");
}



//菜单界面
void showMenu()
{
	cout << "****************************" << endl;
	cout << "*****  1.添加学生信息  *****" << endl;
	cout << "*****  2.显示学生信息  *****" << endl;
	cout << "*****  3.删除学生信息  *****" << endl;
	cout << "*****  4.查找学生信息  *****" << endl;
	cout << "*****  5.修改学生信息  *****" << endl;
	cout << "*****  6.清空学生信息  *****" << endl;
	cout << "*****  0.退出查询系统  *****" << endl;
	cout << "****************************" << endl;
}

int main()
{

	//创建系统结构体变量
	System abs;
	//初始化系统当前学生个数
	abs.m_Size = 0;

	int select = 0; //创建用户选择输入的变量
	
	while (true)
	{
		//菜单调用
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1:// 1.添加学生信息 
			addStudent(&abs);//利用地址传递 可以修饰实参
			break;
		case 2://2.显示学生信息
			showPerson(&abs);
			break;
		case 3:// 3.删除学生信息
			deletePerson(&abs);
			break;
		case 4:// 4.查找学生信息
			findPerson(&abs);
			break;
		case 5:// 5.修改学生信息 
			modifyPerson(&abs);
			break;
		case 6:// 6.清空学生信息	
			cleanPerson(&abs);
			break;
		case 0:// 0.退出查询系统
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}
