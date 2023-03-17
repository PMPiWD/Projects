#include <stdio.h>
#include <windows.h>
#include <time.h>

unsigned int random (unsigned int x);

int main()
{
	char class123[50][20] = {0};//我们先进的数组定义
	char number = 0;
	unsigned int number_s = 0;
	short lab = 0;
	char last = 0;
	char getting = 0;//定义变量
	printf("*****************************\n");
	printf("********创*建*随*机*项********\n");
	printf("*****************************\n");
	Sleep(500);
first:
	system("cls");
	rewind(stdin);
	printf("请选择要执行的操作\n1、随机默认项目\n2、自定义随机\n3、退出程序\n");
	scanf_s("%hhd", &getting);
	Sleep(100);
	switch (getting)//switch 语句
	{
	case 1: 
		number_s = 1;
		number = 43;
		printf("处理中...请稍后 \n");
		goto student;//这里使用的标签名以学生为例
	case 2:
		printf("处理中...请稍后 \n");
		goto scanf;
	case 3:
		return 0;
	default:
		goto wrong;//错误输入
	}

wrong:
	rewind(stdin);//清空键盘缓冲区
	printf("输入错误，请按下ENTER键重试...\n");
	getting = getchar();//读取按键
	if (getting != 10)//10 /n ASCII码值
	{
		printf("操作错误，退出程序...");
		Sleep(200);
		return 0;
	}
	else
	{
		goto first;//返回选择区块
	}
scanf:
	if (number != 0) {
		printf("自定义再次输入...\n");
		Sleep(100);
	}
	number = 0;
	Sleep(150);
	system("cls");
	rewind(stdin);
	printf("请输入你要随机项目的数量(1<x<=50 非小数)\n");//项目数量
	scanf_s("%hhd", &number);
	Sleep(300);
	lab = number % 1;
	if (number <= 1 || number > 50 || lab != 0)//检验是否为小数
	{
		printf("请合法输入\n");
		Sleep(200);
		goto scanf;
	}
	rewind(stdin);
	printf("请输入你要随机的项目（以Enter隔开）\n");
	int i;
	for (i = 0; i < number; i++)
	{
		rewind(stdin);
		printf("输入第%d个项目：\n",(i+1));
		scanf_s("%s",class123[i],20);//先进的下标输入
	}
	printf("输入完毕\n");
	Sleep(350);
student:
again:
	system("cls");
	printf("正在随机...\n");
	Sleep(300);
	int result = random(number);
	printf("随机完成-->");
	if (number_s == 1) {
		const char students[44][10] = {0};//可自己写入常用项来顶替1号位默认随机内容(这里未输入) 变量名以学生为例，毕竟一般上课点名可以用这个(doge)
		//先进的项目版数组初始化 const常变量标识符的使用
		printf("%s\n", students[result]);
		if (result == 43) {
			printf("3秒后再次随机...\n");
				Sleep(350);
				goto again;
		}
	}
	else{
		printf("%s\n", class123[result]);//先进的利用下标进行输出
	}
	
	Sleep(200);
	rewind(stdin);
	printf("按ENTER键以继续\n");
	getting = getchar();//接收按键
	system("cls");
	if (getting != 10)
	{
	enter:
		rewind(stdin);
		printf("按键错误，请按下ENTER键重试...\n");
		getting = getchar();
		if (getting != 10)
		{
			printf("操作错误...");
			goto enter;
		}
		else
		{
			printf("前往选项菜单...\n");
		}
	}
	Sleep(300);
last:
	system("cls");
	rewind(stdin);
	printf("菜单栏：\n1、保留原设置随机\n（原设置再次随机，不与默认随机共用）\n\n2、返回并直接\\再次默认随机\n\n3、重置设置随机\n（回到自定义随机）\n\n4、退出程序\n");//选择
	scanf_s("%hhd", &last);
	switch (last)
	{
	case 1:
		if (number_s != 0) {
			printf("本设置不与随机默认项共用，选择无效（请选择2）\n");
			Sleep(500);
			goto last;
		}
		else{
			printf("保持原设置再次随机...\n");
			Sleep(200);
			goto again;//回到创建随机处
		}
	case 2:
		number_s = 1;
		goto student;
	case 3:
		printf("重置设置中，删除原配置...\n");
		number_s = 0;
		Sleep(200);
		goto scanf;//回到初始输入处
	case 4:
		break;
	default:
		printf("输入错误，请重试\n");
		Sleep(350);
		goto last;
	}
	return 0;
}
//随机函数整合版
unsigned int random(unsigned int x)
{
	unsigned int num = 0;
	unsigned int y;
	srand((unsigned int)time(NULL));//创建随机项
	num = rand() % 100 + 1;//%100 0~99随机数值 +1 -> 1~100
	y = num % x;//上文原因：0不能做除数
	//范围: 0~（number-1）（数组下标）
	return y;
}


//总结：数组好，50行代码一行搞定，加上输入输出定义等等，至少省下200行
//编程不是一味的重复，要善于运用循环、数组，下标配合循环会很方便，前提是注意下标起始点为“0”


