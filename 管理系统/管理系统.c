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

void safe_flush(FILE* fp);                                                  //������ջ����� 
struct EmperorInformation*CreateList(void);                                 //���ڴ���һ����� 
void mainMenu(void);                                               			//�������˵� 
int getMenuNum(void);                                              			//��ȡ�˵�ѡ���� 
void CreateUsersFile(void);                                        			//�����洢�û��˺�������ļ� 
void Register(void);                                               			//�����û�ע�� 
void Login(void);                                              				//�����û���¼ 
void LoginMenu(void);                                          				//���ڴ�����½���� 
struct EmperorInformation* CreateEmperor(void);                				//���ڴ����µĵ������� 
void AddEmperorByHead(struct EmperorInformation* list );       				//����������ͷ����ӵ�������Ϣ 
void AddEmperorByEnd(struct EmperorInformation* list);         				//�����������β����ӵ�������Ϣ 
void AddEmperorByPos(struct EmperorInformation* list);         				//����������ָ��λ�ô���ӵ�������Ϣ
void ShowAll(struct EmperorInformation* list);          				    //������ʾ���е�������Ϣ 
void DeleteEmperorByNum(struct EmperorInformation* list, int num);          //���ڸ��ݱ��ɾ����������Ϣ 
void DeleteEmperorByName(struct EmperorInformation* list, char name[100]);  //���ڸ��ݻʵ�����ɾ����������Ϣ 
void FindEmperorByNum(struct EmperorInformation* list,int num);             //���ڸ��ݱ�Ų�ѯ��������Ϣ 
void FindEmperorByName(struct EmperorInformation* list, char name[100]);    //���ڸ��ݻʵ�������ѯ�Ƶ�����Ϣ 
void ChangeEmperorByNum(struct EmperorInformation* list,int num);           //���ڸ��ݱ���޸ĵ�������Ϣ 
void ChangeEmperorByName(struct EmperorInformation* list, char name[100]);  //���ڸ��ݻʵ������޸ĵ�������Ϣ 
void sorted(struct EmperorInformation* list);                               //���ڰ��ճ���˳���������� 
void sorted_reverse(struct EmperorInformation* list);                       //���ڰ��ճ���˳�������� 
void load(struct EmperorInformation* list);                                 //���ڶ�ȡ�ļ� 
void save(struct EmperorInformation* list);                                 //���ڱ����ļ� 
void statistcs_dynasty(struct EmperorInformation* list);                    //���ڸ��ݳ���ͳ������ 
void Menu(struct EmperorInformation* list);                                 //���ڴ����˵�

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
		printf("\n\n\t\t\t-�����ڴ�ʧ��\n");
		return NULL;
	}
	list->next = NULL;
	return list;
}

void mainMenu(void)
{
	printf("\t\t\t\t\t-------------------------------------\n");
	printf("\t\t\t\t\t          ��������Ϣ����ϵͳ         \n");
	printf("\t\t\t\t\t-------------------------------------\n");
	printf("\t\t\t\t\t1.��ӵ�������Ϣ\n");
	printf("\t\t\t\t\t2.ɾ����������Ϣ\n");
	printf("\t\t\t\t\t3.���ҵ�������Ϣ\n");
	printf("\t\t\t\t\t4.�޸ĵ�������Ϣ\n");
	printf("\t\t\t\t\t5.����Ĺ�������\n");
	printf("\t\t\t\t\t6.��ʾ���е�������Ϣ\n");
	printf("\t\t\t\t\t7.��ȡ�ļ������е�������Ϣ\n");
	printf("\t\t\t\t\t8.����������Ϣ���浽�ļ�\n");
	printf("\t\t\t\t\t9.ͳ������\n");
	printf("\t\t\t\t\t0.�˳���¼\n");
	printf("\t\t\t\t\t------------------------------------\n");
	printf("\t\t\t\t\t��������: "); 	
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
		printf("\n\n\t\t\t\t\t����������������룺"); 
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
			printf("\n\n\t\t\t\t\t�޷������û��ļ��������˳�ϵͳ\n");
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
	printf("\t\t\t\t\t          ��������Ϣ����ϵͳ\n");
	printf("\t\t\t\t\t-------------------------------------\n");
	fread(&b,sizeof(struct User),1, fp);
	printf("\n\n\t\t\t\t\t�������û�����");
	while (scanf("%s", a.username) != 1)
	{
		printf("\n\n\t\t\t\t\t����������������룺");
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
			printf("\n\n\t\t\t\t\t���û����ѱ�ע�ᣬ�������ص�¼����\n");
			fclose(fp);
			Sleep(3000);
			LoginMenu();
			return;
		}
	}
	
	printf("\n\n\t\t\t\t\t����������: ");
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
	printf("\n\n\t\t\t\t\t��ȷ�����룺");
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
			printf("\n\n\t\t\t\t\tע��ɹ����������ص�½����...\n");
			fclose(fp);
			Sleep(3000);
			LoginMenu();
			return;
		}
		else
		{
			printf("\n\n\t\t\t\t\t�������벻һ�£����������룡\n");
			printf("\n\n\t\t\t\t\t���������룺");
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
			printf("\n\n\t\t\t\t\t��ȷ�����룺");
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
	printf("\t\t\t\t\t          ��������Ϣ����ϵͳ         \n");
	printf("\t\t\t\t\t-------------------------------------\n");	
	fp = fopen("Users.txt","r");
	fread(&b,sizeof(struct User),1,fp);
	printf("\n\n\t\t\t\t\t�������û���: ");
	while(scanf("%s",a.username)!=1)
	{
		printf("\n\n\t\t\t\t\t����������������룺");
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
				printf("\n\n\t\t\t\t\t�û������ڣ�\n");
				fclose(fp);
				system("pause");
				LoginMenu();
				return; 
			}
		}
	}
	printf("\n\n\t\t\t\t\t����������: ");
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
			printf("\n\n\t\t\t\t\t��½�ɹ������ڽ���...\n");
			Sleep(2000);
			struct EmperorInformation* list=CreateList();
			while(1)
				Menu(list);
			return; 
		}
		else
		{
			printf("\n\n\t\t\t\t\t������󣬼������ص�½����...\n");
			Sleep(2000);
			LoginMenu();
		}
	}while(strcmp(a.password,b.password)==0);
} 

void LoginMenu(void)
{
	system("cls");
	printf("\t\t\t\t\t-------------------------------------\n");
	printf("\t\t\t\t\t          ��������Ϣ����ϵͳ         \n");
	printf("\t\t\t\t\t-------------------------------------\n");
	printf("\t\t\t\t\t1.��¼ϵͳ\n");
	printf("\t\t\t\t\t2.���û�ע��\n");
	printf("\t\t\t\t\t3.���ڱ�ϵͳ\n");
	printf("\t\t\t\t\t4.�˳�\n");	
	printf("\t\t\t\t\t-------------------------------------\n");	
	printf("\t\t\t\t\t�������Ӧѡ��: ");
	int i;
	while(scanf("%d",&i)!=1||i<0||i>4)
	{
		safe_flush(stdin);
		printf("\t\t\t\t\t����������������룺"); 
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
			printf("\t\t\t\t\t\t\t          ��������Ϣ����ϵͳ         \n");
			printf("\t\t\t\t\t\t\t-------------------------------------\n");
			printf("\t\t\t\t\t\t\t���ߣ����꺭   �����ʵ��ѧ�����ѧԺ\n"); 
			printf("\t\t\t\t\t\t\t    ������2001\n");
			printf("\t\t\t\t\t\t\t-------------------------------------\n");
			system("pause");
			LoginMenu();
			break;
		case 4:
			printf("\n\n\t\t\t\t\t�����˳���loading...\n");
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
		printf("\n\n\t\t\t\t\t�����ڴ�ʧ��\n");
		return NULL; 
	}
	node->next=NULL;
	printf("\n\n\t\t\t\t\t������������ţ�");
	while(scanf("%d", &node->num)!=1)
	{
		printf("\n\n\t\t\t\t\t����������������룺");
		safe_flush(stdin);
	}
	node->next=NULL;
	printf("\n\n\t\t\t\t\t��������������ƣ�");
	while(scanf("%s", &node->name)!=1)
	{
		printf("\n\n\t\t\t\t\t����������������룺");
		safe_flush(stdin);
	}
	printf("\n\n\t\t\t\t\t��������Ĺ������");
	while(scanf("%s",node->dynasty)!=1)
	{
		printf("\n\n\t\t\t\t\t����������������룺");
		safe_flush(stdin);
	}
	printf("\n\n\t\t\t\t\t��������Ĺ���ڵ�ַ��");
	while(scanf("%s",node->address)!=1)
	{
		printf("\n\n\t\t\t\t\t����������������룺");
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
			printf("\n\n\t\t\t\t\t����ظ���¼����Ϣʧ��!\n");
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
			printf("\n\n\t\t\t\t\t����ظ���¼����Ϣʧ�ܣ�\n");
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
		printf("\n\n\t\t\t\t\t����Ϊ�գ����������Ϣ��\n");
		return;
	}
	struct EmperorInformation* newEmperor=CreateEmperor();
	while(pos->next!=NULL)
	{
		if(pos->next->num == newEmperor->num)
		{
			printf("\n\n\t\t\t\t\t����ظ���¼����Ϣʧ�ܣ�\n");
			return;
		}
		pos=pos->next;
	}
	int num;
	ShowAll(list);
	printf("\n\n\t\t\t\t\t�������ţ�����Ϣ��������ָ��λ��֮ǰ��");
	while(scanf("%s",&num)!=1)
	{
		printf("\n\n\t\t\t\t\t����������������룺");
		safe_flush(stdin);
	}
	struct EmperorInformation* pos1=list->next;
	while(pos1->num!=num)
	{
		pos1=pos1->next;
		posF=posF->next;
		if(pos1==NULL)
		{
			printf("\n\n\t\t\t\t\tδ�ҵ�ָ����ţ�\n");
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
        printf("\n\n\t\t\t\t\t����Ϊ�գ�\n");
        return;
    }
    while (pos != NULL && pos->num != num) {
        pos = pos->next;
        posF = posF->next;
    }
    if (pos == NULL) {
        printf("\n\n\t\t\t\t\t����δ�ҵ���\n");
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
		printf("\n\n\t\t\t\t\t����Ϊ�գ�\n");
		return;
	}
	while(pos!=NULL && *pos->name != *name)
	{
		pos=pos->next;
		posF=posF->next;
	}
	if(pos==NULL)
	{
		printf("\n\n\t\t\t\t\t����δ�ҵ���\n");
		return;
	}
	posF->next = pos->next;
	free(pos);
	return;
}

void FindEmperorByNum(struct EmperorInformation* list, int num) 
{                    
    printf("\n\n\t\t\t\t\t���ڲ��ң�loading...\n");
    Sleep(2000);
    struct EmperorInformation* pos = list->next;
    if (!pos) {
        printf("\n\n\t\t\t\t\t����Ϊ�գ�\n");
        system("pause");
        return;
    }
    while (pos != NULL && pos->num != num)
        pos = pos->next;
    if (pos == NULL) {
        printf("\n\n\t\t\t\t\t����δ�ҵ���\n");
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
	printf("\n\n\t\t\t\t\t���ڲ��ң�loading...\n");
	Sleep(2000);
	struct EmperorInformation* pos = list->next;
	if(!pos)
	{
		printf("\n\n\t\t\t\t\t����Ϊ�գ�\n");
		system("pause");
		return;
	}
	while(pos!=NULL && *pos->name!=*name)
		pos=pos->next;
	if(pos==NULL)
	{
		printf("\n\n\t\t\t\t\t����δ�ҵ���\n");
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
		printf("\n\n\t\t\t\t\t����Ϊ�գ�\n");
		return;
	}
	while(pos!=NULL && pos->num!=num)
		pos=pos->next;
	if(pos==NULL)
	{
		printf("\n\n\t\t\t\t\t����δ�ҵ���\n");
		return;
	}
	printf("\n\n\t\t\t\t\t�������޸ĺ�ı�ţ�");
	while(scanf("%d",pos->num)!=1)
	{
		printf("\n\n\t\t\t\t\t����������������룺");
		safe_flush(stdin);	
	} 
	printf("\n\n\t\t\t\t\t�������޸ĺ�Ļʵ�������");
	while(scanf("%s",pos->name)!=1)
	{
		printf("\n\n\t\t\t\t\t����������������룺");
		safe_flush(stdin);	
	} 
	printf("\n\n\t\t\t\t\t�������޸ĺ�ĳ�����");
	while(scanf("%s",pos->dynasty)!=1)
	{
		printf("\n\n\t\t\t\t\t����������������룺");
		safe_flush(stdin); 
	}
	printf("\n\n\t\t\t\t\t�������޸ĺ�ĵ�ַ��");
	while(scanf("%s",pos->address)!=1)
	{
		printf("\n\n\t\t\t\t\t����������������룺");
		safe_flush(stdin); 
	}
}


void ChangeEmperorByName(struct EmperorInformation* list,char name[100])
{
	struct EmperorInformation* pos=list->next;
	if(!pos)
	{
		printf("\n\n\t\t\t\t\t����Ϊ�գ�\n");
		return;
	}
	while(pos!=NULL && *pos->name!=*name)
		pos=pos->next;
	if(pos==NULL)
	{
		printf("\n\n\t\t\t\t\t����δ�ҵ���\n");
		return;
	}
	printf("\n\n\t\t\t\t\t�������޸ĺ�ı�ţ�");
	while(scanf("%d",pos->num)!=1)
	{
		printf("\n\n\t\t\t\t\t����������������룺");
		safe_flush(stdin);	
	} 
	printf("\n\n\t\t\t\t\t�������޸ĺ�Ļʵ�������");
	while(scanf("%s",pos->name)!=1)
	{
		printf("\n\n\t\t\t\t\t����������������룺");
		safe_flush(stdin);	
	} 
	printf("\n\n\t\t\t\t\t�������޸ĺ�ĳ�����");
	while(scanf("%s",pos->dynasty)!=1)
	{
		printf("\n\n\t\t\t\t\t����������������룺");
		safe_flush(stdin); 
	}
	printf("\n\n\t\t\t\t\t�������޸ĺ�ĵ�ַ��");
	while(scanf("%s",pos->address)!=1)
	{
		printf("\n\n\t\t\t\t\t����������������룺");
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
		printf("\n\n\t\t\t\t\t����Ϊ�գ�\n");
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
		printf("\n\n\t\t\t\t\t����Ϊ�գ�\n");
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
		printf("\n\n\t\t\t\t\t�ļ���ʧ�ܣ�\n");
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
	printf("\n\n\t\t\t\t\t���ڶ�ȡ��Ϣ��loading...\n");
	Sleep(2000);
	printf("\n\n\t\t\t\t\t��ȡ��Ϣ�ɹ���\n");
	system("pause");
	return;
}

void save(struct EmperorInformation* list)
{
	FILE* fp;
	printf("\n\n\t\t\t\t\t�Ƿ�����ļ���(Y/N)\n");
	printf("\n\n\t\t\t\t\t��������������ݣ�ϵͳ���Զ�������һ����");
	char i;
	safe_flush(stdin); 
	while(scanf("%c",&i)!=1)
	{
		printf("\n\n\t\t\t\t\t����������������룺");
		safe_flush(stdin);
	}
	switch(i){
	case'y':
		if((fp=fopen("Emperor.txt","w"))==NULL)
		{
			printf("\n\n\t\t\t\t\t���ļ�ʧ�ܣ�\n");
			system("pause");
			return;
		}
		break;
	case'n':
		if((fp=fopen("Emperor.txt","a"))==NULL)
		{
			printf("\n\n\t\t\t\t\t���ļ�ʧ�ܣ�\n");
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
	printf("\n\n\t\t\t\t\t���ڱ�����Ϣ��loading...\n");
	Sleep(2000);
	printf("\n\n\t\t\t\t\t��Ϣ����ɹ���\n");
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
	printf("\t\t\t\t\t          ��������Ϣ����ϵͳ\n");
	printf("\t\t\t\t\t-------------------------------------\n");
	printf("\t\t\t\t\t����ͳ��,loading...\n");
	Sleep(2000);
	printf("\t\t\t\t\tͳ����ɣ��������ɱ���...\n");
	Sleep(2000);
	printf("\t\t\t\t\t-------------------------------------\n");
	printf("\t\t\t\t\t            ͳ�Ʊ���\n");
	printf("\t\t\t\t\t-------------------------------------\n");
	printf("\t\t\t\t\t���е�����:%d��\n",cc_emperors);
	printf("\n\n\t\t\t\t\t��:%d��\n",cc_qin);
	printf("\n\n\t\t\t\t\t��:%d��\n",cc_han);
	printf("\n\n\t\t\t\t\t��:%d��\n",cc_tang);
	printf("\n\n\t\t\t\t\t��:%d��\n",cc_song);
	printf("\n\n\t\t\t\t\t��:%d��\n",cc_qing); 
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
			printf("\t\t\t\t\t        ��������Ϣ����ϵͳ\n");
			printf("\t\t\t\t\t-------------------------------------\n");
			printf("\t\t\t\t\t1.�ڿ�ͷ��¼����Ϣ\n");
			printf("\t\t\t\t\t2.�ڽ�β��¼����Ϣ\n");
			printf("\t\t\t\t\t3.��ָ��λ��֮ǰ¼����Ϣ\n");
			printf("\t\t\t\t\t4.������һ��\n");
			printf("\t\t\t\t\t-------------------------------------\n");
			printf("\t\t\t\t\t�������Ӧѡ�");
			int j;
			while(scanf("%d",&j)!=1 || j<1 || j>4)
			{
				safe_flush(stdin);
				printf("\n\n\t\t\t\t\t����������������룺"); 
			}
			switch(j)
			{
				case 1:
					system("cls");
					printf("\t\t\t\t\t-------------------------------------\n");
					printf("\t\t\t\t\t        ��������Ϣ����ϵͳ\n");
					printf("\t\t\t\t\t-------------------------------------\n");
					ShowAll(list);
					AddEmperorByHead(list);
					break;
				case 2:
					system("cls");
					printf("\t\t\t\t\t-------------------------------------\n");
					printf("\t\t\t\t\t       ��������Ϣ����ϵͳ\n");
					printf("\t\t\t\t\t-------------------------------------\n");
					ShowAll(list);
					AddEmperorByEnd(list);
					break;
				case 3:
					system("cls");
					printf("\t\t\t\t\t-------------------------------------\n");
					printf("\t\t\t\t\t      ��������Ϣ����ϵͳ\n");
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
			printf("\t\t\t\t\t       ��������Ϣ����ϵͳ\n");
			printf("\t\t\t\t\t-------------------------------------\n");
			printf("\t\t\t\t\t1.���ݱ��ɾ��\n");
			printf("\t\t\t\t\t2.��������ɾ��\n");
			printf("\t\t\t\t\t3.������һ��\n");
			printf("\t\t\t\t\t------------------------------------\n");
			printf("\t\t\t\t\t�������Ӧѡ�");
			while(scanf("%d",&j)!=1 || j<1 || j>3)
			{
				safe_flush(stdin);
				printf("\n\n\t\t\t\t\t����������������룺");	 
			}
			switch(j)
			{
				case 1:
					system("cls");
					printf("\t\t\t\t\t-------------------------------------\n");
					printf("\t\t\t\t\t        ��������Ϣ����ϵͳ\n");
					printf("\t\t\t\t\t-------------------------------------\n");
					ShowAll(list);
					int num;
					printf("\n\n\t\t\t\t\t��������Ҫɾ���ı�ţ�");
					while(scanf("%d",&num)!=1)
					{
						printf("\n\n\t\t\t\t\t����������������룺");
						safe_flush(stdin); 
					}
					DeleteEmperorByNum(list,num);
					ShowAll(list);
					system("cls");
					break;
				case 2:
					system("cls");
					printf("\t\t\t\t\t-------------------------------------\n");
					printf("\t\t\t\t\t       ��������Ϣ����ϵͳ\n");
					printf("\t\t\t\t\t-------------------------------------\n");
					ShowAll(list);
					char name[100];
					printf("\n\n\t\t\t\t\t��������Ҫɾ����������");
					while(scanf("%s",name)!=1)
					{
						printf("\n\n\t\t\t\t\t����������������룺");
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
			printf("\t\t\t\t\t       ��������Ϣ����ϵͳ\n");
			printf("\t\t\t\t\t-------------------------------------\n");
			printf("\t\t\t\t\t1.���ݱ�Ų�ѯ\n");
			printf("\t\t\t\t\t2.����������ѯ\n");
			printf("\t\t\t\t\t3.������һ��\n");
			printf("\t\t\t\t\t-------------------------------------\n");
			printf("\t\t\t\t\t�������Ӧѡ��:��");
			while(scanf("%d",&j)!=1 || j<1 || j>3)
			{
				safe_flush(stdin);
				printf("\n\n\t\t\t\t\t����������������룺");
			}
			switch(j)
			{
				case 1:
					system("cls");
					printf("\t\t\t\t\t-------------------------------------\n");
					printf("\t\t\t\t\t       ��������Ϣ����ϵͳ\n");
					printf("\t\t\t\t\t-------------------------------------\n");
					int num;
					printf("\n\n\t\t\t\t\t��������Ҫ��ѯ�ı��룺");
					while(scanf("%d",&num)!=1)
					{
						printf("\n\n\t\t\t\t\t����������������룺");
						safe_flush(stdin); 
					}
					FindEmperorByNum(list,num);
					break;
				case 2:
					system("cls");
					printf("\t\t\t\t\t-------------------------------------\n");
					printf("\t\t\t\t\t        ��������Ϣ����ϵͳ\n");
					printf("\t\t\t\t\t-------------------------------------\n");
					char name[100];
					printf("\n\n\t\t\t\t\t��������Ҫ��ѯ��������");
					while(scanf("%s,name")!=1)
					{
						printf("\n\n\t\t\t\t\t����������������룺");
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
			printf("\t\t\t\t\t        ��������Ϣ����ϵͳ\n");
			printf("\t\t\t\t\t-------------------------------------\n");
			printf("\t\t\t\t\t1.���ݱ���޸�����\n");
			printf("\t\t\t\t\t2.���������޸�����\n");
			printf("\t\t\t\t\t3.������һ��\n");
			printf("\t\t\t\t\t-------------------------------------\n");
			while(scanf("%d",&j)!=1 || j<1 || j>3)
			{
				safe_flush(stdin);
				printf("\n\n\t\t\t\t\t����������������룺");
			}
			switch(j)
			{
				case 1:
					system("cls");
					printf("\t\t\t\t\t-------------------------------------\n");
					printf("\t\t\t\t\t        ��������Ϣ����ϵͳ\n");
					printf("\t\t\t\t\t-------------------------------------\n");
					int num;
					printf("\n\n\t\t\t\t\t��������Ҫ�޸ĵı�ţ�");
					while(scanf("%d",&num)!=1)
					{
						printf("\n\n\t\t\t\t\t����������������룺");
						safe_flush(stdin);
					}
					ChangeEmperorByNum(list,num);
					ShowAll(list);
					system("pause");
					break;
				case 2:
					system("cls");
					printf("\t\t\t\t\t-------------------------------------\n");
					printf("\t\t\t\t\t        ��������Ϣ����ϵͳ\n");
					printf("\t\t\t\t\t-------------------------------------\n");
					char name[100];
					printf("\n\n\t\t\t\t\t��������Ҫ�޸ĵ�������");
					while(scanf("%s",name)!=1)
					{
						printf("\n\n\t\t\t\t\t����������������룺");
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
			printf("\t\t\t\t\t        ��������Ϣ����ϵͳ\n");
			printf("\t\t\t\t\t-------------------------------------\n");
			printf("\t\t\t\t\t1.�������������\n");
			printf("\t\t\t\t\t2.����Ž�������\n");
			printf("\t\t\t\t\t3.������һ��\n");
			printf("\t\t\t\t\t-------------------------------------\n");
			printf("\n\n\t\t\t\t\t�������Ӧѡ�");
			while(scanf("%d",&j)!=1 || j<1 || j>3)
			{
				safe_flush(stdin);
				printf("\n\n\t\t\t\t\t����������������룺");
			}
			switch(j)
			{
				case 1:
					system("cls");
					printf("\t\t\t\t\t-------------------------------------\n");
					printf("\t\t\t\t\t        ��������Ϣ����ϵͳ\n");
					printf("\t\t\t\t\t-------------------------------------\n");
					sorted(list);
					ShowAll(list);
					system("pause");
					break;
				case 2:
					system("cls");
					printf("\t\t\t\t\t-------------------------------------\n");
					printf("\t\t\t\t\t        ��������Ϣ����ϵͳ\n");
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
			printf("\t\t\t\t\t        ��������Ϣ����ϵͳ\n");
			printf("\t\t\t\t\t-------------------------------------\n");
			ShowAll(list);
			system("pause");
			break;
		case 7:
			system("cls");
			printf("\t\t\t\t\t-------------------------------------\n");
			printf("\t\t\t\t\t        ��������Ϣ����ϵͳ\n");
			printf("\t\t\t\t\t-------------------------------------\n");
			load(list);
			break;
		case 8:
			system("cls");
			printf("\t\t\t\t\t-------------------------------------\n");
			printf("\t\t\t\t\t        ��������Ϣ����ϵͳ\n");
			printf("\t\t\t\t\t-------------------------------------\n");
			save(list);
			break;
		case 9:
			system("cls");
			printf("\t\t\t\t\t-------------------------------------\n");
			printf("\t\t\t\t\t        ��������Ϣ����ϵͳ\n");
			printf("\t\t\t\t\t-------------------------------------\n");
			printf("\t\t\t\t\t1.������ͳ������\n");
			printf("\t\t\t\t\t2.������һ��\n");
			printf("\t\t\t\t\t-------------------------------------\n");
			printf("�������Ӧѡ�");
			while(scanf("%d",&j)!=1 || j<1 || j>2)
			{
				safe_flush(stdin);
				printf("\n\n\t\t\t\t\t����������������룺");
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
			printf("\n\n\t\t\t\t\t�����˳���loading...\n");
			Sleep(3000);
			LoginMenu();
			break;
    }
} 
