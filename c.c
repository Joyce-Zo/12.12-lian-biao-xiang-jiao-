#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

// 暴力求解
struct ListNode* getIntersectionNode1(struct ListNode* headA, struct ListNode* headB) {
    struct ListNode* Lb = headB;
    while (headA && headB)
    {
        if(headA != headB)
            headB = headB->next;
        if (headB == NULL)
        {
            headA = headA->next;
            headB = Lb;
        }
        if (headA == headB)
            return headA;
    }
    return NULL;
}

// 老师解法
struct ListNode* getIntersectionNode2(struct ListNode* headA, struct ListNode* headB) {
    int la = 0, lb = 0;
    struct ListNode* LA = headA;
    struct ListNode* LB = headB;

    while (LA != 0)
    {
        LA = LA->next;
        la++;
    }
    while (LB != 0)
    {
        LB = LB->next;
        lb++;
    }
    if (LA != LB)
    {
        return NULL;
    }
    struct ListNode* longlist = headA;
    struct ListNode* shortlist = headB;
    if (la < lb)
    {
        longlist = headB;
        shortlist = headA;
    }
    int gap = abs(la - lb);
    while (gap--)
    {
        longlist = longlist->next;
    }

    while (longlist != shortlist)
    {
        longlist = longlist->next;
        shortlist = shortlist->next;
    }
    return longlist;
}

// 我的原版
struct ListNode* getIntersectionNode3(struct ListNode* headA, struct ListNode* headB) {
    int la = 1, lb = 1;
    struct ListNode* LA = headA;
    struct ListNode* LB = headB;
    while (LA != 0)
    {
        LA = LA->next;
        la++;
    }
    while (LB != 0)
    {
        LB = LB->next;
        lb++;
    }
    if (LA != LB)
    {
        return NULL;
    }

    while (la != lb)
    {
        if (la > lb)
        {
            la--;
            headA = headA->next;
        }
        else 
        {
            lb--;
            headB = headB->next;
        }
    }

    while (headA != headB)
    {
        headA = headA->next;
        headB = headB->next;
    }
    return headA;
}


int main()
{
    //  自己创建链表
    struct ListNode* newnode1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* newnode2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* newnode3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* newnode4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* newnode5 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* newnode6 = (struct ListNode*)malloc(sizeof(struct ListNode));

    struct ListNode* newnode11 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* newnode22 = (struct ListNode*)malloc(sizeof(struct ListNode));
  
    //  给链表赋值
    newnode1->val = 1; newnode1->next = newnode2;
    newnode2->val = 2; newnode2->next = newnode3;
    newnode3->val = 3; newnode3->next = newnode4;
    newnode4->val = 4; newnode4->next = newnode5;
    newnode4->val = 5; newnode5->next = newnode6;
    newnode5->val = 6; newnode6->next = NULL;

    newnode11->val = 11; newnode11->next = newnode22;
    newnode22->val = 22; newnode22->next = newnode4;
    newnode4->val = 4; newnode4->next = newnode5;
    newnode5->val = 5; newnode5->next = newnode6;
    newnode6->val = 6; newnode6->next = NULL;
    
    //  调用链表函数
    struct ListNode* head = getIntersectionNode3(newnode1,newnode11);
    return 0;
}