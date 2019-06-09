#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
#include <stdio.h>
#include <stdlib.h>
//��̬������ʼ��
//void InitContact(Contact *pcon)
//{
//	assert(pcon != NULL);
//	pcon->sz = 0;
//	memset(pcon->data, 0, sizeof(pcon->data));
//}
//��̬������ʼ��
void InitContact(Contact *pcon)
{
	assert(pcon != NULL);
	pcon->sz = 0;
	pcon->data = (Info*)malloc(3 * sizeof(Info));
	if (pcon->data == NULL)
	{
		perror("InitContact::use malloc");
		exit(EXIT_FAILURE);//�˳�����
	}
	pcon->capacity = 3;
	//�����ļ��еı�����Ϣ
	LoadContact(pcon);
}
void DestroyContact(Contact *pcon)
{
	assert(pcon != NULL);
	pcon->sz = 0;
	pcon->capacity = 0;
	free(pcon->data);
	pcon->data = NULL;
}
int Check_Capacity(Contact *pcon)
{
	assert(pcon);
	if (pcon->capacity == pcon->sz)
	{
		//����
		Info *ptr=realloc(pcon->data, (pcon->capacity + 2)*sizeof(Info));
		if (ptr != NULL)
		{
			pcon->data = ptr;
			printf("���ݳɹ�!");
			return 1;
		}
	}
	return 1;
}
void AddContact(Contact *pcon)
{
	assert(pcon != NULL);
	/*if (pcon->sz == MAX)
	{
		printf("ͨѶ¼�������޷����!\n");
	}*/
	if (0 == Check_Capacity(pcon))
	{
		printf("����ʧ��,�޷����");
		return;
	}
	else
	{
		printf("����������:> ");
		scanf("%s", pcon->data[pcon->sz].name);
		printf("����������:> ");
		scanf("%d", &(pcon->data[pcon->sz].age));
		printf("�������Ա�:> ");
		scanf("%s", pcon->data[pcon->sz].sex);
		printf("������绰:> ");
		scanf("%s", pcon->data[pcon->sz].tele);
		printf("�������ַ;> ");
		scanf("%s", pcon->data[pcon->sz].addr);
		pcon->sz++;
	}
}
void ShowContact(const Contact* pcon)
{
	int i = 0;
	//����  ����  �Ա�  �绰  ��ַ
	//����  20    ��    123   ����
	printf("%10s\t%4s\t%4s\t%12s\t%15s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (i = 0; i < pcon->sz; i++)
	{
		printf("%10s\t%4d\t%4s\t%12s\t%15s\n",
			pcon->data[i].name,
			pcon->data[i].age,
			pcon->data[i].sex,
			pcon->data[i].tele,
			pcon->data[i].addr);
		//��ӡһ���˵���Ϣ
	}
}
static int Find(Contact *pcon, char name[])
{
	int i = 0;
	for (i = 0; i < pcon->sz; ++i)
	{
		if (0 == strcmp(pcon->data[i].name, name))
		{
			return i;
		}
	}
	return -1;
}
void DelContact(Contact *pcon)
{
	int i = 0;
	int j = 0;
	int ret = 0;
	char name[MAX_Name] = { 0 };
	printf("������Ҫɾ�����˵�����:> ");
	scanf("%s", &name);
	if (pcon->sz == 0)
	{
		printf("ͨѶ¼�ѿգ��޷�ɾ��!\n");
		return;
	}
	ret = Find(pcon, name);
	if (ret==-1)
	{
		printf("Ҫɾ�����˲�����!\n");
		return;
	}
	if (ret != -1 && ret <= pcon->sz)
	{
		//ɾ��
		for (j = ret; j < pcon->sz - 1; ++j)
		{
			pcon->data[j] = pcon->data[j + 1];
		}
	}
	pcon->sz--;
	printf("ɾ���ɹ�!\n");
}
void SearchContact(const Contact *pcon)
{
	int pos = 0;
	char name[MAX_Name] = { 0 };
	assert(pcon != NULL);
	printf("������Ҫ���ҵ��˵�����:> ");
	scanf("%s", &name);
	pos = Find(pcon, name);
	if (pos == -1)
	{
		printf("Ҫ���ҵ��˵���Ϣ������!\n");
	}
	else if (pos != -1)
	{
		printf("%10s\t%4s\t%4s\t%12s\t%15s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		printf("%10s\t%4d\t%4s\t%12s\t%15s\n",
			pcon->data[pos].name,
			pcon->data[pos].age,
			pcon->data[pos].sex,
			pcon->data[pos].tele,
			pcon->data[pos].addr);//��ӡһ���˵���Ϣ
	}
	else
		printf("Ҫ���ҵ��˲�����!\n");
}
void ModifyContact(Contact *pcon)
{
	char name[MAX_Name] = { 0 };
	int pos = 0;
	assert(pcon != NULL);
	printf("������Ҫ�޸ĵ��˵�����:> ");
	scanf("%s", &name);
	pos = Find(pcon, name);
	if (pos == -1)
		printf("Ҫ�޸ĵ��˵���Ϣ������!\n");
	else
	{
		printf("����������:");
		scanf("%s", pcon->data[pos].name);
		printf("����������:");
		scanf("%d", &(pcon->data[pos].age));
		printf("�������Ա�:");
		scanf("%s", pcon->data[pos].sex);
		printf("������绰:");
		scanf("%s", pcon->data[pos].tele);
		printf("�������ַ:");
		scanf("%s", pcon->data[pos].addr);
	}
}
void SortContact(Contact *pcon)//ð������
{
	int i = 0;
	int j = 0;
	assert(pcon != NULL);
	for (i = 0; i < pcon->sz; ++i)
	{
		int flag = 1;//��ʾ�Ѿ��ź�
		for (j = 0; j < pcon->sz - 1; ++j)
		{
			if (strcmp(pcon->data[j].name, pcon->data[j + 1].name)>0)
			{
				Info tmp = pcon->data[j];
				pcon->data[j] = pcon->data[j + 1];
				pcon->data[j + 1] = tmp;
			}
		}
		if (flag == 1)
		{
			printf("�Ѿ��ź���!\n");
			break;
		}
	}
}
void EmptyContact(Contact *pcon)
{
	pcon->sz = 0;
	printf("��ճɹ�!!\n");
}
void SaveContact(Contact *pcon)
{
	FILE *pf = fopen("contact.data", "wb");
	int i = 0;
	if (pf == NULL)
	{
		perror("fopen");
		return;
	}
	//д����
	for (i = 0; i < pcon->sz; i++)
	{
		fwrite(&(pcon->data[i]), sizeof(Info), 1, pf);
	}
	fclose(pf);
	pf = NULL;
}
void LoadContact(Contact *pcon)
{
	FILE* pf = fopen("contact.data", "rb");
	Info tmp = { 0 };
	if (pf == NULL)
	{
		perror("LoadContact::fopen");
		return;
	}
	//���ļ�
	while (fread(&tmp, sizeof(Info),1,pf)>=1)
	{
		//����ȡ����Ԫ�ط���ͨѶ¼��
		Check_Capacity(pcon);
		pcon->data[pcon->sz] = tmp;
		pcon->sz++;
	}
	fclose(pf);
	pf = NULL;
}