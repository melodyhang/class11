#include<stdio.h>
#include<stdlib.h>
#include<math.h>



/*��ʽ������ʵ�ʲ���*/

//����ʵ��pow����
//���һ��������n����
//double num1��double num2������ʽ����
double power(double, int);	//����ԭ��
//���ݴ���İ뾶������Բ���
double calcCircle(double);
//�����û�����Ŀ�͸ߣ����ؾ������
double calcRectangle(double, double);
//���û������ֵ���зǸ���֤/���û�������ȷ��ֵ/�õ��û����������ȷֵ
int validate(double);	//��֤�����double���������Ƿ�Ϊ����

double input();	//������ֱ�����û����룬���������Ҫ�������¼�룬����¼����ȷ������


double power(double num1, int num2)	//��������
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
	//pow���������Լ�����
	double s = 3.14 * pow(radius, 2);
	//���ؼ���õ������ֵ
	return s;
}

double calcRectangle(double width, double height)
{
	return width * height;
}

int validate(double num)
{
		return num > 0;	//���num>0,�᷵��һ������ֵ����ʾ��
}



int main()
{
	//ʵ�ʲ�����������
	//printf("%d��%d���ݵ��ڣ�%.2lf", 8, 4, power(8, 4));
	
	
	double radius;
	double width, height;	
	double s;
	int choice;		//�û���ѡ��


	printf("1��Բ\n");
	printf("2������\n");
	printf("3��������\n");
	printf("��ϵͳ֧�ּ�������ͼ�ε��������ѡ��");
	scanf_s("%d", &choice);
	switch (choice)
	{
	case 1:
		printf("������Բ�İ뾶��");
		do {
			scanf_s("%lf", &radius);
			if (!validate(radius))	//���û��ͨ����֤���ʹ�ӡһ����ʾ
			{
				printf("��¼������ݲ���Ϊ��������������������������");		//¼��
			}
		} while (!validate(radius));	//����֤��ͨ����ʱ������¼��
		s = calcCircle(radius);
		break;		
	case2:
		printf("��������εĿ�͸ߣ�");
		do {
			scanf_s("%lf%lf",&width,&height);
			if (!validate(width)||!validate(height))	//���û��ͨ����֤���ʹ�ӡһ����ʾ
			{
				printf("��¼������ݲ���Ϊ����������������һ��������");		//¼��
			}
		} while (!validate(width) || !validate(height));
		s = calcRectangle(width, height);
		break;
	case3:
		printf("");
		break;
	defult:
		printf("��ϵͳֻ֧��3��ͼ�Σ�����1-3֮��ѡ��");
	}
	printf("�������������ǣ�%.2lf", s);

	return 0;
}