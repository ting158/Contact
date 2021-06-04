#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"

void InitContact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->size));
	ps->size = 0;//����ͨѶ¼���ֻ��0��Ԫ��
}

void AddContact(struct Contact* ps)
{
	if (ps->size == MAX)
	{
		printf("ͨѶ¼�������޷�����\n");
	}
	else
	{
		printf("������������");
		scanf("%s", ps->data[ps->size].name);
		printf("���������䣺");
		scanf("%d", &(ps->data[ps->size].age));
		printf("�������Ա�");
		scanf("%s", ps->data[ps->size].sex);
		printf("������绰��");
		scanf("%s", ps->data[ps->size].tele);
		printf("�������ַ��");
		scanf("%s", ps->data[ps->size].addr);

		ps->size++;
		printf("��ӳɹ�\n");
	}
}

void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("����ϵ��\n");
	}
	else
	{
		int i = 0;
		//����
		printf("%-12s\t%-4s\t%-5s\t%-12s\t%-12s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		//����
		for (i = 0;i < ps->size;i++)
		{
			printf("%-12s\t%-4d\t%-5s\t%-12s\t%-12s\n", ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
			 
		}
	}
}

static int FindName(const struct Contact* ps, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0;i < ps->size;i++)
	{
		if (strcmp(ps->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;//�Ҳ���
}

void DelContact(struct Contact* ps)
{
	char name[MAX_NAME] = { 0 };
	printf("������Ҫɾ����ϵ�˵�������");
	scanf("%s", name);
	//1.����Ҫɾ����ϵ�˵�λ��
	int pos = FindName(ps, name);//�ҵ��˷�����������Ԫ�ص��±꣬�Ҳ�������-1
	//2.ɾ��
	if (pos == -1)
	{
		printf("Ҫɾ������ϵ�˲�����\n");
	}
	else
	{
		int j = 0;
		for (j = pos;j < ps->size - 1;j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�\n");
	}
}

void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME] = { 0 };
	printf("��������ϵ��������");
	scanf("%s", name);
	int pos = FindName(ps, name);
	if (pos == -1)
	{
		printf("����ϵ�˲�����\n");
	}
	else
	{
		printf("%-12s\t%-4s\t%-5s\t%-12s\t%-12s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		//����
		printf("%-12s\t%-4d\t%-5s\t%-12s\t%-12s\n", ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr);
	}
}

void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ�޸���ϵ�˵�������");
	scanf("%s", name);
	int pos = FindName(ps, name);
	if (pos == -1)
	{
		printf("����ϵ�˲�����\n");
	}
	else
	{
		printf("������������");
		scanf("%s", ps->data[pos].name);
		printf("���������䣺");
		scanf("%d", &(ps->data[pos].age));
		printf("�������Ա�");
		scanf("%s", ps->data[pos].sex);
		printf("������绰��");
		scanf("%s", ps->data[pos].tele);
		printf("�������ַ��");
		scanf("%s", ps->data[pos].addr);

		printf("�޸����\n");
	}
}

void SortContact(struct Contact* ps)
{
	/*int i, j;
	for (i = 0;i < MAX_NAME - 1;i++)
	{
		struct PeoInfo* tmp = ps;
		for (j = i + 1;j < MAX_NAME;j++)
		{
			int ret = strcmp(ps->data[i].name, ps->data[i].name);
			if (ret > 0)
			{
				*tmp = ps->data[i];
				ps->data[i] = ps->data[j];
				ps->data[j] = *tmp;
			}
		}
	}
	printf("������ɣ�����������%d���鿴\n", SHOW);*/
}