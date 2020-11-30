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
        monthday += judge_month(month, 2);
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





/*
 所谓变位词是指把某个单词的字母的位置(顺序)加以改换所形成的一个新词。例如:silent 就是 listen 的一个变位词，integral 也是 triangle 的一个变位词。
 请编写一个C语言程序，用来求解某个单词在一篇文章中的变位词。用户通过键盘输入一个单词和一个文本文件的名称，
 程序按照升序输出在这个文本文件中出现的该单词的所有变位词 (同一个变位词多次出现的，只输出一次);如果没有变位词，则程序输出 NONE。
 说明:
 (1)为了简化问题，假设所有涉及的单词长度均不超过 20 个字母，文本文件中出现的
 都是普通单词，他们通过空格符、制表符或者回车进行分隔，没有数字、标点符号等其他特殊符
 号，且单词个数不超过 100 个。
 (2)变位词不区分大、小写(大、小写字母均被认为是相同的)，即:Silent 也是 listen
 的变位词。相同的单词不是变位词，如 Silent 不是 Silent 的变位词。为了简化问题，可以考虑
 把所有输入的单词都转换为小写，排序输出时也不考虑大、小写问题，全部以小写形式输出。
 */

/*
 思路：
 1.用键位映射文件中每个单词是否和输入的单词相同
 2.相同的单词放入一个数组，按升序排列
 3.小写形式输出
 */


void ANAGRAM(void)
{
    int judge_anagram(char *w1, char*w2);
    
    //输入要查找的词语
    char ch[20];
    printf("input the words:\n");
    scanf("%s",ch);
    
    //读取文件内容到缓冲区
    char filename[] = {"/Users/duoguangxu/Documents/19test.txt"};   //文件位置
    FILE *fp = fopen(filename, "r");
    if(NULL == fp)
    {
        perror("Can't open the file!");
        return;
    }
//    char buff[105];
//    fgets(buff, 105, fp);
    
    //获取文件中的每个单词
    char buff[100][20] = {0};      //假设不超过100个单词，每个单词字母个数不超过20
    int i =0, j = 0, k = 0;
    for(i = 0; i < 100; i++)
    {
        if(fscanf(fp, "%20s",buff[i]) != 1)
        {
            break;
        }
    }
    fclose(fp);
    
    //将buff中的单词全变为小写
    i = 0;
    while(buff[i])
    {
        j = 0;
        while(buff[i][j] != '\0')
        {
            if(buff[i][j] >= 'A' && buff[i][j] <= 'Z')
            {
                buff[i][j] += 32;
            }
            j++;
        }
        i++;
    }
    
    //对每个单词进行比较，如果是变位词，则记录下来
    char record[100][20] ;    //记录结果
    for(j = 0; j < i; j++)
    {
        if(judge_anagram(ch, buff[j]))
        {
            strcpy(record[k],buff[j]);
            k++;
        }
    }
    
    //对记录的单词进行排序
    
    //输出
    if(k > 0)
    {
        printf("the file include %d anagram(s):\n",k);
        for(i = 0; i < k; i++)
        {
            printf("%s\n",record[i]);
        }
    }
    else
    {
        printf("no anagram in this file\n");
    }
}



//判断两个单词是否是变位词
int judge_anagram(char *w1, char*w2)
{
    int i = 0, j = 0, k, map[26] = {0}, arr[20] = {0};
    
    //长度不同，直接pass
    if(strlen(w1) != strlen(w2))
    {
        return 0;
    }
    
    //判断是否两个单词相同，同一个单词不为变位词
    if(strcmp(w1, w2))
    {
        return 0;
    }
    
    //
    while(w1[i])                //获取w1单词中各个字母
    {
        if(w1[i] >= 'A' && w1[i] <= 'Z')
        {
            arr[i] = (w1[i] - 'A');
            i++;
        }
        else
        {
            arr[i] = (w1[i] - 'a');
            i++;
        }
    }
    for(k = 0; k < i; k++)      //映射到字母表
    {
        if(map[arr[k]])
        {
            map[arr[k]]++;
            continue;
        }
        map[arr[k]] = 1;
    }
    while(w2[j])                //w2中每每字母映射在字母表的值减1
    {
        if(w2[j] >= 'A' && w2[j] <= 'Z')
        {
            map[w2[j] - 'A']--;
            j++;
        }
        else
        {
            map[w2[j] - 'a']--;
            j++;
        }
    }
    for(k = 0; k < 26; k++)     //若字母表中有非零健值，表明两个单词不是变位词
    {
        if(map[k] != 0)
        {
            return 0;
        }
    }
    return 1;
}




