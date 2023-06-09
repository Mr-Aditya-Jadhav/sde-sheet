//https://www.codingninjas.com/codestudio/problems/palindrome-linked-list_8230717?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

// *****************************************************************/

// LinkedListNode<int>* reverse(LinkedListNode<int>* ptr){
//     LinkedListNode<int>* pre = NULL;
//     LinkedListNode<int>* nex = NULL;

//     while(ptr != NULL){
//         nex = ptr->next;
//         ptr->next = pre;
//         pre = ptr;
//         ptr = nex;
//     }

//     return pre;
    
// }

// bool isPalindrome(LinkedListNode<int>* head) {
//   // Write your code here.
//   if (head == NULL || head->next == NULL) return true;

//   LinkedListNode<int>* slow = head;
//   LinkedListNode<int>* fast = head;
//     while(fast->next->next != NULL && fast->next != NULL){
//         fast = fast->next->next;
//         slow = slow->next;

//     }

//     slow->next = reverse(slow->next);
//     slow = slow->next;

//     LinkedListNode<int>* temp = head;
//     while(slow != NULL){
//         if(slow->data != temp->data) return false;
//         slow = slow->next;
//         temp = temp->next;
//     }

//     return true;
// }

LinkedListNode<int>* reverse(LinkedListNode<int>* ptr) {
    LinkedListNode<int>* pre=NULL;
    LinkedListNode<int>* nex=NULL;
    while(ptr!=NULL) {
        nex = ptr->next;
        ptr->next = pre;
        pre=ptr;
        ptr=nex;
    }
    return pre;
    }

bool isPalindrome(LinkedListNode<int>* head) {
    if(head==NULL||head->next==NULL) return true;
        
    LinkedListNode<int>* slow = head;
    LinkedListNode<int>* fast = head;
        
    while(fast->next!=NULL&&fast->next->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
        
    slow->next = reverse(slow->next);
    slow = slow->next;
    LinkedListNode<int>* dummy = head;
        
    while(slow!=NULL) {
        if(dummy->data != slow->data) return false;
        dummy = dummy->next;
        slow = slow->next;
    }
    return true;
}

