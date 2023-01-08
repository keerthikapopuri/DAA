
#include <iostream>

using namespace std;
struct ListNode {
      int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  }*newnode,*temp;
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
        if(list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;
        
        struct ListNode * ptr = list1;
        if(list1 -> val > list2 -> val)
        {
            ptr = list2;
            list2 = list2 -> next;
        }
        else
        {
            list1 = list1 -> next;
        }
        struct ListNode *curr = ptr;
        while(list1!=NULL &&  list2!=NULL)
        {
            if(list1 -> val < list2 -> val){
                curr->next = list1;
                list1 = list1 -> next;
            }
            else{
                curr->next = list2;
                list2 = list2 -> next;
            }
            curr = curr -> next;
                
        }
        if(list1==NULL)
            curr -> next = list2;
        else
            curr -> next = list1;
            
        return ptr;
       
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
int main()
{
   
    head1=create(head1,tail1);
    head2=create(head2,tail2);
    res=mergeTwoLists(head1,head2);
    display(res);
    return 0;
    
}
