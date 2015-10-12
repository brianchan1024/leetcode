#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    // Ac
    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);;
        ListNode* head = res;
        int carry = 0;
        int value = 0;
        while(l1 != NULL && l2 != NULL) {
            //cout << "----" << l1 -> val << " " << l2 -> val << endl;
            value = (l1 -> val + l2 -> val + carry) % 10;
            carry = (l1 -> val + l2 -> val + carry) / 10;
            if(head -> next == NULL) {
                head -> next = new ListNode(value);
                head = head -> next;
            } else {
                head -> val = value;
            }
            
            l1 = l1 -> next;
            l2 = l2 -> next;
            //cout << "***" << head -> val << endl;
            //printList(res);
        }
        
        if(l1 == NULL) {
            while(l2 != NULL) {
                value = (l2 -> val + carry) % 10;
                carry = (l2 -> val + carry) / 10;
                head -> next = new ListNode(value);
                
                l2 = l2 -> next;
                head = head -> next;
            }
        }

        if(l2 == NULL) {
            while(l1 != NULL) {
                value = (l1 -> val + carry) % 10;
                carry = (l1 -> val + carry) / 10;
                head -> next = new ListNode(value);
                
                l1 = l1 -> next;
                head = head -> next;
            }
        }
        cout<<"@@" << carry << endl;
        if(carry == 1) {
            printList(res->next);
            head -> next = new ListNode(1);
            head = head -> next;
        }
        return res -> next;
    }
    
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode* res = new ListNode(0);
        ListNode* head = res;
        int carry = 0;
        while(l1 && l2) {
            head->next = new ListNode((l1->val + l2->val + carry) % 10);
            carry = (l1->val + l2->val + carry) / 10;
            
            l1 = l1->next;
            l2 = l2->next;
            head = head->next;
        }

        while(l1) {
            head->next = new ListNode((l1->val + carry) % 10);
            carry = (l1->val + carry) / 10;
            
            l1 = l1->next;
            head = head->next;
        }

        while(l2) {
            head->next = new ListNode((l2->val + carry) % 10);
            carry = (l2->val + carry) / 10;

            l2 = l2->next;
            head = head->next;
        }

        if(carry == 1) {
            head->next = new ListNode(1);
        }

        return res->next;
    }

    void printList(ListNode *p) {
        ListNode *idx = p;
        cout << "#";
        while(idx != NULL) {
            cout << idx -> val << " ";
            idx = idx -> next;
        }
        cout << endl;
    }
};

int main()
{
    ListNode *a3 = new ListNode(5);
    ListNode *a2 = new ListNode(4);
    a2 -> next = a3;
    ListNode *a1 = new ListNode(2);
    a1 -> next = a2;
 
    ListNode *b3 = new ListNode(4);
    ListNode *b2 = new ListNode(6);
    b2 -> next = b3;
    ListNode *b1 = new ListNode(5);
    b1 -> next = b2;
    
    Solution so = Solution();
    so.printList(a1);
    so.printList(a2);

    ListNode* res = so.addTwoNumbers(a1, b1);
    so.printList(res);
    
    return 0;
}
