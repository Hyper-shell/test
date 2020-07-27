#include <stdio.h>
#include <string.h>
#include <getch.h>
#include <stdlib.h>
#include <ctype.h>
//通讯录

static int count=0;//有效联系人数量
//static char name[100][20] = {0};
//static char tel[100][12] = {};
//static char sex[100] = {};

struct Compeople
{
	char name[20];
	char tel[20];
	char sex;//[100];
};

struct Compeople co[100];

void show_msg(const char* msg,float sec)
{
	printf("%s",msg);
	fflush(stdout);
	usleep(sec*1000000);
}

void any_key()
{
	stdin->_IO_read_ptr = stdin->_IO_read_end;//有点小问题
	puts("press任意键继续");
	getch();

}

void add_TXL()//添加
{
	if(count >= 100)
	{
		puts("系统正在升级");
		return ;
	}
	int i=0;
	while(co[i].sex)i++;	
	printf("输入添加的姓名 性别 电话:");
	scanf("%s %c %s", co[i].name,&co[i].sex+i,co[i].tel);
	count++;
	show_msg("添加联系人成功",1.5);
	printf("%d %s %c %s\n",i,co[i].name,co[i].sex+i,co[i].tel);
}

void del_TXL()//删除
{
	char i=0;
	char key[20]={};
	printf("输入要删除的电话或姓名");
	scanf("%s",key);
	do{
		if(co[i].sex)
		{
			if(isdigit(key[0]))
			{
				if(0==strcmp(co[i].tel,key)) break;
			}
			else
			{
				if(0==strcmp(co[i].name,key)) break;
			}
			
		}
	}while(++i<100);

	if(i<100)
	{
		printf("删除%s %s %s成功\n",co[i].name[i],'w'==co[i].sex?"女":"男",co[i].tel);
		co[i].sex=0;
		count--;
	}
	else
	{
		printf("没有找到联系人 检查条件%s", key);
	}
	
	show_msg("",1.5);
}


void modify(void)
{
	char i=0;
	char key[20]={};
	printf("输入要修改的联系人姓名:");
	scanf("%s", key);
	do{
		if(co[i].sex && 0 == strcmp(co[i].name,key))
		{
			printf("请重新输入联系人的姓名 性别 电话:");
			scanf("%s %s %s",co[i].name,co[i].sex+i,co[i].tel);
			show_msg("修改联系人成功\n",1.5);
			return;
		}
	}while(++i<100);
	show_msg("未找到该联系人\n",1.5);
}


void find(void)
{
	char key[20]={};
	printf("请输入要查询的关键字:");
	scanf("%s", key);
	for(int i=0;i<100;i++)
	{
		if(co[i].sex && (strstr(co[i].name,key) || strstr(co[i].tel,key)));
		{
			printf("%s %s %s\n",co[i].name,'w'==co[i].sex?"女":"男",co[i].tel);
		}
	}
	any_key();
}

void list_TXL()
{
	for(int i=0;i<100;i++)
	{
		if(co[i].sex)
		{
			printf("%s %s %s\n", co[i].name,'w'==co[i].sex?"女":"男",co[i].tel);
		}
	}
	any_key();

}

char menu(void)
{
	int n=0;
	system("clear");
	puts("---通讯录---");
	puts("1、添加");
	puts("2、删除");
	puts("3、修改");
	puts("4、查找");
	puts("5、所有");
	puts("6、退出");
	puts("输入指令");
	char cmd=getch();
	printf("%c\n",cmd);
	return cmd;
}

int main(int argc,const char* argv[])
{
//	struct Compeople co;
	for(;;)
	{	
		switch(menu())
		{
			case '1':add_TXL();break;
			case '2':del_TXL();break;
			case '3':modify();break;
			case '4':find();break;
			case '5':list_TXL();break;
			case '6':return 0;
			default:puts("输入不合法");break;
		}
	}//for循环的下括号
}
