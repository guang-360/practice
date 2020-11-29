//
//  functions.c
//  program design
//
//  Created by duoguang xu on 2020/11/9.
//

#include <stdio.h>
#include "Header.h"




//18年第四题——算法设计
//BIN_FIND函数查找item在顺序表A[]中item的位置，若没有item，则找到最接近且比item小的元素的位置
int BIN_FIND(int key[], int len, int target)
{
    int low = 1, high = len, mid;
    while(low <= high)
    {
        mid = (low + high)/2;
        if(key[mid] == target)
        {
            return mid;     //success
        }
        if(key[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return 0;       //fail
}

void insert(int A[], int len, int item)
{
    if(!A[len])
    {
        printf("array over flow\n");
        exit(0);
    }
    int pos = BIN_FIND(A, len, item), a, i = len - 2;
    while(i >= pos)
    {
        A[i+1] = A[i];
        i--;
    }
    A[pos] = item;
    for(a = 0; a < len ; a++)
    {
        printf("%d ",A[a]);
    }
}
//调用
//int array[8] = {-2,5,6,7,9,13,24};
//int len = sizeof(array)/sizeof(array[0]);
//insert(array, len, 8);



//18年第七题
//程序设计
int freqs(char *source, char *destination)
{
    if(NULL == source || NULL == destination)   //初始条件
    {
        return 0;
    }
    int i, len1, len2, j, count = 0;
    /*i作为遍历标志，len1为source长度，len2为目标长度，count计数，j作为判断过程中循环的计数*/
    len1 = (int)strlen(source);
    len2 = (int)strlen(destination);
//    printf("len1 = %d,len2 = %d\n",len1,len2);
    if(len1 < len2 || 0 == len2)    //对比长度，若len2比len1大或len2为0，退出
    {
        return 0;
    }
    for(i = 0; i < len1 - len2 ; i++)
    {
        if(source[i] == destination[0])
        {
            count++;
            for(j = 1; j < len2 ; j++)
            {
                if(source[i+j] != destination[j])
                {
                    count--;
                    break;
                }
            }
        }
    }
    return count;
}
//调用
//    char a[] = "akjkdjfjkjjkj";
//    char b[] = "kj";
//    int num = freqs(a, b);
//    printf("there are %d '%s' totally in the first sentence.\n",num,b);


//17年第七题
long long POWER(int n, int a)
{
    
    int i;
    long long result = 1;
    for(i = 1; i <= a; i++)
    {
        result *= n;
    }
    return result;
}

int psum(int n, int a)
{
    if(!(a > 0 && n > 0))   //边界条件
        {
            return 0;
        }
    int base, sum = 0;
    for(base = 1; base <= n; base++)
    {
        sum += POWER(base, a);
    }
    return sum;
}
//调用
//    int a = 4, b = 8;
//    int n = psum(a, b);
//    printf("result = %d\n",n);






////17年第四题：链表删除重复元素
////创建链表

LinkList CreateLink(void)
{
    //p每次申请新结点并存放数据
    //r用来连接list和p
    //a存放数据，n记录长度
    LinkList p, r = NULL, list = NULL;
    int i, a, n;
    //获取链表长度
    printf("how many node?\n");
    scanf("%d",&n);
    printf("input data:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a);
        p = (LinkList)malloc(sizeof(struct node));
        p->data = a;
        p->link = NULL;
        if (list == NULL)
        {
            list = p;    //不带头指针
        }
        else
        {
            r->link = p;
        }
        r = p;
    }
    return list;
}

//打印链表
void PrintLink(LinkList list)
{
    if(NULL == list)
    {
        return;
    }
    LinkList p = list;
    while(NULL != p)
    {
        printf("%d ",p->data);
        p = p->link;
    }
}

//实现函数
void DELE_SURPLUS(LinkList list)
{
    LinkList pre = list;
    LinkList p = list->link;
    LinkList q = list;
    int flag = 0;
    while (p != NULL)
    {
        q = list;
        while (q != p)
        {
            if (q->data == p->data)
            {
                pre->link = p->link;
                free(p);
                flag = 1;
                break;
            }
            else
            {
                q = q->link;
            }
        }
        if (flag)
        {
            p = pre->link;
            flag = 0;
        }
        else
        {
            pre = p;
            p = p->link;
        }
    }
}


//17年第八题——程序设计
/*
 题目大意：
 键盘输入字符串（包含字母与数字，如：abc123de45f6），提取出数字并递减次序排序，输出
 步骤：
 1.从键盘获取字符串 ，选出其中的数字
 2.编写stoi函数，将字符串类型转换成整型
 3.将获得的数字放入数组
 4.编写output函数，给数组排序（从大到小），输出
 */
////////////////方法1:用队列存储

void NUM_IN_SORT1(void)
{
    char str[105];      //strc
    char buf[50][50] = {'\0'};   //二维数组，存放数字字注意初始化'\0'，野指针很危险
    int row = 0, col = 0, num[100] = {0}, i = 0, flag = 0, len;
    printf("input something no longer than 100 characters:\n");
    gets(str);
    
    
    while(str[i])
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            buf[row][col] = str[i];
            col++;
            flag = 1;
        }
        else if(1 == flag)
        {
            col = 0;
            row++;
            flag = 0;
        }
        i++;
    }
   
    for(i = 0; i <= row; i++)
    {
        len = (int)strlen(buf[i]);
        num[i] = stoi(buf[i], len);
    }
    
    aroutput(num, row+1);
}

//stoi函数，将数字字符串转换为整数
int stoi(char *ch, int n)
{
    int i, num = 0;
    for(i = 0; i < n; i++)
    {
        if(!(ch[i] >= '0' && ch[i] <= '9'))
        {
            printf("not pure number string!\n");
            return 0;
        }
        num = num * 10 + (ch[i] - 48);
    }
    return num;
}

//排序
void aroutput(int k[], int n)     //这里用的shell排序
{
    int gap, i, j;
    int temp;   //datatype
    for(gap = n/2; gap > 0; gap /= 2)
    {
        for(i = gap; i < n; i++)
        {
            temp = k[i];
            for(j = i - gap; j >= 0 && k[j] > temp; j -= gap)
            {
                k[j + gap] = k[j];
            }
            k[j + gap] = temp;
        }
    }
    for(i = 0; i < n; i++)
    {
        printf("%d ",k[i]);
    }
}





//14年第八题
/*
 功能：计算并输出某子串substr在主串str中出现的次数。
 要求：
 1.要求子串在主串中出现次数的过程编写为一个独立的函数：int STRCOUNT(char *str, char *substr)
 2.若主串中str中未出现子串substr，则函数返回0.
 3.在主函数中通过键盘输入方式给str与substr赋值，并且所有涉及到字符串的操作均通过指针完成。
 */
//int STRCOUNT(char *str, char *substr)
//{
//    int num = 0;
//
//
//    return num;
//}
//






//文件
/*
 $$文件的输入输出——日程列表
 《c程序设计导引——尹宝林》p200
 
 */
int is_empty_line(char *s)
{
    for( ; *s != '\0'; s++)
    {
        if (!isspace(*s))
        {
            return 0;
        }
    }
    return 1;
}

void SCHEDULE(void)
{
    FILE *fp = NULL;
    int m, d;
    char buf[105], s[105];
    
    fp = fopen(F_NAME, "a");
    if( NULL == fp)
    {
        sprintf(buf, "can't open file %s",F_NAME);
        perror(buf);
        return;
    }
    while(1)
    {
        fgets(buf, 105, stdin);
        if (is_empty_line(buf))
        {
            fclose(fp);
            return;
        }
        if (sscanf(buf, "%d.%d %s", &m, &d, s) != 3)
        {
            fputs("Input format: <month>.<day> <message>\n", stderr);
            continue;
        }
        fputs(buf, fp);
    }
}






/*
 请编写一 C语言函数get_weekday，该函数用于计算某一天是星期几。函数接收三个整型参数，
 分别表示年(year)、月(month)与日(day);并返回一个整数表示星期几，用 0、1-6 分 别表示星期日、星期一到星期六。
 说明:已知公元元年(即 1 年)1 月 1 日是星期一。为了简化问题，只考虑公元后的日期， 即年大于等于 1.
 */

int get_weekday(int year, int month, int day)
{
    if(month < 1 || month > 12 || day < 0 || day > 31)
    {
        perror("wrong input!");
        return 0;
    }
    
    int is_leapyear(int year);      //判断闰年
    int judge_month(int month, int n);  //用来判断当年过完了几个月，在当前月之前的返回1，否则返回0
    int weekday = 0;
    int yearday = ((year - 1)/4) * (365 * 4 + 1) + ((year - 1) % 4) * 365 - ((year - 1) / 100 - (year - 1) / 400);      //这里复杂一点，计算当前年之前已经过完所有年的天数
    int monthday = 31 * (judge_month(month, 1) + judge_month(month, 3) + judge_month(month, 5) + judge_month(month, 7) + judge_month(month, 8) + judge_month(month, 10) + judge_month(month, 12)) + 28 * judge_month(month, 2) + 30 *( judge_month(month, 4) + judge_month(month, 6) + judge_month(month, 9) + judge_month(month, 11)  );
    if(is_leapyear(year))       //闰年2月再加一天
    {
        monthday += 1;
    }
    printf("yearday = %d\nmonthday = %d\n",yearday,monthday);
    int total = yearday + monthday + day;
    weekday = total % 7;
    
    return weekday;
    
}

int judge_month(int month, int n)   //判断month是否大于n
{
    if(month > n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_leapyear(int year)
{
    if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}










