//
//  pointer.c
//  program design
//
//  Created by duoguang xu on 2020/11/25.
//

#include "pointer.h"

//6
//求字符串长度
int ex_6(void)
{
    int length(char *s);
    int len = 0;
    char str[20];
    printf("input string:\n");
    scanf("%s",str);
    len = length(str);
    printf("the length of the string is %d\n",len);
    return 0;
}

int length(char *s)
{
    int n;
    n = 0;
    while(*s != '\0')
    {
        s++;
        n++;
    }
    return n;
}

//7
//从指定位置复制字符串
int ex_7(void)
{
    void copystr(char *, char*, int);
    int m;
    char s1[20], s2[20];
    printf("input something:\n");
    gets(s1);
    printf("where do u wanna start?\n");
    scanf("%d",&m);
    while(m > strlen(s1))
    {
        printf("m is too large! input again:\n");
        scanf("%d",&m);
    }
    copystr(s1, s2, m);
    printf("the reslut:\n%s",s2);
    
    
    return 0;
}

void copystr(char *s1, char *s2, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        s1++;
    }
    while(*s1 != '\0')
    {
        *s2 = *s1;
        s2++;
        s1++;
    }
    //注意！最后加一个结束符号
    *s2 = '\0';
}



//8
//统计大小写字母、空格、数字以及其他字符数量
int ex_8(void)
{
    int upper = 0, lower = 0, space = 0, digit = 0, other = 0, i = 0;
    char *p, s[200];
    printf("input string:\n");
    while((s[i] = getchar()) != '\n')
    {
        i++;
    }
    p = &s[0];
    while(*p != '\n')
    {
        if(*p == ' ')
        {
            space++;
        }
        else if(*p >= 'A' && *p <= 'Z')
        {
            upper++;
        }
        else if(*p >= 'a' && *p <= 'z')
        {
            lower++;
        }
        else if(*p >= '0' && *p <= '9')
        {
            digit++;
        }
        else
        {
            other++;
        }
        p++;
    }
    printf("upper: %d\nlower: %d\ndigit: %d\nspace: %d\nother: %d\n",upper,lower,digit,space,other);
    return 0;
}



//9
//三阶矩阵转置

//进阶版，非方阵转置
//M*N   用空间2*M*N
//如果想用M*N呢？
//等待更进阶
#define M 4
#define N 3
int ex_9(void)
{
    void transpose(int *, int *);
    int a[M][N], b[N][M], i, j;
    printf("input the elements:\n");
    for(i = 0; i < M; i++)
    {
        for(j = 0; j < N; j++)
        {
            scanf("%d",&a[i][j]);
        }

    }
    //转置
    transpose(*a,*b);
    //打印原矩阵
    printf("original matrix:\n");
    for(i = 0; i < M; i++)
    {
        for(j = 0; j < N; j++)
        {
            printf("%2d ",a[i][j]);
        }
        printf("\n");
    }
    //打印转置后的矩阵
    printf("transposed matrix:\n");
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < M; j++)
        {
            printf("%2d ",b[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}


void transpose(int *p1, int *p2)
{
    int i, j;
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < M; j++)
        {
            //核心
            *(p2 + i * M + j) = *(p1 + j * N + i);
        }
    }
}


//我这里改一点东西，试试git
