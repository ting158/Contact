#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"

void menu()
{
	printf("**************************************\n");
	printf("*****    1. add        2. del   ******\n");
	printf("*****    3. search     4. modify******\n");
	printf("*****    5. show       6. sort  ******\n");
	printf("*****    0. exit                ******\n");
	printf("**************************************\n");
}

int main()
{
	int input = 0;
	//����ͨѶ¼
	struct Contact con;//con����ͨѶ¼����߰���1000��Ԫ�ص������size
	//��ʼ��ͨѶ¼
	InitContact(&con);
	do
	{
		menu();
		printf("�����룺");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case EXIT:
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}