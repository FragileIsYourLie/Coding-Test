/*
题目描述
给定一个链表，请先将链表中的所有奇数节点放在前面，偶数节点放在后面。
随后，对链表中第 l个位置到第 r个位置之间的节点进行反转操作。

输入格式
第一行输入一个整数 n，表示链表的长度。
第二行输入 n 个整数，表示链表中的节点值。
第三行输入两个整数 l 和 r，表示需要反转的区间。

输出格式
输出调整后的链表，节点值之间用空格分隔。

输入样例 
6
1 2 3 4 5 6
2 5

输出样例
1 4 2 5 3 6 
*/
#include <iostream>
using namespace std;
const int N=100010;
int a[N];

struct ListNode{
    int val;
    ListNode *next;
};
int main(){
    int n,l,r;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    cin >> l >> r;
    //尾插法建立单链表
    ListNode* p1 = new ListNode{0, nullptr};
    ListNode* p2 = new ListNode{0, nullptr};
    ListNode *h1 = p1;
    ListNode *h2 = p2;
    ListNode *head = p1;
    for (int i=0;i<n;i++){
        ListNode* p = new ListNode{a[i], nullptr};
        //表示奇数节点
        if(a[i]%2!=0){
            p1->next = p;
            p1 = p1->next;
        }
        else{
            p2->next = p;
            p2 = p2->next;
        }
    }
    p1->next = h2->next;
    //找到p1链的第l-1个节点：h1
    ListNode *prev,*curr,*next,*tmp;
    for (int i=0;i<l-1;i++){
        h1 = h1->next;
    }
    prev = h1->next;
    curr = h1->next->next;
    for (int j=0;j<r-l;j++){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    tmp = h1->next;
    tmp->next = curr;
    h1 ->next = prev;

    head = head->next;
    while (head){
        cout<< head->val<<" ";
        head = head->next;
    }
}
