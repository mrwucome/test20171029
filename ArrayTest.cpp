// ArrayTest.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "stdio.h"

//-----------------------------------------
//1 ��������Ϊ��������ʱ:�����ǽ���ֵ�Ĵ���,����������������׵�ַ���������������Ϊ��������ʱ�����еĴ���ֻ�ǵ�ַ�Ĵ���,��ʵ�����β���һ�ι��õ��ڴ�ռ䡣
//
//2 ���ܸ������� (��������һ����ַ��һ��ָ�볣������const�͵ģ������޸�)
//-----------------------------------------



//һά���鶨�����ʽ
//void printvalues(int *param);  
//void printvalues(int param[]);  
//void printvalues(int param[10]); 
//void printvalues(int param[],int size);//���ڱ���������Ե�һά����ĳ��ȣ����Խ��䳤����Ϊ�ڶ����β�

//��ά���鶨���������ʽ
//void printvalues(int (*matrix)[10],int rowsize);  
//void printvalues(int matrix[][10],int rowsize);//��Ϊ��һά����һ������������Ե�һά�ĳ��ȣ������ðѵ�һά�ĳ�����Ϊ�ڶ����β�









void func(int n, char **str)
{	
	int i; 
	for(i = 0; i < n; i++) 
		printf("\nstr[%d] = %s\n", i, str[i]);
}


void addArray1 (int b[10])
{
    int i=0;
    for(;i<10;i++)
    {
		b[i] +=1;
        printf("%d,",b[i]);
    }
	printf("\n");
}

void aa_cmd(int(*pp)[5])
{
	int tmp = 0;
	
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			//tmp = pp[i][j]++;
			tmp = *(*pp+j);
			printf("%d,",tmp);
		}
		pp++;
		printf("\n");
	}
	printf("\n");
}

int _tmain(int argc, _TCHAR* argv[])
{
    int a[10]={2,4,6,8,10,12,14,16,18,20};
	int aa[2][5] = {{1,2,3,4,5},{6,7,8,9,10}};
#if 0
    addArray1(a);//��������Ϊ��������
    for(int i=0;i<10;i++)
    {
        printf("%d,",a[i]);//��Ӱ�챾��
    }
#endif

#if 0
	 char* p[3];  
	 char str[][5] = {"abc","def","ghi"}; 
	 p[0] = &str[0][0]; 
	 p[1] = str[1]; 
	 p[2] = str[2]; 
	 func(3, p);
#endif
	aa_cmd(aa);
	printf("-------------------------------\n");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 5; j++)
		{			
			printf("%d,",aa[i][j]);
		}
		printf("\n");
	}
	


	return 0;
}

