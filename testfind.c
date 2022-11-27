#include <stdio.h>
#include <string.h>
#include "sort.h"
#include "find.h"

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
typedef Student ElementType;
typedef Student* P_Student;

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


void Print_struct1(Student s1)
{
    printf("    ID      name  score\n");
    printf("%s ",s1.ID);
    printf("%5s ",s1.name);
    printf("%6.2lf ",s1.score);
    putchar('\n');
}


/****************/
bool Find_ID(void *Ele, void *WantFind)
{
    int result = strcmp(((P_Student)(Ele))->ID, (char *)WantFind);
    if( result == 0 )
    {
        return Find_Result_Equation;
    }
    else if( result >= 0)
    {
        return Find_Result_Bigger;
    }
    else
    {
        return Find_Result_Smaller;
    }
}

bool Find_Name(void *Ele, void *WantFind)
{
    int result = strcmp(((P_Student)(Ele))->name, (char *)WantFind);
    if( result == 0 )
    {
        return Find_Result_Equation;
    }
    else if( result >= 0)
    {
        return Find_Result_Bigger;
    }
    else
    {
        return Find_Result_Smaller;
    }
}

bool Find_Score(void *Ele, void *WantFind)
{
    if( ((P_Student)(Ele))->score == *(double *)WantFind)
    {
        return Find_Result_Equation;
    }
    else if( ((P_Student)(Ele))->score > *(double *)WantFind)
    {
        return Find_Result_Bigger;
    }
    else
    {
        return Find_Result_Smaller;
    }
}



int main()
{
    Sort_InitTypeDef Sort_InitStructure;
    int student = 0;
    char ID[11];
    char name[20];
    double score;

    printf("\n�� ID ����ṹ��:\n");
    //�������������ÿ��Ԫ����ռ�õĴ�С
    Sort_InitStructure.Sort_Element_Size = sizeof(StuInfo[0]);
    //�������������׵�ַ
    Sort_InitStructure.Sort_Arr = StuInfo;
    //����������ĳ��̣�Ҳ��������Ԫ�صĶ���
    Sort_InitStructure.Sort_Size = sizeof(StuInfo) / sizeof(StuInfo[0]);
    //��ʹ�õ����򷽷� [�������򡢹鲢���򡢿�������](Ŀǰд�˵ķ�����������ܻ���������򷽷�)
    Sort_InitStructure.Sort_Method = Sort_Method_Quicksort;
    //�û��Զ���ıȽϺ���������ȷ������Ԫ�ص�������Ⱥ�˳��Ĭ��bool Sort_Comapre(void *a, void *b),���� True ��ʾ��Ҫ����
    Sort_InitStructure.Sort_Compare = sort_struct_ID;
    //�����ʱ���Ƿ���Ҫ�ı�ԭ���������˳��������ı�ͻ᷵��һ��ָ������������ʾ����Ľ��
    Sort_InitStructure.Sort_Way = Sort_Way_Change;
    //������ɺ�Ĵ�ӡ�����������ź���֮��ֱ�������������Ĭ��void Sort_Print(void *P_Ele[], int Size),����NULL����ѡ�񲻴�ӡ
    Sort_InitStructure.Sort_Printf = Print_struct;
    Sort(&Sort_InitStructure);
    printf("������Ҫ���ҵ�ѧ����ID:");
    gets(ID);
    
    //��ʼ�����ҽṹ��
    Find_InitTypeDef Find_InitStruct;
    //�����в��ҵ�������ÿ��Ԫ����ռ�õĴ�С
    Find_InitStruct.Find_Element_Size = sizeof(StuInfo[0]);
    //�����в��ҵ�����
    Find_InitStruct.Find_Arr = StuInfo;
    //�����в��ҵ�����ĳ���
    Find_InitStruct.Find_Size = sizeof(StuInfo) / sizeof(StuInfo[0]);
    //�����еĲ��Һ���
    Find_InitStruct.Find_Compare = Find_ID;
    //�����ҵ�Ԫ��
    Find_InitStruct.WantFind = ID;
    student = BinarySearch(&Find_InitStruct);
    if( student >= 0)
    {
        printf("���ҵ� ID Ϊ %s ��ѧ��\n", ID);
        Print_struct1(StuInfo[student]);
    }
    else
    {
        printf("û���ҵ���ѧ��\n");
    }


    //�������ʼ����֮������Ҫ�ı�ṹ������ľ������ݵ�ʱ��ֻ��Ҫ�ı�Sort_Compare
    printf("\n�� name ����ṹ��:\n");
    Sort_InitStructure.Sort_Compare = sort_struct_name;
    Sort(&Sort_InitStructure);
    printf("������Ҫ���ҵ�ѧ��������:");
    gets(name);
    //ͬ����������Ҳֻ��Ҫ����Find_Compare�ĸı��Լ�Ҫ���ҵ�Ԫ�ص�
    Find_InitStruct.Find_Compare = Find_Name;
    Find_InitStruct.WantFind = name;
    student = BinarySearch(&Find_InitStruct);
    if( student >= 0)
    {
        printf("���ҵ� name Ϊ %s ��ѧ��\n", name);
        Print_struct1(StuInfo[student]);
    }
    else
    {
        printf("û���ҵ���ѧ��\n");
    }

    printf("\n�� score ����ṹ��:\n");
    Sort_InitStructure.Sort_Compare = sort_struct_score;
    Sort(&Sort_InitStructure);
    printf("������Ҫ���ҵ�ѧ���ķ���:");
    scanf("%lf",&score);
    Find_InitStruct.Find_Compare = Find_Score;
    Find_InitStruct.WantFind = &score;
    student = BinarySearch(&Find_InitStruct);
    if( student >= 0)
    {
        printf("���ҵ� score Ϊ %lf ��ѧ��\n", score);
        Print_struct1(StuInfo[student]);
    }
    else
    {
        printf("û���ҵ���ѧ��\n");
    }
    return 0;
}