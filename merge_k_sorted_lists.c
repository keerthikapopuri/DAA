23. Merge k Sorted Lists
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include<vector>
using namespace std;
struct ListNode {
      int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  }*newnode,*temp;
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

struct ListNode* mergeTwoSorted(struct ListNode* list1,struct  ListNode* list2) {
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

    
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if(lists.size()==0) return NULL;
        while(lists.size() > 1){
            lists.push_back(mergeTwoSorted(lists[0], lists[1])); // time consuming 
            // erase first 2 heads of lists
            lists.erase(lists.begin()); // time consuming 
            lists.erase(lists.begin());
        }
        return lists[0];
    }
int main()
{
   int n;
   cout<<"enter size";
   cin>>n;
   vector<struct ListNode*>lists;
   for(int i=0;i<n;i++){
       struct ListNode* head1=NULL;
        struct ListNode* tail1=NULL;
        head1=create(head1,tail1);
    lists.push_back(head1);
   }

    display(mergeKLists(lists));
    return 0;
    
}
