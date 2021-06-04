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
		//标题
		printf("%-12s\t%-4s\t%-5s\t%-12s\t%-12s\n", "姓名", "年龄", "性别", "电话", "地址");
		//内容
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
	return -1;//找不到
}

void DelContact(struct Contact* ps)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入要删除联系人的姓名：");
	scanf("%s", name);
	//1.查找要删除联系人的位置
	int pos = FindName(ps, name);//找到了返回名字所在元素的下标，找不到返回-1
	//2.删除
	if (pos == -1)
	{
		printf("要删除的联系人不存在\n");
	}
	else
	{
		int j = 0;
		for (j = pos;j < ps->size - 1;j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}
}

void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入联系人姓名：");
	scanf("%s", name);
	int pos = FindName(ps, name);
	if (pos == -1)
	{
		printf("该联系人不存在\n");
	}
	else
	{
		printf("%-12s\t%-4s\t%-5s\t%-12s\t%-12s\n", "姓名", "年龄", "性别", "电话", "地址");
		//内容
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
	printf("请输入要修改联系人的姓名：");
	scanf("%s", name);
	int pos = FindName(ps, name);
	if (pos == -1)
	{
		printf("该联系人不存在\n");
	}
	else
	{
		printf("请输入姓名：");
		scanf("%s", ps->data[pos].name);
		printf("请输入年龄：");
		scanf("%d", &(ps->data[pos].age));
		printf("请输入性别：");
		scanf("%s", ps->data[pos].sex);
		printf("请输入电话：");
		scanf("%s", ps->data[pos].tele);
		printf("请输入地址：");
		scanf("%s", ps->data[pos].addr);

		printf("修改完成\n");
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
	printf("排序完成，您可以输入%d来查看\n", SHOW);*/
}