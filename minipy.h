#define Epsilon 1e-6
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

typedef enum TYPE {
    Int,
    Double,
    Identify,
    String,
    MyList,
    List_element,
    Splite
}TYPE;

typedef struct ListElement
{
    char* cID;//所在的列表名称
    vector<int> place;//元素位置 insert(place.begin(),int)
}ListElement;

typedef struct cList {
    TYPE                type;
    union {
        int             integer;
        double          float_number;
        char*           string_literal;
        struct cList*   new_List;
    };
    struct cList*       next_element;
} cList;

typedef struct stype {
    TYPE        type;
    union {
        int     iValue;
        double  dValue;
        char*   cID;
        char*   string_literal;
        cList*  new_List;
    };
    ListElement sListElement;
    char            str;
} stype;

typedef struct symbol_item {
    char*               cID;            //标识符
    struct stype*        slice_TEMP;        //切片
    struct stype*       stype_items;    //stype指针，指向标识符对应的stype类型变量
    struct symbol_item* next_element;   //链表
} symbol_item;

/*
 * 返回值的含义：
 *  0: 类型不符
 *  1: 运算成功
 * -1: 被除数为零
 */
int stype_Add(stype* lval, stype* rval, stype* result);
int stype_Minus(stype* lval, stype* rval, stype* result);
int stype_Mul(stype* lval, stype* rval, stype* result);
int stype_Div(stype* lval, stype* rval, stype* result);
int stype_Mod(stype* lval, stype* rval, stype* result);

/* 申请内存请使用这个函数！！！ */
void* safe_malloc(int size);

void yyerror (char const *s);

void printList (cList* new_List);
void printAssignExpr(stype* show);

symbol_item* Search_Symbol(char * cID);

void copy_cList(cList* src, cList* dst);
void copy_stype(stype* src, stype* dst);

void free_stype(stype* target);
void free_cList(cList* target);
void free_symbol_item(symbol_item* target);

cList* analysis_ListElement(stype* src);
