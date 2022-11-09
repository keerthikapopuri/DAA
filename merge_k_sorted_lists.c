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
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){

    if(list1 == NULL && list2 == NULL){
        return NULL;
    }
    
    if(list1 == NULL){
        return list2;
    }
    
    if(list2 == NULL){
        return list1;
    }
    
  struct ListNode* main=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* temp1=list1;
    struct ListNode* temp2=list2;
    struct ListNode* res=main;
    if(temp1->val>temp2->val)
    {
        main->val=temp2->val;
        temp2=temp2->next;
}
    else
    {
main->val=temp1->val;
    temp1=temp1->next;}
    main->next=NULL;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->val>temp2->val){
            res->next=temp2;
            res=temp2;
            temp2=temp2->next;
        }
        else
        {
            res->next=temp1;
            res=temp1;
            temp1=temp1->next;
        }
    }
    if(temp1!=NULL){
        while(temp1!=NULL)
        {
              res->next=temp1;
            res=temp1;
            temp1=temp1->next;  
        }
    }
    if(temp2!=NULL){
        while(temp2!=NULL)
        {
              res->next=temp2;
            res=temp2;
            temp2=temp2->next;  
        }
    }
    return main;
}


struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if (listsSize == 0) return NULL;
	if (listsSize == 1) return lists[0];
	struct ListNode* result = NULL;
	for (int i = 0; i < listsSize; i++)
		result = mergeTwoLists(result, lists[i]);
	return result;

}
