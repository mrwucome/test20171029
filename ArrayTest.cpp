// ArrayTest.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "stdio.h"

//-----------------------------------------
//1 数组名作为函数参数时:并不是进行值的传递,数组名就是数组的首地址。因此在数组名作为函数参数时所进行的传递只是地址的传递,即实参与形参有一段共用的内存空间。
//
//2 不能复制数组 (数组名是一个地址，一个指针常量，是const型的，不能修改)
//-----------------------------------------



//一维数组定义的形式
//void printvalues(int *param);  
//void printvalues(int param[]);  
//void printvalues(int param[10]); 
//void printvalues(int param[],int size);//由于编译器会忽略第一维数组的长度，所以将其长度作为第二个形参

//二维数组定义的两种形式
//void printvalues(int (*matrix)[10],int rowsize);  
//void printvalues(int matrix[][10],int rowsize);//因为和一维数组一样编译器会忽略第一维的长度，因此最好把第一维的长度作为第二个形参









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
    addArray1(a);//数组名作为函数参数
    for(int i=0;i<10;i++)
    {
        printf("%d,",a[i]);//会影响本身
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

