#pragma once

#include <stdio.h>
#include <string.h>

#define MAX 100

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

enum Option
{
	EXIT,//0
	ADD,//1
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};

struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

//ͨѶ¼����
struct Contact
{
	struct PeoInfo data[MAX];//���һ����Ϣ
	int size;//��¼��ǰ�Ѿ��е�Ԫ�ظ���
};

//��������
void InitContact(struct Contact* ps);//��ʼ��ͨѶ¼
void AddContact(struct Contact* ps);//����ͨѶ¼��Ϣ
void ShowContact(const struct Contact* ps);//��ӡͨѶ¼��Ϣ
void DelContact(struct Contact* ps);//ɾ��ָ����ͨѶ¼��Ϣ
void SearchContact(const struct Contact* ps);//����ָ����ϵ��
void ModifyContact(struct Contact* ps);//�޸�ָ����ϵ����Ϣ
void SortContact(struct Contact* ps);//������������