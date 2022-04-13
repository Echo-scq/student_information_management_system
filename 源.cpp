#include<iostream>
using namespace std;
#define max 100

struct Student {  // 学生信息结构体
	char id[8];
	char name[20];
	int Math_score;
	int English_score;
}stu[max];

int num;//学生人数

void printf_menu()//对菜单进行输出
{
	cout << "************************************" << endl;
	cout << "****--欢迎使用教务管理系统--********" << endl;
	cout << "****    ***创建学生信息库***    ****" << endl;
	cout << "****   1.输入学生信息           ****" << endl;
	cout << "****   2.显示现有学生数据       ****" << endl;
	cout << "****   3.按姓名查询学生信息     ****" << endl;
	cout << "****   4.按学号查询             ****" << endl;
	cout << "****   5.删除学生信息           ****" << endl;
	cout << "****   6.按照学生成绩进行排序   ****" << endl;
	cout << "****   7.插入学生信息           ****" << endl;
	cout << "****   8.将现有学生信息进行保存 ****" << endl;
	cout << "****     ***学生信息维护***     ****" << endl;
	cout << "****   9.增加学生信息           ****" << endl;
	cout << "****   10.删除学生信息          ****" << endl;
	cout << "****   11.修改学生信息          ****" << endl;
	cout << "****   12.退出程序              ****" << endl;
	cout << "************************************" << endl;
	cout << endl;
}

void Input_Date()//对学生信息进行输入
{
	int n;
	cout << "请输入学生人数：";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		printf("请输入第%d个人的学号:", i);
		scanf_s("%s", &stu[i].id, 8);
		printf("请输入第%d个人的名字:", i);
		scanf_s("%s", &stu[i].name, 20);
		printf("请输入第%d个人的数学成绩:", i);
		scanf_s("%d", &stu[i].Math_score);
		printf("请输入第%d个人的英语成绩:", i);
		scanf_s("%d", &stu[i].English_score);
		printf("\n");
	}
	num = n;
	putchar('\n');
}

void Put_Date()//将现有学生信息进行输出
{
	if (num <= 0)
	{
		cout << "该系统中没有学生信息" << endl;
		return;
	}
	cout << "学号     姓名     数学     英语" << endl;
	for (int i = 1; i <= num; i++)
	{
		printf("%-9s%-9s%-9d%-9d\n", stu[i].id, stu[i].name, stu[i].Math_score, stu[i].English_score);
	}
	putchar('\n');
}

void search_name()//按照学生姓名进行查询
{
	cout << "请输入你要查询的学生的姓名：";
	char name[20];
	cin >> name;
	for (int i = 1; i <= num; i++)
	{
		if (strcmp(stu[i].name, name) == 0)
		{
			cout << "学号     姓名     数学     英语" << endl;
			printf("%-9s%-9s%-9d%-9d\n", stu[i].id, stu[i].name, stu[i].Math_score, stu[i].English_score);
		}
	}
	putchar('\n');
}

void search_id()//按照学生学号进行查询
{
	cout << "请输入你要查询的学生的学号：";
	char id[8];
	cin >> id;
	for (int i = 1; i <= num; i++)
	{
		if (strcmp(stu[i].id, id) == 0)
		{
			cout << "学号     姓名     数学     英语" << endl;
			printf("%-9s%-9s%-9d%-9d\n", stu[i].id, stu[i].name, stu[i].Math_score, stu[i].English_score);
		}
	}
	cout << endl;
}

void delete_date()//删除学生信息
{
	cout << "请输入你要删除的学生的学号：";
	char id[8];
	cin >> id;
	int i;
	for ( i = 1; i <= num; i++)
	{
		if (strcmp(stu[i].id, id) == 0)
		{
			for (int j = i; j <= num; j++)
			{
				stu[j] = stu[j + 1];
			}
			cout << "删除成功" << endl;
			num--;
		}
	}
	cout << endl;
}

void sort_date()//按照学生某科的成绩进行由大到小排序
{
	cout << "请输入排序科目标准" << endl;
	cout << "数学请按1；英语请按2" << endl;
	int n;
	Student student;
	cin >> n;
	switch (n)
	{
	case 1: {
		for (int i = 1; i < num; i++)
		{
			if (stu[i].Math_score < stu[i + 1].Math_score)
			{
				student = stu[i];
				stu[i] = stu[i + 1];
				stu[i + 1] = student;
			}
		}
		cout << "排序成功" << endl;
		break;
	}
	case 2: {
		for (int i = 1; i < num; i++)
		{
			if (stu[i].English_score < stu[i + 1].English_score)
			{
				student = stu[i];
				stu[i] = stu[i + 1];
				stu[i + 1] = student;
			}
		}
		cout << "排序成功" << endl;
		break;
	}
	default:cout << "输入错误" << endl; break;
	}
}

void insert_date()//插入学生信息
{
	cout << "请输入要插入的位置：";
	int n;
	Student student;
	cin >> n;
	if (n<1 || n>num + 1)
	{
		cout << "输入错误" << endl;
		return;
	}
	else
	{
		printf("请输入该学生的学号:");
		scanf_s("%s", &student.id, 8);
		printf("请输入该学生的名字:");
		scanf_s("%s", &student.name, 20);
		printf("请输入该学生的数学成绩:");
		scanf_s("%d", &student.Math_score);
		printf("请输入该学生的英语成绩:");
		scanf_s("%d", &student.English_score);
	}
	for (int i = num; i >= n; i--)
	{
		stu[i + 1] = stu[i];
	}
	stu[n] = student;
	num++;
}

void save_date()//对现有学生信息进行保存
{
	FILE* fp;
	fopen_s(&fp, "shuju.txt", "w");//以只写方式打开文件
	if (NULL == fp)
	{
		printf("Failed to open the file !\n");
		exit(0);
	}
	for (int i = 1; i <= num; i++)
	{
		fprintf(fp, "%s %s %d %d\n", stu[i].id, stu[i].name, stu[i].Math_score, stu[i].English_score);//对文件进行写入
	}
	fclose(fp);//关闭文件
}

void add_date()//增加学生信息
{
	Student student;
	printf("请输入该学生的学号:");
	scanf_s("%s", &student.id, 8);
	printf("请输入该学生的名字:");
	scanf_s("%s", &student.name, 20);
	printf("请输入该学生的数学成绩:");
	scanf_s("%d", &student.Math_score);
	printf("请输入该学生的英语成绩:");
	scanf_s("%d", &student.English_score);
	stu[num + 1] = student;
	num++;
	save_date();
	cout << "增加成功" << endl;
	cout << endl;
}

void delete_date_from_datebase()//从数据库中删除学生信息
{
	cout << "请输入您要删除的学生的学号：";
	char id[8];
	scanf_s("%s", id, 8);
	for (int i = 1; i <= num; i++)
	{
		if (strcmp(stu[i].id, id) == 0)
		{
			for (int j = i; j <= num; j++)
			{
				stu[j] = stu[j + 1];
			}
		}
	}
	num--;
	save_date();
	cout << "删除成功" << endl;
	cout << endl;
}

void date_change()
{
	cout << "请输入你要修改的学生的学号：";
	char id[8];	
	scanf_s("%s", id, 8);
	cout << "请输入您要修改的项目：1.学号 2.姓名 3.数学成绩 4.英语成绩" << endl;
	int a;
	cin >> a;
	for (int i = 1; i <= num; i++)
	{
		if (strcmp(stu[i].id, id) == 0)
		{
			switch (a)
			{
			case 1: {
				cout << "请输入修改后的学生学号：";
				char id[8];
				scanf_s("%s", id, 8);
				strcpy_s(stu[i].id, id);
				break;
			}
			case 2: {
				cout << "请输入修改后的学生的姓名：";
				char name[20];
				scanf_s("%s", name, 20);
				strcpy_s(stu[i].name, name);
				break;
			}
			case 3: {
				cout << "请输入修改后该学生的数学成绩：";
				int math;
				cin >> math;
				stu[i].Math_score = math;
				break;
			}
			case 4: {
				cout << "请输入修改后该学生的英语成绩：";
				int english;
				cin >> english;
				stu[i].English_score = english;
				break;
			}
			}
		}
	}
	save_date();
	cout << "修改成功" << endl;
	cout << endl;
}

int main()
{
	while (1)
	{
		printf_menu();
		cout << "请选择操作选项：";
		int opt;
		cin >> opt;
		switch (opt)
		{
		case 1:Input_Date(); break;
		case 2:Put_Date(); break;
		case 3:search_name(); break;
		case 4:search_id(); break;
		case 5:delete_date(); break;
		case 6:sort_date(); break;
		case 7:insert_date(); break;
		case 8:save_date(); break;
		case 9:add_date(); break;
		case 10:delete_date_from_datebase(); break;
		case 11:date_change(); break;
		case 12:return 0;
		}
	}
	return 0;
}