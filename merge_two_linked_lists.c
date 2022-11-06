#include<stdio.h>
#include<stdlib.h>
struct ListNode{
        int val;
        struct node *next;
}*newnode,*temp;
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if (NULL == list1) {
        return list2;
    }
    
    if (NULL == list2) {
        return list1;
    }
struct ListNode* head=NULL;
struct ListNode* tail=NULL;
while(list1!=NULL && list2!=NULL){
    struct ListNode* res=(struct ListNode*)malloc(sizeof(struct ListNode));
    res->next=NULL;
    if(list1->val<list2->val){
        res->val=list1->val;
        if(head==NULL){
            head=res;
            tail=res;
        }
        else
        {
            tail->next=res;
            tail=res;
        }
        list1=list1->next;
    }
    else
    {
        res->val=list2->val;
        if(head==NULL){
            head=res;
            tail=res;
        }
        else
        {
            tail->next=res;
            tail=res;
        }
    list2=list2->next;
    }
}
if(list1!=NULL){
    while(list1!=NULL){
        struct ListNode* res=(struct ListNode*)malloc(sizeof(struct ListNode));
        res->next=NULL;
        res->val=list1->val;
        tail->next=res;
        tail=res;
        list1=list1->next;
        
    }
}
if(list2!=NULL){
    while(list2!=NULL){
        struct ListNode* res=(struct ListNode*)malloc(sizeof(struct ListNode));
    res->next=NULL;
        res->val=list2->val; 
            tail->next=res;
            tail=res;
        list2=list2->next;
        
    }
}
display(head);
    
return head;

}

struct ListNode* create( struct ListNode* head,struct ListNode* tail)
{
        int valu;
        char ch;
        do{
                newnode=(struct ListNode *)malloc(sizeof(struct ListNode));
                printf("enter the value: ");
                scanf("%d",&valu);
                newnode->val=valu;
                newnode->next=NULL;
                if(head==NULL)
                {
                        head=newnode;
                        tail=newnode;
                }
                else
                {
                        tail->next=newnode;
                        tail=newnode;

                }
                printf("Do you want to insert another element? if yes press y else n: ");
                fflush(stdin);
                scanf(" %c",&ch);
        }while(ch=='y');
    return head;
}

void display(struct ListNode* head)
{
        temp=head;
        while(temp!=NULL)
        {
                printf("%d ",temp->val);
                temp=temp->next;
        }
}
 struct ListNode* head1=NULL;
    struct ListNode* head2=NULL;
    struct ListNode* tail2=NULL;
    struct ListNode* tail1=NULL;
    struct ListNode* res=NULL;
void main()
{
   
    head1=create(head1,tail1);
    head2=create(head2,tail2);
    res=mergeTwoLists(head1,head2);
    
    
}
