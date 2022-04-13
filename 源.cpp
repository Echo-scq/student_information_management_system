#include<iostream>
using namespace std;
#define max 100

struct Student {  // ѧ����Ϣ�ṹ��
	char id[8];
	char name[20];
	int Math_score;
	int English_score;
}stu[max];

int num;//ѧ������

void printf_menu()//�Բ˵��������
{
	cout << "************************************" << endl;
	cout << "****--��ӭʹ�ý������ϵͳ--********" << endl;
	cout << "****    ***����ѧ����Ϣ��***    ****" << endl;
	cout << "****   1.����ѧ����Ϣ           ****" << endl;
	cout << "****   2.��ʾ����ѧ������       ****" << endl;
	cout << "****   3.��������ѯѧ����Ϣ     ****" << endl;
	cout << "****   4.��ѧ�Ų�ѯ             ****" << endl;
	cout << "****   5.ɾ��ѧ����Ϣ           ****" << endl;
	cout << "****   6.����ѧ���ɼ���������   ****" << endl;
	cout << "****   7.����ѧ����Ϣ           ****" << endl;
	cout << "****   8.������ѧ����Ϣ���б��� ****" << endl;
	cout << "****     ***ѧ����Ϣά��***     ****" << endl;
	cout << "****   9.����ѧ����Ϣ           ****" << endl;
	cout << "****   10.ɾ��ѧ����Ϣ          ****" << endl;
	cout << "****   11.�޸�ѧ����Ϣ          ****" << endl;
	cout << "****   12.�˳�����              ****" << endl;
	cout << "************************************" << endl;
	cout << endl;
}

void Input_Date()//��ѧ����Ϣ��������
{
	int n;
	cout << "������ѧ��������";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		printf("�������%d���˵�ѧ��:", i);
		scanf_s("%s", &stu[i].id, 8);
		printf("�������%d���˵�����:", i);
		scanf_s("%s", &stu[i].name, 20);
		printf("�������%d���˵���ѧ�ɼ�:", i);
		scanf_s("%d", &stu[i].Math_score);
		printf("�������%d���˵�Ӣ��ɼ�:", i);
		scanf_s("%d", &stu[i].English_score);
		printf("\n");
	}
	num = n;
	putchar('\n');
}

void Put_Date()//������ѧ����Ϣ�������
{
	if (num <= 0)
	{
		cout << "��ϵͳ��û��ѧ����Ϣ" << endl;
		return;
	}
	cout << "ѧ��     ����     ��ѧ     Ӣ��" << endl;
	for (int i = 1; i <= num; i++)
	{
		printf("%-9s%-9s%-9d%-9d\n", stu[i].id, stu[i].name, stu[i].Math_score, stu[i].English_score);
	}
	putchar('\n');
}

void search_name()//����ѧ���������в�ѯ
{
	cout << "��������Ҫ��ѯ��ѧ����������";
	char name[20];
	cin >> name;
	for (int i = 1; i <= num; i++)
	{
		if (strcmp(stu[i].name, name) == 0)
		{
			cout << "ѧ��     ����     ��ѧ     Ӣ��" << endl;
			printf("%-9s%-9s%-9d%-9d\n", stu[i].id, stu[i].name, stu[i].Math_score, stu[i].English_score);
		}
	}
	putchar('\n');
}

void search_id()//����ѧ��ѧ�Ž��в�ѯ
{
	cout << "��������Ҫ��ѯ��ѧ����ѧ�ţ�";
	char id[8];
	cin >> id;
	for (int i = 1; i <= num; i++)
	{
		if (strcmp(stu[i].id, id) == 0)
		{
			cout << "ѧ��     ����     ��ѧ     Ӣ��" << endl;
			printf("%-9s%-9s%-9d%-9d\n", stu[i].id, stu[i].name, stu[i].Math_score, stu[i].English_score);
		}
	}
	cout << endl;
}

void delete_date()//ɾ��ѧ����Ϣ
{
	cout << "��������Ҫɾ����ѧ����ѧ�ţ�";
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
			cout << "ɾ���ɹ�" << endl;
			num--;
		}
	}
	cout << endl;
}

void sort_date()//����ѧ��ĳ�Ƶĳɼ������ɴ�С����
{
	cout << "�����������Ŀ��׼" << endl;
	cout << "��ѧ�밴1��Ӣ���밴2" << endl;
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
		cout << "����ɹ�" << endl;
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
		cout << "����ɹ�" << endl;
		break;
	}
	default:cout << "�������" << endl; break;
	}
}

void insert_date()//����ѧ����Ϣ
{
	cout << "������Ҫ�����λ�ã�";
	int n;
	Student student;
	cin >> n;
	if (n<1 || n>num + 1)
	{
		cout << "�������" << endl;
		return;
	}
	else
	{
		printf("�������ѧ����ѧ��:");
		scanf_s("%s", &student.id, 8);
		printf("�������ѧ��������:");
		scanf_s("%s", &student.name, 20);
		printf("�������ѧ������ѧ�ɼ�:");
		scanf_s("%d", &student.Math_score);
		printf("�������ѧ����Ӣ��ɼ�:");
		scanf_s("%d", &student.English_score);
	}
	for (int i = num; i >= n; i--)
	{
		stu[i + 1] = stu[i];
	}
	stu[n] = student;
	num++;
}

void save_date()//������ѧ����Ϣ���б���
{
	FILE* fp;
	fopen_s(&fp, "shuju.txt", "w");//��ֻд��ʽ���ļ�
	if (NULL == fp)
	{
		printf("Failed to open the file !\n");
		exit(0);
	}
	for (int i = 1; i <= num; i++)
	{
		fprintf(fp, "%s %s %d %d\n", stu[i].id, stu[i].name, stu[i].Math_score, stu[i].English_score);//���ļ�����д��
	}
	fclose(fp);//�ر��ļ�
}

void add_date()//����ѧ����Ϣ
{
	Student student;
	printf("�������ѧ����ѧ��:");
	scanf_s("%s", &student.id, 8);
	printf("�������ѧ��������:");
	scanf_s("%s", &student.name, 20);
	printf("�������ѧ������ѧ�ɼ�:");
	scanf_s("%d", &student.Math_score);
	printf("�������ѧ����Ӣ��ɼ�:");
	scanf_s("%d", &student.English_score);
	stu[num + 1] = student;
	num++;
	save_date();
	cout << "���ӳɹ�" << endl;
	cout << endl;
}

void delete_date_from_datebase()//�����ݿ���ɾ��ѧ����Ϣ
{
	cout << "��������Ҫɾ����ѧ����ѧ�ţ�";
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
	cout << "ɾ���ɹ�" << endl;
	cout << endl;
}

void date_change()
{
	cout << "��������Ҫ�޸ĵ�ѧ����ѧ�ţ�";
	char id[8];	
	scanf_s("%s", id, 8);
	cout << "��������Ҫ�޸ĵ���Ŀ��1.ѧ�� 2.���� 3.��ѧ�ɼ� 4.Ӣ��ɼ�" << endl;
	int a;
	cin >> a;
	for (int i = 1; i <= num; i++)
	{
		if (strcmp(stu[i].id, id) == 0)
		{
			switch (a)
			{
			case 1: {
				cout << "�������޸ĺ��ѧ��ѧ�ţ�";
				char id[8];
				scanf_s("%s", id, 8);
				strcpy_s(stu[i].id, id);
				break;
			}
			case 2: {
				cout << "�������޸ĺ��ѧ����������";
				char name[20];
				scanf_s("%s", name, 20);
				strcpy_s(stu[i].name, name);
				break;
			}
			case 3: {
				cout << "�������޸ĺ��ѧ������ѧ�ɼ���";
				int math;
				cin >> math;
				stu[i].Math_score = math;
				break;
			}
			case 4: {
				cout << "�������޸ĺ��ѧ����Ӣ��ɼ���";
				int english;
				cin >> english;
				stu[i].English_score = english;
				break;
			}
			}
		}
	}
	save_date();
	cout << "�޸ĳɹ�" << endl;
	cout << endl;
}

int main()
{
	while (1)
	{
		printf_menu();
		cout << "��ѡ�����ѡ�";
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