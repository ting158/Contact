#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"

void InitContact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->size));
	ps->size = 0;//设置通讯录最初只有0个元素
}

void AddContact(struct Contact* ps)
{
	if (ps->size == MAX)
	{
		printf("通讯录已满，无法增加\n");
	}
	else
	{
		printf("请输入姓名：");
		scanf("%s", ps->data[ps->size].name);
		printf("请输入年龄：");
		scanf("%d", &(ps->data[ps->size].age));
		printf("请输入性别：");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入电话：");
		scanf("%s", ps->data[ps->size].tele);
		printf("请输入地址：");
		scanf("%s", ps->data[ps->size].addr);

		ps->size++;
		printf("添加成功\n");
	}
}

void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("无联系人\n");
	}
	else
	{
		int i = 0;
		printf("%-12s\t%-4s\t%-5s\t%-12s\t%-12s\n", "姓名", "年龄", "性别", "电话", "地址");
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