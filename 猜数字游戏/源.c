#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void game(difficulty,goal)
{
	int guess = 0;//��Ҳµ���
	int time = 0;//��¼����
	int key = 1;//��ʼ��
	system("cls");//����

	switch (difficulty)
	{
	case 1:
	{
		key = rand() % 100 + 1;
		printf("��ģʽ������ѳɹ�����\n");
		break;
	}
	case 2:
	{
		key = rand() % 1000 + 1;
		printf("��ͨģʽ������ѳɹ�����\n");
		break;
	}
	case 3:
	{
		key = rand();
		printf("����ģʽ������ѳɹ�����\n");
		break;
	}
	default :
	{
		printf("�Ѷ����ó����Ѷ��Զ����������Ѷ�\n");
		key = rand() % 100 + 1;
		break;
	}
	}//��������ɲ���

	while (goal >= 1)
	{
		printf("��ǰĿ��Ϊ %d �β³��յ�\n", goal);
		break;
	}//��������Ŀ��ʱ����ʾ���
	printf("��Ϸ��ʽ��ʼ�������������µ�����:>>");
	while (1)
	{
		scanf("%d", &guess);
		if (guess == -1)
		{
			time++;
			printf("�յ���%d\n", key);
			continue;
		}//�����ú���
		else if (guess > key)
		{
			printf("�´��ˣ������԰�:>>");
			time++;
			continue;
		}
		else if (guess < key)
		{
			printf("��С�ˣ������԰�:>>");
			time++;
			continue;
		}
		else
		{
			time++;
			printf("�¶��ˣ��յ׼�Ϊ%d\n��һ��������%d��\n", key, time);
			while (goal >= 1)
			{
				if (time <= goal)
				{
					printf("�ɹ����Ŀ�꣡����\n");
					break;
				}
				else
				{
					printf("���ź�û�����Ŀ��......\n");
					break;
				}
			}//�ж�Ŀ���Ƿ����
			break;
		}
	}
}//��Ϸ����


int main()
{
	int a = 1;//����ѭ��
	srand((unsigned int)time(NULL));//���������Ԥ��
	int main_mune = 0;//�������˵�
	static int difficulty = 1;//�Ѷȿ���
	int goal = 0;//Ŀ������

begin:
	printf("**********************\n");
	printf("*****������С��Ϸ*****\n");
	printf("**********************\n");
	printf("******1.��ʼ��Ϸ******\n");
	printf("******2.�Ѷ�ѡ��******\n");
	printf("******3.����Ŀ��******\n");
	printf("******4.�˳���Ϸ******\n");
	printf("**********************\n");

	printf("������������ִ����ز���:>");
	scanf("%d", &main_mune);

	do
	{
		switch (main_mune)
		{
		case 1:
		{
			printf("��Ϸ��ʼ��ף��Ϸ���\n");
			game(difficulty, goal);

			printf("��������һ��������1��ȷ��,����2�Ե����Ѷȣ�����3�Ը���Ŀ�꣬���������������˳���Ϸ:>>");
			int want = 0;
			scanf("%d", &want);
			if (want == 1)
			{
				main_mune = 1;
			}
			else if (want == 2)
			{
				main_mune = 2;
			}
			else if (want == 3)
			{
				main_mune = 3;
			}
			else
			{
				main_mune = 4;
			}//��תָ���˵�

			break;
		}//����һ�ι���
		case 2:
		{
			printf("**********************\n");
			printf("*******�Ѷ�ѡ��*******\n");
			printf("**********************\n");
			printf("******1.���Ѷ�******\n");
			printf("******2.��ͨ�Ѷ�******\n");
			printf("******3.�����Ѷ�******\n");
			printf("**********************\n");
			//�ѶȲ˵�
			printf("������������ִ����ز���:>");
			scanf("%d", &difficulty);
			int b = 1;//����ѭ��

			do
			{
				switch (difficulty)
				{
				case 1:
				{
					printf("��ǰΪ���Ѷ�\n");
					b = 0;
					main_mune = 1;
					break;
				}
				case 2:
				{
					printf("��ǰΪ��ͨ�Ѷ�\n");
					b = 0;
					main_mune = 1;
					break;
				}
				case 3:
				{
					printf("��ǰΪ�����Ѷ�\n");
					b = 0;
					main_mune = 1;
					break;
				}
				default:
				{
					printf("�Ѷ�������Ч��������\n");
					printf("������������ִ����ز���:>");
					scanf("%d", &difficulty);
					continue;

				}
				}
			} while (b == 1);//�Ѷ�ѡ���ж�
			break;
		}
		case 3:
		{
			printf("�����������õ�Ŀ��:>>");
			scanf("%d", &goal);
			if (goal <= 0)
			{
				while (goal <= 0);
				{
					printf("��Ч���룬����������:>>");
					scanf("%d", &goal);
				}//�ų�goalΪ������0�����
			}
			printf("���óɹ�����ǰĿ��Ϊ %d ���ڲ³��յ�\n", goal);
			goto begin;
		}//Ŀ�����ò���

		case 4:
		{
			printf("��Ϸ���˳����ڴ��������´����\n");
			a = 0;
			break;//�˳���Ϸ
		}
		default:
		{
			printf("��Ч���룬������:>>");
			scanf("%d", &main_mune);
			continue;
		}//���˵�ѡ���ж�
		}
	}
	while (a == 1);

	return 0;
}//������

