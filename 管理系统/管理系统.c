#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <windows.h>
#include <stdlib.h> 
#include <conio.h>

struct User {
	char username[20];
	char password[50];
};

struct EmperorInformation {
	int num;
	char name[100];
	char dynasty[50];
	char address[50];
	struct EmperorInformation* next;
};

void safe_flush(FILE* fp);                                                  //用于清空缓冲区 
struct EmperorInformation*CreateList(void);                                 //用于创建一个结点 
void mainMenu(void);                                               			//创建主菜单 
int getMenuNum(void);                                              			//获取菜单选项编号 
void CreateUsersFile(void);                                        			//创建存储用户账号密码的文件 
void Register(void);                                               			//用于用户注册 
void Login(void);                                              				//用于用户登录 
void LoginMenu(void);                                          				//用于创建登陆界面 
struct EmperorInformation* CreateEmperor(void);                				//用于创建新的帝王陵结点 
void AddEmperorByHead(struct EmperorInformation* list );       				//用于在链表开头处添加帝王陵信息 
void AddEmperorByEnd(struct EmperorInformation* list);         				//用于在链表结尾处添加帝王陵信息 
void AddEmperorByPos(struct EmperorInformation* list);         				//用于在链表指定位置处添加帝王陵信息
void ShowAll(struct EmperorInformation* list);          				    //用于显示所有帝王陵信息 
void DeleteEmperorByNum(struct EmperorInformation* list, int num);          //用于根据编号删除帝王陵信息 
void DeleteEmperorByName(struct EmperorInformation* list, char name[100]);  //用于根据皇帝姓名删除帝王陵信息 
void FindEmperorByNum(struct EmperorInformation* list,int num);             //用于根据编号查询帝王陵信息 
void FindEmperorByName(struct EmperorInformation* list, char name[100]);    //用于根据皇帝姓名查询黄帝陵信息 
void ChangeEmperorByNum(struct EmperorInformation* list,int num);           //用于根据编号修改帝王陵信息 
void ChangeEmperorByName(struct EmperorInformation* list, char name[100]);  //用于根据皇帝名字修改帝王陵信息 
void sorted(struct EmperorInformation* list);                               //用于按照朝代顺序升序排序 
void sorted_reverse(struct EmperorInformation* list);                       //用于按照朝代顺序降序排序 
void load(struct EmperorInformation* list);                                 //用于读取文件 
void save(struct EmperorInformation* list);                                 //用于保存文件 
void statistcs_dynasty(struct EmperorInformation* list);                    //用于根据朝代统计数据 
void Menu(struct EmperorInformation* list);                                 //用于创建菜单

int main(void)
{
	system("color E5");
	LoginMenu();
	return 0;
}

void safe_flush(FILE* fp)
{
	int ch;
	while ((ch=fgetc(fp))!=EOF && ch!='\n');
}

struct EmperorInformation* CreateList(void)
{
	struct EmperorInformation* list = (struct EmperorInformation*)malloc(sizeof(struct EmperorInformation));
	if(!list)
	{
		printf("\n\n\t\t\t-申请内存失败\n");
		return NULL;
	}
	list->next = NULL;
	return list;
}

void mainMenu(void)
{
	printf("\t\t\t\t\t-------------------------------------\n");
	printf("\t\t\t\t\t          帝王陵信息管理系统         \n");
	printf("\t\t\t\t\t-------------------------------------\n");
	printf("\t\t\t\t\t1.添加帝王陵信息\n");
	printf("\t\t\t\t\t2.删除帝王陵信息\n");
	printf("\t\t\t\t\t3.查找帝王陵信息\n");
	printf("\t\t\t\t\t4.修改帝王陵信息\n");
	printf("\t\t\t\t\t5.按陵墓编号排序\n");
	printf("\t\t\t\t\t6.显示所有帝王陵信息\n");
	printf("\t\t\t\t\t7.读取文件中所有帝王陵信息\n");
	printf("\t\t\t\t\t8.将帝王陵信息保存到文件\n");
	printf("\t\t\t\t\t9.统计数据\n");
	printf("\t\t\t\t\t0.退出登录\n");
	printf("\t\t\t\t\t------------------------------------\n");
	printf("\t\t\t\t\t请输入编号: "); 	
}

int getMenuNum(void)
{
	mainMenu();
	int num;
	while(scanf("%d",&num) != 1 || num<0 || num >9)
	{
		safe_flush(stdin);
		system("cls");
		mainMenu();
		printf("\n\n\t\t\t\t\t输入错误，请重新输入："); 
	}
	return num;
}

void CreateUserFile(void)
{
//	FILE *fp;
//	fp=fopen("Users.txt","a");
//	fclose(fp);
	FILE* fp;
	if((fp=fopen("User.txt","a"))==NULL){
		if((fp=fopen("User.txt","w+"))==NULL){
			printf("\n\n\t\t\t\t\t无法建立用户文件！即将退出系统\n");
			Sleep(2000);
			exit(0);
		}	
	}	
}

void Register(void)
{
	struct User a,b;
	FILE* fp;
	char temp[40];
	fp=fopen("Users.txt","a+");
	system("cls");
	printf("\t\t\t\t\t-------------------------------------\n");
	printf("\t\t\t\t\t          帝王陵信息管理系统\n");
	printf("\t\t\t\t\t-------------------------------------\n");
	fread(&b,sizeof(struct User),1, fp);
	printf("\n\n\t\t\t\t\t请输入用户名：");
	while (scanf("%s", a.username) != 1)
	{
		printf("\n\n\t\t\t\t\t输入错误，请重新输入：");
		safe_flush(stdin);
	}
	
	while(1)
	{
		if(strcmp(a.username, b.username))
		{
			if(!feof(fp))
				fread(&b,sizeof(struct User),1,fp);
			else
				break;
		}
		else
		{
			printf("\n\n\t\t\t\t\t该用户名已被注册，即将返回登录界面\n");
			fclose(fp);
			Sleep(3000);
			LoginMenu();
			return;
		}
	}
	
	printf("\n\n\t\t\t\t\t请输入密码: ");
	int i=0;
	while((a.password[i] = _getch())!='\r')
	{
		if(a.password[i] == '\b' && i>=1)
		{
			printf("\b \b");
			i--;
		}
		else if (a.password[i] == '\b' && i==0);
		else
		{
			printf("*");
			i++;
		}
	}
	a.password[i] = '\0';
	printf("\n\n\t\t\t\t\t请确认密码：");
	i = 0;
	while((temp[i] = _getch()) != '\r')
	{
		if(temp[i] == '\b' && i >= 1){
			printf("\b \b");
			i--;
		}
		else if(temp[i] == '\b' && i==0);
		else
		{
			printf("*");
			i++;
		}
	} 
	temp[i]='\0';
	do{
		if(strcmp(a.password,temp)==0){
			fp=fopen("Users.txt","a");
			fwrite(&a,sizeof(struct User),1,fp);
			printf("\n\n\t\t\t\t\t注册成功！即将返回登陆界面...\n");
			fclose(fp);
			Sleep(3000);
			LoginMenu();
			return;
		}
		else
		{
			printf("\n\n\t\t\t\t\t两次密码不一致，请重新输入！\n");
			printf("\n\n\t\t\t\t\t请输入密码：");
			i=0;
			while((a.password[i]=_getch()) != '\r')
			{
				if(a.password[i] == '\b' && i>=1)
				{
					printf("\b \b");
					i--;
				}
				else if (a.password[i] == '\b' && i==0);
				else{
					printf("*");
					i++;
				}
			}
			a.password[i]='\0';
			printf("\n\n\t\t\t\t\t请确认密码：");
			i = 0;
			while((temp[i]=_getch())!='r')
			{
				if(temp[i]=='\b' && i==0)
				{
					printf("\b \b");
					i--;
				}
				else if(temp[i] == '\b' && i==0);
				else
				{
					printf("*");
					i++;
				}
			}
			temp[i]='\0';
		}
	}while(1);
}

void Login(void)
{
	struct User a,b;
	FILE* fp;
	system("cls");
	printf("\t\t\t\t\t-------------------------------------\n");
	printf("\t\t\t\t\t          帝王陵信息管理系统         \n");
	printf("\t\t\t\t\t-------------------------------------\n");	
	fp = fopen("Users.txt","r");
	fread(&b,sizeof(struct User),1,fp);
	printf("\n\n\t\t\t\t\t请输入用户名: ");
	while(scanf("%s",a.username)!=1)
	{
		printf("\n\n\t\t\t\t\t输入错误，请重新输入：");
		safe_flush(stdin);
	}
	while(1)
	{
		if(strcmp(a.username,b.username)==0)
			break;
		else{
			if(!feof(fp))
				fread(&b,sizeof(struct User),1,fp);
			else
			{
				printf("\n\n\t\t\t\t\t用户不存在！\n");
				fclose(fp);
				system("pause");
				LoginMenu();
				return; 
			}
		}
	}
	printf("\n\n\t\t\t\t\t请输入密码: ");
	int i = 0;
	while((a.password[i]=_getch())!='\r'){
		if(a.password[i]=='\b'&&i>=1){
			printf("\b \b");
			i--;
		}
		else if(a.password[i]=='\b'&&i==0);
		else{
			printf("*");
			i++;
		}
	}
	a.password[i]='\0';
	do
	{
		if(strcmp(a.password,b.password)==0)
		{
			fclose(fp);
			printf("\n\n\t\t\t\t\t登陆成功，正在进入...\n");
			Sleep(2000);
			struct EmperorInformation* list=CreateList();
			while(1)
				Menu(list);
			return; 
		}
		else
		{
			printf("\n\n\t\t\t\t\t密码错误，即将返回登陆界面...\n");
			Sleep(2000);
			LoginMenu();
		}
	}while(strcmp(a.password,b.password)==0);
} 

void LoginMenu(void)
{
	system("cls");
	printf("\t\t\t\t\t-------------------------------------\n");
	printf("\t\t\t\t\t          帝王陵信息管理系统         \n");
	printf("\t\t\t\t\t-------------------------------------\n");
	printf("\t\t\t\t\t1.登录系统\n");
	printf("\t\t\t\t\t2.新用户注册\n");
	printf("\t\t\t\t\t3.关于本系统\n");
	printf("\t\t\t\t\t4.退出\n");	
	printf("\t\t\t\t\t-------------------------------------\n");	
	printf("\t\t\t\t\t请输入对应选项: ");
	int i;
	while(scanf("%d",&i)!=1||i<0||i>4)
	{
		safe_flush(stdin);
		printf("\t\t\t\t\t输入错误！请重新输入："); 
	}
	switch(i)
	{
		case 1:
			Login();
			break;
		case 2:
			Register();
			break;
		case 3:
			system("cls");
			printf("\t\t\t\t\t\t\t-------------------------------------\n");
			printf("\t\t\t\t\t\t\t          帝王陵信息管理系统         \n");
			printf("\t\t\t\t\t\t\t-------------------------------------\n");
			printf("\t\t\t\t\t\t\t作者：陈雨涵   西安邮电大学计算机学院\n"); 
			printf("\t\t\t\t\t\t\t    大数据2001\n");
			printf("\t\t\t\t\t\t\t-------------------------------------\n");
			system("pause");
			LoginMenu();
			break;
		case 4:
			printf("\n\n\t\t\t\t\t正在退出，loading...\n");
			Sleep(3000);
			printf("\n\n\t\t\t\t\tGood Bye!\n");
			exit(0);
	}
}

struct EmperorInformation* CreateEmperor(void)
{
	struct EmperorInformation* node = (struct EmperorInformation*)malloc(sizeof(struct EmperorInformation));
	if(!node)
	{
		printf("\n\n\t\t\t\t\t申请内存失败\n");
		return NULL; 
	}
	node->next=NULL;
	printf("\n\n\t\t\t\t\t请输入帝王陵编号：");
	while(scanf("%d", &node->num)!=1)
	{
		printf("\n\n\t\t\t\t\t输入错误！请重新输入：");
		safe_flush(stdin);
	}
	node->next=NULL;
	printf("\n\n\t\t\t\t\t请输入帝王陵名称：");
	while(scanf("%s", &node->name)!=1)
	{
		printf("\n\n\t\t\t\t\t输入错误！请重新输入：");
		safe_flush(stdin);
	}
	printf("\n\n\t\t\t\t\t请输入陵墓朝代：");
	while(scanf("%s",node->dynasty)!=1)
	{
		printf("\n\n\t\t\t\t\t输入错误！请重新输入：");
		safe_flush(stdin);
	}
	printf("\n\n\t\t\t\t\t请输入陵墓所在地址：");
	while(scanf("%s",node->address)!=1)
	{
		printf("\n\n\t\t\t\t\t输入错误！请重新输入：");
		safe_flush(stdin);
	}
	return node;
}

void AddEmperorByHead(struct EmperorInformation* list)
{
	struct EmperorInformation* newEmperor = CreateEmperor();
	struct EmperorInformation* pos = list;
	while (pos->next!=NULL)
	{
		if(pos->next->num == newEmperor->num)
		{
			printf("\n\n\t\t\t\t\t编号重复，录入信息失败!\n");
			return;
		}
		pos=pos->next;
	}
	newEmperor->next=list->next;
	list->next=newEmperor;
}

void AddEmperorByEnd(struct EmperorInformation* list)
{
	struct EmperorInformation* newEmperor = CreateEmperor();
	struct EmperorInformation* pos = list;
	while(pos->next!=NULL)
	{
		if(pos->next->num == newEmperor->num)
		{
			printf("\n\n\t\t\t\t\t编号重复，录入信息失败！\n");
			return;	
		}	
		pos=pos->next;
	} 
	pos->next=newEmperor;
	newEmperor->next=NULL;
}

void AddEmperorByPos(struct EmperorInformation* list)
{
	struct EmperorInformation* pos=list;
	struct EmperorInformation* posF=list;
	if(pos->next==NULL)
	{
		printf("\n\n\t\t\t\t\t数据为空，不能添加信息！\n");
		return;
	}
	struct EmperorInformation* newEmperor=CreateEmperor();
	while(pos->next!=NULL)
	{
		if(pos->next->num == newEmperor->num)
		{
			printf("\n\n\t\t\t\t\t编号重复，录入信息失败！\n");
			return;
		}
		pos=pos->next;
	}
	int num;
	ShowAll(list);
	printf("\n\n\t\t\t\t\t请输入编号，改信息将插入在指定位置之前：");
	while(scanf("%s",&num)!=1)
	{
		printf("\n\n\t\t\t\t\t输入错误，请重新输入：");
		safe_flush(stdin);
	}
	struct EmperorInformation* pos1=list->next;
	while(pos1->num!=num)
	{
		pos1=pos1->next;
		posF=posF->next;
		if(pos1==NULL)
		{
			printf("\n\n\t\t\t\t\t未找到指定编号！\n");
			return;
		}
	}
	newEmperor->next=posF->next;
	posF->next=newEmperor;
}

void ShowAll(struct EmperorInformation* list)
{
	printf("\n");
	struct EmperorInformation* pos=list;
	printf("\t\t\t\t%s\t\t%s\t\t%s\t\t%s\n","Number","Name","Dynasty","Address");
	while(pos->next)
	{
		printf("%d\t",pos->next->num);
		printf("%s\t\t",pos->next->name);
		printf("%s\t\t",pos->next->dynasty);
		printf("%s\n",pos->next->address);
		pos=pos->next;
	}
	printf("\n");
}

void DeleteEmperorByNum(struct EmperorInformation* list, int num) 
{                  
    struct EmperorInformation* posF = list;
    struct EmperorInformation* pos = posF->next;
    if (!posF->next) {
        printf("\n\n\t\t\t\t\t数据为空！\n");
        return;
    }
    while (pos != NULL && pos->num != num) {
        pos = pos->next;
        posF = posF->next;
    }
    if (pos == NULL) {
        printf("\n\n\t\t\t\t\t数据未找到！\n");
        return;
    }
    posF->next = pos->next;
    free(pos);
    return;
}

void DeleteEmperorByName(struct EmperorInformation* list,char name[100])
{
	struct EmperorInformation* posF=list;
	struct EmperorInformation* pos=list;
	if(!posF->next)
	{
		printf("\n\n\t\t\t\t\t数据为空！\n");
		return;
	}
	while(pos!=NULL && *pos->name != *name)
	{
		pos=pos->next;
		posF=posF->next;
	}
	if(pos==NULL)
	{
		printf("\n\n\t\t\t\t\t数据未找到！\n");
		return;
	}
	posF->next = pos->next;
	free(pos);
	return;
}

void FindEmperorByNum(struct EmperorInformation* list, int num) 
{                    
    printf("\n\n\t\t\t\t\t正在查找，loading...\n");
    Sleep(2000);
    struct EmperorInformation* pos = list->next;
    if (!pos) {
        printf("\n\n\t\t\t\t\t数据为空！\n");
        system("pause");
        return;
    }
    while (pos != NULL && pos->num != num)
        pos = pos->next;
    if (pos == NULL) {
        printf("\n\n\t\t\t\t\t数据未找到！\n");
        system("pause");
        return;
    }
    printf("\t\t\t\t%s\t%s\t\t%s\t\t%s\n", "Number", "Name", "Dynasty", "Address");
    printf("%d\t", pos->num);
    printf("%s\t\t", pos->name);
    printf("%s\t\t", pos->dynasty);
    printf("%s\n\n", pos->address);
    system("pause");
}

void FindEmperorByName(struct EmperorInformation* list,char name[100])
{
	printf("\n\n\t\t\t\t\t正在查找，loading...\n");
	Sleep(2000);
	struct EmperorInformation* pos = list->next;
	if(!pos)
	{
		printf("\n\n\t\t\t\t\t数据为空！\n");
		system("pause");
		return;
	}
	while(pos!=NULL && *pos->name!=*name)
		pos=pos->next;
	if(pos==NULL)
	{
		printf("\n\n\t\t\t\t\t数据未找到！\n");
		system("pause");
		return; 
	}
	printf("\t\t\t\t%s\t%s\t\t%s\t\t%s\n","Number","Name","Dynasty","Address");
	printf("%d\t", pos->num);
    printf("%s\t\t", pos->name);
    printf("%s\t\t", pos->dynasty);
    printf("%s\n\n", pos->address);
	system("pause");
}

void ChangeEmperorByNum(struct EmperorInformation* list,int num)
{
	struct EmperorInformation* pos=list->next;
	if(!pos)
	{
		printf("\n\n\t\t\t\t\t数据为空！\n");
		return;
	}
	while(pos!=NULL && pos->num!=num)
		pos=pos->next;
	if(pos==NULL)
	{
		printf("\n\n\t\t\t\t\t数据未找到！\n");
		return;
	}
	printf("\n\n\t\t\t\t\t请输入修改后的编号：");
	while(scanf("%d",pos->num)!=1)
	{
		printf("\n\n\t\t\t\t\t输入错误，请重新输入：");
		safe_flush(stdin);	
	} 
	printf("\n\n\t\t\t\t\t请输入修改后的皇帝姓名：");
	while(scanf("%s",pos->name)!=1)
	{
		printf("\n\n\t\t\t\t\t输入错误，请重新输入：");
		safe_flush(stdin);	
	} 
	printf("\n\n\t\t\t\t\t请输入修改后的朝代：");
	while(scanf("%s",pos->dynasty)!=1)
	{
		printf("\n\n\t\t\t\t\t输入错误，请重新输入：");
		safe_flush(stdin); 
	}
	printf("\n\n\t\t\t\t\t请输入修改后的地址：");
	while(scanf("%s",pos->address)!=1)
	{
		printf("\n\n\t\t\t\t\t输入错误，请重新输入：");
		safe_flush(stdin); 
	}
}


void ChangeEmperorByName(struct EmperorInformation* list,char name[100])
{
	struct EmperorInformation* pos=list->next;
	if(!pos)
	{
		printf("\n\n\t\t\t\t\t数据为空！\n");
		return;
	}
	while(pos!=NULL && *pos->name!=*name)
		pos=pos->next;
	if(pos==NULL)
	{
		printf("\n\n\t\t\t\t\t数据未找到！\n");
		return;
	}
	printf("\n\n\t\t\t\t\t请输入修改后的编号：");
	while(scanf("%d",pos->num)!=1)
	{
		printf("\n\n\t\t\t\t\t输入错误，请重新输入：");
		safe_flush(stdin);	
	} 
	printf("\n\n\t\t\t\t\t请输入修改后的皇帝姓名：");
	while(scanf("%s",pos->name)!=1)
	{
		printf("\n\n\t\t\t\t\t输入错误，请重新输入：");
		safe_flush(stdin);	
	} 
	printf("\n\n\t\t\t\t\t请输入修改后的朝代：");
	while(scanf("%s",pos->dynasty)!=1)
	{
		printf("\n\n\t\t\t\t\t输入错误，请重新输入：");
		safe_flush(stdin); 
	}
	printf("\n\n\t\t\t\t\t请输入修改后的地址：");
	while(scanf("%s",pos->address)!=1)
	{
		printf("\n\n\t\t\t\t\t输入错误，请重新输入：");
		safe_flush(stdin); 
	}
}

void sorted(struct EmperorInformation* list)
{
	int numQ;
	char nameQ[100];
	char dynastyQ[50];
	char addressQ[50];
	struct EmperorInformation* posF=list;
	struct EmperorInformation* pos=list->next;
	if(!posF->next)
	{
		printf("\n\n\t\t\t\t\t数据为空！\n");
		return;
	}
	while(pos->next)
	{
		posF=posF->next;
		pos=pos->next;
		if(posF->num > pos->num)
		{
			numQ=posF->num;
			strcpy(nameQ,posF->name);
			strcpy(dynastyQ,posF->dynasty);
			strcpy(addressQ,posF->address);	
			
			posF->num = pos->num;		
			strcpy(nameQ,posF->name);
			strcpy(dynastyQ,posF->dynasty);
			strcpy(addressQ,posF->address);	
			
			posF->num = numQ;
			strcpy(nameQ,posF->name);
			strcpy(dynastyQ,posF->dynasty);
			strcpy(addressQ,posF->address);	
			
			sorted(list);
		}
	}
}

void sorted_reverse(struct EmperorInformation* list)
{
	int numQ;
	char nameQ[100];
	char dynastyQ[50];
	char addressQ[50];
	struct EmperorInformation* posF=list;
	struct EmperorInformation* pos=list->next;
	if(!posF->next)
	{
		printf("\n\n\t\t\t\t\t数据为空！\n");
		return;
	}
	while(pos->next)
	{
		posF=posF->next;
		pos=pos->next;
		if(posF->num < pos->num)
		{
			numQ = posF->num;
			strcpy(nameQ,posF->name);
			strcpy(dynastyQ,posF->dynasty);
			strcpy(addressQ,posF->address);	
			
			posF->num = pos->num;
			strcpy(nameQ,posF->name);
			strcpy(dynastyQ,posF->dynasty);
			strcpy(addressQ,posF->address);	
			
			pos->num = numQ;
			strcpy(nameQ,posF->name);
			strcpy(dynastyQ,posF->dynasty);
			strcpy(addressQ,posF->address);	
			
			sorted_reverse(list);
		}
	}
}

void load(struct EmperorInformation* list)
{
	FILE* fp;
	if((fp=fopen("Emperor.txt","w+"))==NULL)
	{
		printf("\n\n\t\t\t\t\t文件打开失败！\n");
		system("pause");
		return;
	}
	struct EmperorInformation* pos=CreateList();
	while((fscanf(fp,"%d\t%s\t\t%s\t\t%s\n",&pos->num,&pos->name,&pos->dynasty,&pos->address))==4)
	{
		list->next=pos;
		list=list->next;
		pos=CreateList();
	}
	printf("\n\n\t\t\t\t\t正在读取信息，loading...\n");
	Sleep(2000);
	printf("\n\n\t\t\t\t\t读取信息成功！\n");
	system("pause");
	return;
}

void save(struct EmperorInformation* list)
{
	FILE* fp;
	printf("\n\n\t\t\t\t\t是否清空文件？(Y/N)\n");
	printf("\n\n\t\t\t\t\t如果输入其他内容，系统将自动返回上一步：");
	char i;
	safe_flush(stdin); 
	while(scanf("%c",&i)!=1)
	{
		printf("\n\n\t\t\t\t\t输入错误，请重新输入：");
		safe_flush(stdin);
	}
	switch(i){
	case'y':
		if((fp=fopen("Emperor.txt","w"))==NULL)
		{
			printf("\n\n\t\t\t\t\t打开文件失败！\n");
			system("pause");
			return;
		}
		break;
	case'n':
		if((fp=fopen("Emperor.txt","a"))==NULL)
		{
			printf("\n\n\t\t\t\t\t打开文件失败！\n");
			system("pause");
			return;
		}
		break;
	default:
		return;
		break;
	}
	struct EmperorInformation* pos=list->next;
	while(pos)
	{
		fprintf(fp,"%d\t%s\t\t%s\t\t%s\n",pos->num,pos->name,pos->dynasty,pos->address);
		pos=pos->next;
	}
	fclose(fp);
	printf("\n\n\t\t\t\t\t正在保存信息，loading...\n");
	Sleep(2000);
	printf("\n\n\t\t\t\t\t信息保存成功！\n");
	return;
}

void statistcs_dynasty(struct EmperorInformation* list)
{
	int cc_emperors = 0;
	int cc_qin = 0;
	int cc_han = 0;
	int cc_tang = 0;
	int cc_song = 0;
	int cc_qing = 0;
	struct EmperorInformation* pos = list->next;
	while(pos)
	{
		cc_emperors++;
		if(strcmp(pos->dynasty,"qin")==0)
		{
			cc_qin++;
		}
		if(strcmp(pos->dynasty,"han")==0)
		{
			cc_han++;
		}
		if(strcmp(pos->dynasty,"tang")==0)
		{
			cc_tang++;
		}
		if(strcmp(pos->dynasty,"song")==0)
		{
			cc_song++;
		}
		if(strcmp(pos->dynasty,"qing")==0)
		{
			cc_qing++;
		}
		pos=pos->next;
	}
	system("cls");
    printf("\t\t\t\t\t-------------------------------------\n");
	printf("\t\t\t\t\t          帝王陵信息管理系统\n");
	printf("\t\t\t\t\t-------------------------------------\n");
	printf("\t\t\t\t\t正在统计,loading...\n");
	Sleep(2000);
	printf("\t\t\t\t\t统计完成，正在生成报告...\n");
	Sleep(2000);
	printf("\t\t\t\t\t-------------------------------------\n");
	printf("\t\t\t\t\t            统计报告\n");
	printf("\t\t\t\t\t-------------------------------------\n");
	printf("\t\t\t\t\t共有帝王陵:%d座\n",cc_emperors);
	printf("\n\n\t\t\t\t\t秦:%d座\n",cc_qin);
	printf("\n\n\t\t\t\t\t汉:%d座\n",cc_han);
	printf("\n\n\t\t\t\t\t唐:%d座\n",cc_tang);
	printf("\n\n\t\t\t\t\t宋:%d座\n",cc_song);
	printf("\n\n\t\t\t\t\t清:%d座\n",cc_qing); 
	printf("\t\t\t\t\t\t\t-------------------------------------\n");
	system("pause");
	return;
}

void Menu(struct EmperorInformation* list)
{
	system("cls");
	int i;
	i=getMenuNum();
	switch(i)
	{
		case 1:
			system("cls");
			printf("\t\t\t\t\t-------------------------------------\n");
			printf("\t\t\t\t\t        帝王陵信息管理系统\n");
			printf("\t\t\t\t\t-------------------------------------\n");
			printf("\t\t\t\t\t1.在开头处录入信息\n");
			printf("\t\t\t\t\t2.在结尾处录入信息\n");
			printf("\t\t\t\t\t3.在指定位置之前录入信息\n");
			printf("\t\t\t\t\t4.返回上一步\n");
			printf("\t\t\t\t\t-------------------------------------\n");
			printf("\t\t\t\t\t请输入对应选项：");
			int j;
			while(scanf("%d",&j)!=1 || j<1 || j>4)
			{
				safe_flush(stdin);
				printf("\n\n\t\t\t\t\t输入错误，请重新输入："); 
			}
			switch(j)
			{
				case 1:
					system("cls");
					printf("\t\t\t\t\t-------------------------------------\n");
					printf("\t\t\t\t\t        帝王陵信息管理系统\n");
					printf("\t\t\t\t\t-------------------------------------\n");
					ShowAll(list);
					AddEmperorByHead(list);
					break;
				case 2:
					system("cls");
					printf("\t\t\t\t\t-------------------------------------\n");
					printf("\t\t\t\t\t       帝王陵信息管理系统\n");
					printf("\t\t\t\t\t-------------------------------------\n");
					ShowAll(list);
					AddEmperorByEnd(list);
					break;
				case 3:
					system("cls");
					printf("\t\t\t\t\t-------------------------------------\n");
					printf("\t\t\t\t\t      帝王陵信息管理系统\n");
					printf("\t\t\t\t\t-------------------------------------\n");
					ShowAll(list);
					AddEmperorByPos(list);
					break;
				case 4:
					return;
					break;
			} 
			ShowAll(list);
			system("pause");
			break;	
		case 2:
			system("cls");
			printf("\t\t\t\t\t-------------------------------------\n");
			printf("\t\t\t\t\t       帝王陵信息管理系统\n");
			printf("\t\t\t\t\t-------------------------------------\n");
			printf("\t\t\t\t\t1.根据编号删除\n");
			printf("\t\t\t\t\t2.根据姓名删除\n");
			printf("\t\t\t\t\t3.返回上一步\n");
			printf("\t\t\t\t\t------------------------------------\n");
			printf("\t\t\t\t\t请输入对应选项：");
			while(scanf("%d",&j)!=1 || j<1 || j>3)
			{
				safe_flush(stdin);
				printf("\n\n\t\t\t\t\t输入错误，请重新输入：");	 
			}
			switch(j)
			{
				case 1:
					system("cls");
					printf("\t\t\t\t\t-------------------------------------\n");
					printf("\t\t\t\t\t        帝王陵信息管理系统\n");
					printf("\t\t\t\t\t-------------------------------------\n");
					ShowAll(list);
					int num;
					printf("\n\n\t\t\t\t\t请输入需要删除的编号：");
					while(scanf("%d",&num)!=1)
					{
						printf("\n\n\t\t\t\t\t输入错误，请重新输入：");
						safe_flush(stdin); 
					}
					DeleteEmperorByNum(list,num);
					ShowAll(list);
					system("cls");
					break;
				case 2:
					system("cls");
					printf("\t\t\t\t\t-------------------------------------\n");
					printf("\t\t\t\t\t       帝王陵信息管理系统\n");
					printf("\t\t\t\t\t-------------------------------------\n");
					ShowAll(list);
					char name[100];
					printf("\n\n\t\t\t\t\t请输入需要删除的姓名：");
					while(scanf("%s",name)!=1)
					{
						printf("\n\n\t\t\t\t\t输入错误，请重新输入：");
						safe_flush(stdin);
					}
					DeleteEmperorByName(list,name);
					ShowAll(list);
					system("cls");
					break;
				case 3:
					return;
				 	break;
			}
			break;
		case 3:
			system("cls");
			printf("\t\t\t\t\t-------------------------------------\n");
			printf("\t\t\t\t\t       帝王陵信息管理系统\n");
			printf("\t\t\t\t\t-------------------------------------\n");
			printf("\t\t\t\t\t1.根据编号查询\n");
			printf("\t\t\t\t\t2.根据姓名查询\n");
			printf("\t\t\t\t\t3.返回上一步\n");
			printf("\t\t\t\t\t-------------------------------------\n");
			printf("\t\t\t\t\t请输入对应选项:：");
			while(scanf("%d",&j)!=1 || j<1 || j>3)
			{
				safe_flush(stdin);
				printf("\n\n\t\t\t\t\t输入错误，请重新输入：");
			}
			switch(j)
			{
				case 1:
					system("cls");
					printf("\t\t\t\t\t-------------------------------------\n");
					printf("\t\t\t\t\t       帝王陵信息管理系统\n");
					printf("\t\t\t\t\t-------------------------------------\n");
					int num;
					printf("\n\n\t\t\t\t\t请输入需要查询的编码：");
					while(scanf("%d",&num)!=1)
					{
						printf("\n\n\t\t\t\t\t输入错误，请重新输入：");
						safe_flush(stdin); 
					}
					FindEmperorByNum(list,num);
					break;
				case 2:
					system("cls");
					printf("\t\t\t\t\t-------------------------------------\n");
					printf("\t\t\t\t\t        帝王陵信息管理系统\n");
					printf("\t\t\t\t\t-------------------------------------\n");
					char name[100];
					printf("\n\n\t\t\t\t\t请输入需要查询的姓名：");
					while(scanf("%s,name")!=1)
					{
						printf("\n\n\t\t\t\t\t输入错误，请重新输入：");
						safe_flush(stdin);
					}
					FindEmperorByName(list,name);
					break;
				case 3:
					return;
					break;
			}
			break;
		case 4:
			system("cls");
			printf("\t\t\t\t\t-------------------------------------\n");
			printf("\t\t\t\t\t        帝王陵信息管理系统\n");
			printf("\t\t\t\t\t-------------------------------------\n");
			printf("\t\t\t\t\t1.根据编号修改数据\n");
			printf("\t\t\t\t\t2.根据姓名修改数据\n");
			printf("\t\t\t\t\t3.返回上一步\n");
			printf("\t\t\t\t\t-------------------------------------\n");
			while(scanf("%d",&j)!=1 || j<1 || j>3)
			{
				safe_flush(stdin);
				printf("\n\n\t\t\t\t\t输入错误，请重新输入：");
			}
			switch(j)
			{
				case 1:
					system("cls");
					printf("\t\t\t\t\t-------------------------------------\n");
					printf("\t\t\t\t\t        帝王陵信息管理系统\n");
					printf("\t\t\t\t\t-------------------------------------\n");
					int num;
					printf("\n\n\t\t\t\t\t请输入需要修改的编号：");
					while(scanf("%d",&num)!=1)
					{
						printf("\n\n\t\t\t\t\t输入错误，请重新输入：");
						safe_flush(stdin);
					}
					ChangeEmperorByNum(list,num);
					ShowAll(list);
					system("pause");
					break;
				case 2:
					system("cls");
					printf("\t\t\t\t\t-------------------------------------\n");
					printf("\t\t\t\t\t        帝王陵信息管理系统\n");
					printf("\t\t\t\t\t-------------------------------------\n");
					char name[100];
					printf("\n\n\t\t\t\t\t请输入需要修改的姓名：");
					while(scanf("%s",name)!=1)
					{
						printf("\n\n\t\t\t\t\t输入错误，请重新输入：");
						safe_flush(stdin); 
					}
					ChangeEmperorByName(list,name);
					ShowAll(list);
					system("cls");
					break;
				case 3:
					return;
					break;
			}
			break;
		case 5:
			system("cls");
			printf("\t\t\t\t\t-------------------------------------\n");
			printf("\t\t\t\t\t        帝王陵信息管理系统\n");
			printf("\t\t\t\t\t-------------------------------------\n");
			printf("\t\t\t\t\t1.按编号升序排序\n");
			printf("\t\t\t\t\t2.按编号降序排序\n");
			printf("\t\t\t\t\t3.返回上一步\n");
			printf("\t\t\t\t\t-------------------------------------\n");
			printf("\n\n\t\t\t\t\t请输入对应选项：");
			while(scanf("%d",&j)!=1 || j<1 || j>3)
			{
				safe_flush(stdin);
				printf("\n\n\t\t\t\t\t输入错误，请重新输入：");
			}
			switch(j)
			{
				case 1:
					system("cls");
					printf("\t\t\t\t\t-------------------------------------\n");
					printf("\t\t\t\t\t        帝王陵信息管理系统\n");
					printf("\t\t\t\t\t-------------------------------------\n");
					sorted(list);
					ShowAll(list);
					system("pause");
					break;
				case 2:
					system("cls");
					printf("\t\t\t\t\t-------------------------------------\n");
					printf("\t\t\t\t\t        帝王陵信息管理系统\n");
					printf("\t\t\t\t\t-------------------------------------\n");
					sorted_reverse(list);
					ShowAll(list);
					system("pause");
					break;
				case 3:
					return;
					break;
			}
			break;
		case 6:
			system("cls");
			printf("\t\t\t\t\t-------------------------------------\n");
			printf("\t\t\t\t\t        帝王陵信息管理系统\n");
			printf("\t\t\t\t\t-------------------------------------\n");
			ShowAll(list);
			system("pause");
			break;
		case 7:
			system("cls");
			printf("\t\t\t\t\t-------------------------------------\n");
			printf("\t\t\t\t\t        帝王陵信息管理系统\n");
			printf("\t\t\t\t\t-------------------------------------\n");
			load(list);
			break;
		case 8:
			system("cls");
			printf("\t\t\t\t\t-------------------------------------\n");
			printf("\t\t\t\t\t        帝王陵信息管理系统\n");
			printf("\t\t\t\t\t-------------------------------------\n");
			save(list);
			break;
		case 9:
			system("cls");
			printf("\t\t\t\t\t-------------------------------------\n");
			printf("\t\t\t\t\t        帝王陵信息管理系统\n");
			printf("\t\t\t\t\t-------------------------------------\n");
			printf("\t\t\t\t\t1.按朝代统计数据\n");
			printf("\t\t\t\t\t2.返回上一步\n");
			printf("\t\t\t\t\t-------------------------------------\n");
			printf("请输入对应选项：");
			while(scanf("%d",&j)!=1 || j<1 || j>2)
			{
				safe_flush(stdin);
				printf("\n\n\t\t\t\t\t输入错误，请重新输入：");
			}
			switch(j)
			{
				case 1:
					statistcs_dynasty(list);
					break;
				case 2:
					return;
					break;
			}
			break;
		case 0:
			printf("\n\n\t\t\t\t\t正在退出，loading...\n");
			Sleep(3000);
			LoginMenu();
			break;
    }
} 
