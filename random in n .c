#include <stdio.h>
#include <windows.h>
#include <time.h>

unsigned int random (unsigned int x);

int main()
{
	char class123[50][20] = {0};//�����Ƚ������鶨��
	char number = 0;
	unsigned int number_s = 0;
	short lab = 0;
	char last = 0;
	char getting = 0;//�������
	printf("*****************************\n");
	printf("********��*��*��*��*��********\n");
	printf("*****************************\n");
	Sleep(500);
first:
	system("cls");
	rewind(stdin);
	printf("��ѡ��Ҫִ�еĲ���\n1�����Ĭ����Ŀ\n2���Զ������\n3���˳�����\n");
	scanf_s("%hhd", &getting);
	Sleep(100);
	switch (getting)//switch ���
	{
	case 1: 
		number_s = 1;
		number = 43;
		printf("������...���Ժ� \n");
		goto student;//����ʹ�õı�ǩ����ѧ��Ϊ��
	case 2:
		printf("������...���Ժ� \n");
		goto scanf;
	case 3:
		return 0;
	default:
		goto wrong;//��������
	}

wrong:
	rewind(stdin);//��ռ��̻�����
	printf("��������밴��ENTER������...\n");
	getting = getchar();//��ȡ����
	if (getting != 10)//10 /n ASCII��ֵ
	{
		printf("���������˳�����...");
		Sleep(200);
		return 0;
	}
	else
	{
		goto first;//����ѡ������
	}
scanf:
	if (number != 0) {
		printf("�Զ����ٴ�����...\n");
		Sleep(100);
	}
	number = 0;
	Sleep(150);
	system("cls");
	rewind(stdin);
	printf("��������Ҫ�����Ŀ������(1<x<=50 ��С��)\n");//��Ŀ����
	scanf_s("%hhd", &number);
	Sleep(300);
	lab = number % 1;
	if (number <= 1 || number > 50 || lab != 0)//�����Ƿ�ΪС��
	{
		printf("��Ϸ�����\n");
		Sleep(200);
		goto scanf;
	}
	rewind(stdin);
	printf("��������Ҫ�������Ŀ����Enter������\n");
	int i;
	for (i = 0; i < number; i++)
	{
		rewind(stdin);
		printf("�����%d����Ŀ��\n",(i+1));
		scanf_s("%s",class123[i],20);//�Ƚ����±�����
	}
	printf("�������\n");
	Sleep(350);
student:
again:
	system("cls");
	printf("�������...\n");
	Sleep(300);
	int result = random(number);
	printf("������-->");
	if (number_s == 1) {
		const char students[44][10] = {0};//���Լ�д�볣����������1��λĬ���������(����δ����) ��������ѧ��Ϊ�����Ͼ�һ���Ͽε������������(doge)
		//�Ƚ�����Ŀ�������ʼ�� const��������ʶ����ʹ��
		printf("%s\n", students[result]);
		if (result == 43) {
			printf("3����ٴ����...\n");
				Sleep(350);
				goto again;
		}
	}
	else{
		printf("%s\n", class123[result]);//�Ƚ��������±�������
	}
	
	Sleep(200);
	rewind(stdin);
	printf("��ENTER���Լ���\n");
	getting = getchar();//���հ���
	system("cls");
	if (getting != 10)
	{
	enter:
		rewind(stdin);
		printf("���������밴��ENTER������...\n");
		getting = getchar();
		if (getting != 10)
		{
			printf("��������...");
			goto enter;
		}
		else
		{
			printf("ǰ��ѡ��˵�...\n");
		}
	}
	Sleep(300);
last:
	system("cls");
	rewind(stdin);
	printf("�˵�����\n1������ԭ�������\n��ԭ�����ٴ����������Ĭ��������ã�\n\n2�����ز�ֱ��\\�ٴ�Ĭ�����\n\n3�������������\n���ص��Զ��������\n\n4���˳�����\n");//ѡ��
	scanf_s("%hhd", &last);
	switch (last)
	{
	case 1:
		if (number_s != 0) {
			printf("�����ò������Ĭ����ã�ѡ����Ч����ѡ��2��\n");
			Sleep(500);
			goto last;
		}
		else{
			printf("����ԭ�����ٴ����...\n");
			Sleep(200);
			goto again;//�ص����������
		}
	case 2:
		number_s = 1;
		goto student;
	case 3:
		printf("���������У�ɾ��ԭ����...\n");
		number_s = 0;
		Sleep(200);
		goto scanf;//�ص���ʼ���봦
	case 4:
		break;
	default:
		printf("�������������\n");
		Sleep(350);
		goto last;
	}
	return 0;
}
//����������ϰ�
unsigned int random(unsigned int x)
{
	unsigned int num = 0;
	unsigned int y;
	srand((unsigned int)time(NULL));//���������
	num = rand() % 100 + 1;//%100 0~99�����ֵ +1 -> 1~100
	y = num % x;//����ԭ��0����������
	//��Χ: 0~��number-1���������±꣩
	return y;
}


//�ܽ᣺����ã�50�д���һ�и㶨�����������������ȵȣ�����ʡ��200��
//��̲���һζ���ظ���Ҫ��������ѭ�������飬�±����ѭ����ܷ��㣬ǰ����ע���±���ʼ��Ϊ��0��


