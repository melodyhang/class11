#include<stdio.h>
#include<stdlib.h>
#include<math.h>



/*形式参数和实际参数*/

//自行实现pow函数
//求第一个参数的n次幂
//double num1，double num2——形式参数
double power(double, int);	//函数原型
//根据传入的半径，返回圆面积
double calcCircle(double);
//根据用户输入的宽和高，返回矩形面积
double calcRectangle(double, double);
//对用户输入的值进行非负验证/让用户输入正确的值/拿到用户所输入的正确值
int validate(double);	//验证输入的double类型数据是否为正数

double input();	//函数内直接让用户输入，如果不符合要求就重新录入，返回录入正确的数字


double power(double num1, int num2)	//函数定义
{
	double result = 1;
	int i;
	for (i = 0; i < num2; i++)
	{
		result *= num1;
	}
	return result;
}

double calcCircle(double radius)
{
	//pow函数可以自己定义
	double s = 3.14 * pow(radius, 2);
	//返回计算好的面积的值
	return s;
}

double calcRectangle(double width, double height)
{
	return width * height;
}

int validate(double num)
{
		return num > 0;	//如果num>0,会返回一个非零值，表示真
}



int main()
{
	//实际参数——调用
	//printf("%d的%d次幂等于：%.2lf", 8, 4, power(8, 4));
	
	
	double radius;
	double width, height;	
	double s;
	int choice;		//用户的选择


	printf("1、圆\n");
	printf("2、矩形\n");
	printf("3、三角形\n");
	printf("本系统支持计算三种图形的面积，请选择：");
	scanf_s("%d", &choice);
	switch (choice)
	{
	case 1:
		printf("请输入圆的半径：");
		do {
			scanf_s("%lf", &radius);
			if (!validate(radius))	//如果没有通过验证，就打印一句提示
			{
				printf("所录入的内容不能为负数，请重新输入两个正数：");		//录入
			}
		} while (!validate(radius));	//当验证不通过的时候，重新录入
		s = calcCircle(radius);
		break;		
	case2:
		printf("请输入矩形的宽和高：");
		do {
			scanf_s("%lf%lf",&width,&height);
			if (!validate(width)||!validate(height))	//如果没有通过验证，就打印一句提示
			{
				printf("所录入的内容不能为负数，请重新输入一个正数：");		//录入
			}
		} while (!validate(width) || !validate(height));
		s = calcRectangle(width, height);
		break;
	case3:
		printf("");
		break;
	defult:
		printf("本系统只支持3种图形，请在1-3之间选择！");
	}
	printf("计算出来的面积是：%.2lf", s);

	return 0;
}