#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void game(difficulty)
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

	printf("**********************\n");
	printf("*****������С��Ϸ*****\n");
	printf("**********************\n");
	printf("******1.��ʼ��Ϸ******\n");
	printf("******2.�Ѷ�ѡ��******\n");
	printf("******3.�˳���Ϸ******\n");
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
			game(difficulty);

			printf("��������һ��������1��ȷ��,����2�Ե����Ѷ�:>>");
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
			else
			{
				main_mune = 3;
			}

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

