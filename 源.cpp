#include<iostream>
#include<cstdio>
#include<cstring>

#define Frame1 "     ----------------------学生成绩-----------------------\n"
#define Frame2 "     |    学号    |   姓名   | 语文 | 数学 | 英语 | 总分 |\n"
#define Frame3 "     |------------|----------|------|------|------|------|\n"
#define Frame4 "     -----------------------------------------------------\n"
#define Format "     |%10s  |%10s|%6d|%6d|%6d|%6d|\n"

using namespace std;

typedef struct Grade
{
    char id[10];    //学号
    char name[8];  //姓名
    int score[4];      //a[0]、a[1]、a[2]、a[3]分别存语文、数学、英语三科成绩和总分，用数组便于后面的选择操作。
} Student;

typedef struct LNode
{
    Student stu;         //数据域，为结构体类型，用于存放学号、姓名、三科成绩和总分
    struct LNode *next;  //指针域，指向下一个结点
} LNode,*LinkList;

void printf_menu()    //菜单
{
    printf("                   学生成绩管理系统               \n");
    printf("    *********************菜单*********************\n");
    printf("    *    1.创建学生信息         2.删除学生信息   *\n");
    printf("    *    3.查询学生信息         4.修改学生信息   *\n");
    printf("    *    5.增加学生信息         6.统计学生信息   *\n");
    printf("    *    7.排序学生资料         8.输出学生信息   *\n");
    printf("    *    9.从文件读入学生信息   10.保存学生信息  *\n");
    printf("    *    11.帮助                12.退出系统      *\n");
    printf("    **********************************************\n");
    cout << endl;
}

void print_Node(LNode *p)//输出某一个学生的信息
{
    printf(Frame1);
    printf(Frame2);
    printf(Frame3);
    printf(Format,p->stu.id,p->stu.name,p->stu.score[0],p->stu.score[1],p->stu.score[2],p->stu.score[3]);//输出学生信息
    printf(Frame4);
}

void PrintList(LinkList L)//将所有的学生信息输出
{
    printf("现在的学生信息如下：\n");
    LNode *p=L->next;
    printf(Frame1);
    printf(Frame2);
    printf(Frame3);
    while(p)
    {
        printf(Format,p->stu.id,p->stu.name,p->stu.score[0],p->stu.score[1],p->stu.score[2],p->stu.score[3]);
        printf(Frame4);
        p=p->next;
    }
}

void CreateList(LinkList &L)
{
    int n;
    cout<<"请输入学生个数：";
    cin>>n;
    L->next=NULL;
    LNode *p,*r;                 //p指向刚建立的节点，r指向链表最后一个节点
    r=L;
    cout<<"分别输入每个学生的学号、姓名和语文、数学、英语三科的成绩"<<endl;
    for(int i=0; i<n; i++)
    {
        p=new LNode;
        p->next=NULL;
        cin>>p->stu.id>>p->stu.name>>p->stu.score[0]>>p->stu.score[1]>>p->stu.score[2];   //依次输入学生数据
        p->stu.score[3]=p->stu.score[0]+p->stu.score[1]+p->stu.score[2];        //总分不另外输入，由前三科的总和呈现
        r->next=p;
        r=p;
    }
}

void Delete_Node(LinkList &L)
{
    LNode *p=L->next,*pre=L;
    char id[10];
    cout<<"请输入需要删除的学生的学号：";
    cin>>id;
    while(p)
    {
        if(strcmp(p->stu.id,id)==0)//判断学号是否相同
        {
            pre->next=p->next;//相同则把这个节点删除
            break;
        }
        else
        {
            pre=pre->next;//不相同则遍历下一个节点
            p=p->next;
        }
    }
    if(p!=NULL)
        cout<<"删除成功!"<<endl;
    delete p;
}

void Search(LinkList L)
{
    int selection;
    cout<<"下面进行查找操作 1.按学号查找 2.按姓名查找"<<endl;
    cout<<"请输入（1-2）：";
    cin>>selection;
    switch(selection)
    {
    case 1:            //按照学号查找
    {
        string id;
        cout<<"请输入需要查询的学生学号:";
        cin>>id;
        LNode *p=L->next;
        while(p)
        {
            if(p->stu.id==id)//判断学号是否相同
            {
                cout<<"该学生信息如下："<<endl;//相同则输出该学生的所有信息
                print_Node(p);
                break;
            }
            p=p->next;//不相同则遍历下一个结点
        }
        if(!p) cout<<"无该学生信息"<<endl;
        break;
    }
    case 2:            //按照姓名查找
    {
        string name;
        cout<<"请输入需要查询的学生姓名:";
        cin>>name;
        LNode *p=L->next;
        while(p)
        {
            if(p->stu.name==name)//判断姓名是否相同
            {
                cout<<"该学生信息如下："<<endl;//相同则输出该学生的所有信息
                print_Node(p);
                break;
            }
            p=p->next;//不相同则遍历下一个结点
        }
        if(!p) cout<<"无该学生信息"<<endl;
        break;
    }
    }
}

void Modify_Node(LinkList &L)  //4.修改学生信息
{
    cout<<"请输入需要修改的学生学号：";
    string id;
    cin>>id;
    LNode *p=L->next;
    while(p)//对链表进行遍历
        if(p->stu.id!=id)//判断学号是否相同
            p=p->next;//不同则遍历下一个结点
        else break;
    if(!p)
    {
        cout<<"该学号学生不存在，无法进行修改"<<endl;
        return ;
    }
    cout<<"请分别输入新的学生信息：";
    cin>>p->stu.id>>p->stu.name>>p->stu.score[0]>>p->stu.score[1]>>p->stu.score[2]; //输入新的学生信息
    p->stu.score[3]=p->stu.score[0]+p->stu.score[1]+p->stu.score[2];                    //计算出新的总分
    cout<<"修改成功！"<<endl;
}

void Add(LinkList &L)
{
    LNode *p=new LNode;
    cout<<"请分别输入新增学生的学号、姓名和语文、数学、英语三科成绩"<<endl;
    cin>>p->stu.id>>p->stu.name;
    cin>>p->stu.score[0]>>p->stu.score[1]>>p->stu.score[2];
    p->stu.score[3]=p->stu.score[0]+p->stu.score[1]+p->stu.score[2];
    p->next=L->next;//头插法创建一个新的结点
    L->next=p;
    cout<<"增添成功！";
}


void Statistic(LinkList L)  //6.统计学生资料
{
    LNode* p;
    p = L->next;
    int n = 0;
    cout << "请输入您要统计的科目：1.语文 2.数学 3.英语 4.总分" << endl;
    int opt;
    cin >> opt;
    cout << "请输入您要统计的分数段（依次输入最低分和最高分，中间用空格间隔）：";
    int min, max;
    cin >> min >> max;//输入最低分和最高分
    switch (opt)
    {
    case 1:
    {
        while (p)
        {
            if (p->stu.score[0] >= min && p->stu.score[0] <= max)//判断该生该科分数是否位于这个分数段
                n++;
            p = p->next;
        }
    }
    case 2:
    {
        while (p)
        {
            if (p->stu.score[1] >= min && p->stu.score[1] <= max)//判断该生该科分数是否位于这个分数段
                n++;
            p = p->next;
        }
    }
    case 3:
    {
        while (p)
        {
            if (p->stu.score[2] >= min && p->stu.score[2] <= max)//判断该生该科分数是否位于这个分数段
                n++;
            p = p->next;
        }
    }
    case 4:
    {
        while (p)
        {
            if (p->stu.score[3] >= min && p->stu.score[3] <= max)//判断该生总分数是否位于这个分数段
                n++;
            p = p->next;
        }
    }
    }
    cout << "处于该分数段的学生的人数为：" << n << endl;

}

void SortList(LinkList &L)
{
    int t1,t2;
    cout<<"请选择需要排序的科目(1-4)：1.语文 2.数学 3.英语 4.总分"<<endl;
    cin>>t1;
    cout<<"请选择排序方法(1-2)：1.升序 2.降序"<<endl;
    cin>>t2;
    LNode *pre,*p,*r;
    r=L->next;
    L->next=NULL;
    switch(t2)
    {
    case 1:     //从小到大排列
    {
        while(r)//冒泡法排序
        {
            pre=L;
            p=L->next;
            while(p&&r->stu.score[t1-1]>p->stu.score[t1-1])
            {
                pre=pre->next;
                p=p->next;
            }
            pre->next=r;
            r=r->next;
            pre->next->next=p;
        }
    }
    case 2:            //从大到小排列
    {
        while(r)//冒泡排序
        {
            pre=L;
            p=L->next;
            while(p&&r->stu.score[t1-1]<p->stu.score[t1-1])
            {
                pre=pre->next;
                p=p->next;
            }
            pre->next=r;
            r=r->next;
            pre->next->next=p;
        }
    }
    }
    cout<<"排序完成！";
}

void Save(LinkList L)
{
    FILE *fp;
    LNode *p;
    int count=0;
    fp=fopen("file","wb");//打开文件，不存在文件则新建一个文件
    if(fp==NULL)
    {
        cout<<"文件打开失败！"<<endl;
        getchar();
        return;
    }
    p=L->next;
    while(p)           //通过循环操作，将学生信息一一存入file文件中
    {
        if(fprintf(fp,"%s %s %d %d %d %d\n",p->stu.id,p->stu.name,p->stu.score[0],p->stu.score[1],p->stu.score[2],p->stu.score[3]))
        {
            p=p->next;
            count++;
        }
        else break;
    }
    if(count)
        cout<<"已保存"<<count<<"个学生信息"<<endl;    //输出已经保存学生个数
    else cout<<"没有学生信息被保存"<<endl;
    fclose(fp);
}

void Read_in(LinkList &L)
{
    FILE *fp;
    fp=fopen("file","rb");//打开文件
    int n;
    cout<<"请输入需要读入学生的个数：";
    cin>>n;
    LNode *p,*r;
    r=L;
    for(int i=0; i<n; i++)
    {
        p=new LNode;
        p->next=NULL;
        fscanf(fp,"%s %s %d %d %d %d",p->stu.id,p->stu.name,&p->stu.score[0],&p->stu.score[1],&p->stu.score[2],&p->stu.score[3]);//对文件中的数据进行读取
        r->next=p;
        r=p;
    }
    fclose(fp);
}

void Help()
{
    printf("    **********************************************\n");
    cout << "            帮助文档（首次使用前必读）        " << endl;
    cout << "     1.首次使用请先创建一个新的学生信息库      " << endl;
    cout << "     2.每次修改数据后请保存进文档，以防文件丢失" << endl;
    cout << "     3.按照菜单提示键入数字代号                " << endl;
    printf("    **********************************************\n");
    cout << endl;
}

int main()
{
    printf_menu();  //操作菜单
    int operation;
    LinkList L=new LNode;
    L->next=NULL;
    do
    {
        cout<<endl<<endl;
        cout<<"请输入需要进行的操作：";
        cin>>operation;
        switch(operation)
        {
        case 1:
            CreateList(L);
            break;     //1.登记学生信息
        case 2:
            Delete_Node(L);
            break;    //2.删除学生信息
        case 3:
            Search(L);
            break;         //3.查询学生信息
        case 4:
            Modify_Node(L);
            break;    //4.修改学生信息
        case 5:
            Add(L);
            break;    //5.增加学生信息
        case 6:
            Statistic(L);
            break;      //6.统计学生信息
        case 7:
            SortList(L);
            break;       //7.排序学生资料
        case 8:
            PrintList(L);
            break;      //8.输出学生信息
        case 9:
            Read_in(L);
            break;        //9.从文件读入学生信息
        case 10:
            Save(L);
            break;      //10.保存学生信息
        case 11:
            Help();
            break;      //输出帮助文档
        case 12:
            return 0;
            break;                   //0.退出系统
        }
    }
    while(operation);
}
