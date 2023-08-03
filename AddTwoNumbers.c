#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode {
     int val;
     struct ListNode *next;
 }ListNode;
 
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    ListNode * result = (ListNode*) malloc(sizeof( ListNode));
    result->val = 0;
    ListNode * carry = NULL;
    ListNode * head = result;
    ListNode * prev;
    while(l1 != NULL || l2 != NULL){
        carry = ( ListNode*) malloc(sizeof( ListNode));
        carry->next = NULL;
        if(l1 == NULL){
            result->val += l2->val;
        }else if(l2 == NULL){
            result->val += l1->val;
        }
        else{
            result->val += l1->val + l2->val;
        }            
        if(result->val >= 10){
            result->val -= 10;
            carry->val = 1;
        }else{
            carry->val = 0;
        }
        result->next = carry;
        prev = result;
        result = result->next;
        
        
        if(l1 != NULL)
            l1 = l1->next;
        if(l2 != NULL)
            l2 = l2->next; 
    }
    if(result->val == 0){
        prev->next = NULL;
        free(result);
    }
    return head;
}


ListNode * CreateList(ListNode * list, int array[], int size){
    ListNode * head = list;
    int i;
    for(i = 0; i < size; i++){
        ListNode * node = (ListNode *) malloc(sizeof(ListNode));
        node->val = array[i];
        node->next = NULL;
        if(i == 0){
            head = node;
            list = head;
        }       
        else{         
            head->next = node;
            head = head->next;
        }
    }
    return list;
}

int main(){
    ListNode * l1 = NULL, * l2 = NULL;
    int arr[2] = {8,8};
    int arr2[3] = {3,5,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    l1 = CreateList(l1, arr, size);
    l2 = CreateList(l2, arr2, 3);
    /*while (l1 != NULL)
    {
        printf("%d -> ",l1->val);
        l1 = l1->next;
    }
    printf("\n");
    while (l2 != NULL)
    {
        printf("%d -> ",l2->val);
        l2 = l2->next;
    }*/

    ListNode * res;
    res = addTwoNumbers(l1, l2);
    while (res != NULL)
    {
        printf("%d -> ",res->val);
        res = res->next;
    }
}