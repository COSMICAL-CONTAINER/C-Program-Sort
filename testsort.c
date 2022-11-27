#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

struct StudentInfo
{
    char ID[11];
    char * name;
    double score;
}StuInfo[12]=
{
    {"2000301105", "JACK", 95},
    {"2000201505", "LUN", 85},
    {"2100820115", "MARY", 75.5},
    {"2100850122", "KATE", 78.9},
    {"1900201011", "LILI", 88},
    {"1900401105", "JACK", 96},
    {"2000830105", "JAN", 98.4},
    {"2000520012", "SAM", 75},
    {"1900800045", "OSCAR", 64},
    {"1900301105", "JACK", 97},
    {"2100803312", "ZOE", 68.9},
    {"2100830211", "BOBI", 87.6},
};

typedef struct StudentInfo Student;
typedef Student* P_Student;

/*  ���� int ����  */
bool sort_int(void *a, void *b)
{
    if( *(int *)a >= *(int *)b )
    {
        return True;
    }
    return False;
}

void Print_int(void *P_Int[], int Size)
{
    for(int i = 0; i < Size; ++i)
    {
        printf("%d ",*(int *)(P_Int[i]));
    }
    putchar('\n');
}

/*  ���� double ����  */
bool sort_double(void *a, void *b)
{
    if( *(double *)a >= *(double *)b )
    {
        return True;
    }
    return False;
}

void Print_double(void *P_Double[], int Size)
{
    for(int i = 0; i < Size; ++i)
    {
        printf("%lf ",*(double *)(P_Double[i]));
    }
    putchar('\n');
}

/*  ���� �ṹ�� ����  */
bool sort_struct_score(void *a, void *b)
{
    if( ((P_Student)(a))->score >= ((P_Student)(b))->score )
    {
        return True;
    }
    return False;
}

bool sort_struct_ID(void *a, void *b)
{
    if( strcmp( ((P_Student)(a))->ID, ((P_Student)(b))->ID) >= 0)
    {
        return True;
    }
    return False;
}

bool sort_struct_name(void *a, void *b)
{
    if( strcmp( ((P_Student)(a))->name, ((P_Student)(b))->name) >= 0)
    {
        return True;
    }
    return False;
}

void Print_struct(void *P_Student_list[], int Size)
{
    printf("    ID      name  score\n");
    for(int i = 0; i < Size; ++i)
    {
        printf("%s ",((P_Student)(P_Student_list[i]))->ID);
        printf("%5s ",((P_Student)(P_Student_list[i]))->name);
        printf("%6.2lf ",((P_Student)(P_Student_list[i]))->score);
        putchar('\n');
    }
}

//p_int ��ָ��һ�� [ָ������(�ź����Ԫ�صĵ�ַ���ɵ�)]�� ָ��
void Print_int_1(void *p_int,int N)
{
    for(int i = 0; i < N; ++i)
    {
        printf("%d ", *(int *)(*((long long *)p_int + i)) );
    }
    putchar('\n');
}

void Print_int_2(long long p_int[],int N)
{
    for(int i = 0; i < N; ++i)
    {
        printf("%d ", *(int *)(p_int[i]) );
    }
    putchar('\n');
}

int main()
{
    Sort_InitTypeDef Sort_InitStructure;
    int array_int[10] = {9,8,7,6,5,4,3,2,1,0};
    double array_double[10] = {9.9,8.8,7.7,6.6,5.5,4.4,3.3,2.2,1.1,10.10};

    printf("���� int ������:\n");
    
    //�������������ÿ��Ԫ����ռ�õĴ�С
    Sort_InitStructure.Sort_Element_Size = sizeof(int);
    //�������������׵�ַ
    Sort_InitStructure.Sort_Arr = array_int;
    //����������ĳ��̣�Ҳ��������Ԫ�صĶ���
    Sort_InitStructure.Sort_Size = sizeof(array_int) / sizeof(array_int[0]);
    //��ʹ�õ����򷽷� [�������򡢹鲢���򡢿�������](Ŀǰд�˵ķ�����������ܻ���������򷽷�)
    Sort_InitStructure.Sort_Method = Sort_Method_Quicksort;
    //�û��Զ���ıȽϺ���������ȷ������Ԫ�ص�������Ⱥ�˳��Ĭ��bool Sort_Comapre(void *a, void *b),���� True ��ʾ��Ҫ����
    Sort_InitStructure.Sort_Compare = sort_int;
    //�����ʱ���Ƿ���Ҫ�ı�ԭ���������˳��������ı�ͻ᷵��һ��ָ������������ʾ����Ľ��
    Sort_InitStructure.Sort_Way = Sort_Way_UnChange;
    //������ɺ�Ĵ�ӡ�����������ź���֮��ֱ�������������Ĭ��void Sort_Print(void *P_Ele[], int Size),����NULL����ѡ�񲻴�ӡ
    Sort_InitStructure.Sort_Printf = Print_int;
    //Sort����������ѡ��Sort_WayΪSort_Way_UnChange��ʱ��᷵��һ��ָ��(��ַ)���� [��ʵ�����������׵�ַ]
    //����ָ����ָ���Ԫ�ؾ��Ǹ����û�������������������˳��
    long long *p_int = Sort(&Sort_InitStructure);
    printf("��ӡ���ص� ָ������ \n");
    //�����ṩ���ַ�����ӡSort�������ص�����
    Print_int_1((void *)p_int, sizeof(array_int) / sizeof(array_int[0]));
    Print_int_2(p_int, sizeof(array_int) / sizeof(array_int[0]));
    //����������Ҫfree����Ƭ�ռ�
    free(p_int);

    //��������Ͳ����ӡ�������
    Sort_InitStructure.Sort_Printf = NULL;
    Sort(&Sort_InitStructure);

    printf("\n���� double ������:\n");
    Sort_InitStructure.Sort_Element_Size = sizeof(double);
    Sort_InitStructure.Sort_Arr = array_double;
    Sort_InitStructure.Sort_Size = sizeof(array_double) / sizeof(array_double[0]);
    Sort_InitStructure.Sort_Method = Sort_Method_Quicksort;
    Sort_InitStructure.Sort_Compare = sort_double;
    Sort_InitStructure.Sort_Way = Sort_Way_Change;
    Sort_InitStructure.Sort_Printf = Print_double;

    Sort(&Sort_InitStructure);

    printf("\n�� ID ����ṹ��:\n");
    Sort_InitStructure.Sort_Element_Size = sizeof(StuInfo[0]);
    Sort_InitStructure.Sort_Arr = StuInfo;
    Sort_InitStructure.Sort_Size = sizeof(StuInfo) / sizeof(StuInfo[0]);
    Sort_InitStructure.Sort_Method = Sort_Method_Quicksort;
    Sort_InitStructure.Sort_Compare = sort_struct_ID;
    Sort_InitStructure.Sort_Way = Sort_Way_Change;
    Sort_InitStructure.Sort_Printf = Print_struct;
    Sort(&Sort_InitStructure);

    //�������ʼ����֮������Ҫ�ı�ṹ������ľ������ݵ�ʱ��ֻ��Ҫ�ı�Sort_Compare
    printf("\n�� name ����ṹ��:\n");
    Sort_InitStructure.Sort_Compare = sort_struct_name;
    Sort(&Sort_InitStructure);

    printf("\n�� score ����ṹ��:\n");
    Sort_InitStructure.Sort_Compare = sort_struct_score;
    Sort(&Sort_InitStructure);

    printf("\nԭ����int����:\n");
    for(int i = 0; i < sizeof(array_int) / sizeof(array_int[0]); ++i)
    {
        printf("%d ",array_int[i]);
    }
    putchar('\n');

    printf("\nԭ����double����:\n");
    for(int i = 0; i < sizeof(array_double) / sizeof(array_double[0]); ++i)
    {
        printf("%lf ",array_double[i]);
    }
    putchar('\n');

    printf("\nԭ���Ľṹ��:\n");
    printf("    ID      name  score\n");
    for(int i = 0; i < sizeof(StuInfo) / sizeof(StuInfo[0]); ++i)
    {
        printf("%s ",(StuInfo[i]).ID);
        printf("%5s ",(StuInfo[i]).name);
        printf("%6.2lf ",(StuInfo[i]).score);
        putchar('\n');
    }

    return 0;
}