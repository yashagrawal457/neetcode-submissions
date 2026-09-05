/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* temp = NULL;
        if (list1 == NULL && list2 == NULL){
            return NULL;
        }
        while(list1 != NULL && list2 != NULL){
            if (list1->val <= list2->val){
                if (temp == NULL){
                    head->val = list1->val;
                    temp = head;
                }else{
                    temp->next = new ListNode(list1->val);
                    temp = temp->next;
                }
                list1 = list1->next;
            }else {
                if (temp == NULL){
                    head->val = list2->val;
                    temp = head;
                }else{
                    temp->next = new ListNode(list2->val);
                    temp = temp->next;
                }
                list2 = list2->next;
            }
        }
        while(list1 != NULL){
            if (temp == NULL){
                head->val = list1->val;
                temp = head;
                list1 = list1->next;
            } else {
                temp->next = new ListNode(list1->val);
                list1 = list1->next;
                temp = temp->next;  
            }
            
        }
        while(list2 != NULL){
            if (temp == NULL){
                head->val = list2->val;
                temp = head;
                list2 = list2->next;
            } else {
                temp->next = new ListNode(list2->val);
                list2 = list2->next;
                temp = temp->next;  
            }
            
        }

        return head;
    }
};
