//
//  Header.h
//  program design
//
//  Created by duoguang xu on 2020/11/3.
//

#ifndef Header_h
#define Header_h

#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define F_NAME "/Users/duoguangxu/Documents/reminder.txt"

//18年第四题——算法设计
//BIN_FIND函数查找item在顺序表A[]中item的位置，若没有item，则找到最接近且比item小的元素的位置
int BIN_FIND(int key[], int len, int target);
void insert(int A[], int len, int item);

//18年第七题
//程序设计
int freqs(char *source, char *destination);

//17年第七题
long long POWER(int n, int a);




////17年第四题：链表删除重复元素
////创建链表
typedef struct node{
    int data;
    struct node *link;
}*LinkList;

LinkList CreateLink(void);
//打印链表
void PrintLink(LinkList list);
//实现函数
void DELE_SURPLUS(LinkList list);


//17年第八题
int stoi(char *ch, int n);
void aroutput(int k[], int n);

void NUM_IN_SORT1(void);


//14年第八题
int STRCOUNT(char *str, char *substr);



//文件
int is_empty_line(char *s);

void SCHEDULE(void);



#endif /* Header_h */






