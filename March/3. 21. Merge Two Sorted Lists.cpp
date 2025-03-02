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
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {

        ListNode *first = list1;
        ListNode *second = list2;
        ListNode *ans = NULL;
        ListNode *temp;

        while (first != NULL and second != NULL)
        {

            if (ans == NULL)
            {
                ListNode *newNode;

                if (first->val <= second->val)
                {
                    newNode = new ListNode(first->val);
                    first = first->next;
                }
                else if (second != NULL)
                {
                    newNode = new ListNode(second->val);
                    second = second->next;
                }
                ans = newNode;
                temp = ans;
                continue;
            }

            if (first->val <= second->val)
            {
                ListNode *newNode = new ListNode(first->val);
                temp->next = newNode;
                temp = temp->next;
                first = first->next;
            }
            else if (second->val < first->val)
            {
                ListNode *newNode = new ListNode(second->val);
                temp->next = newNode;
                temp = temp->next;
                second = second->next;
            }
            else
            {
                ListNode *newNode = new ListNode(first->val);
                temp->next = newNode;
                temp = temp->next;
                first = first->next;

                newNode = new ListNode(second->val);
                temp->next = newNode;
                temp = temp->next;
                second = second->next;
            }
        }

        while (first != NULL)
        {
            ListNode *newNode = new ListNode(first->val);
            if (ans == NULL)
            {
                ans = newNode;
                temp = ans;
            }
            else
            {
                temp->next = newNode;
                temp = temp->next;
            }

            first = first->next;
        }

        while (second != NULL)
        {
            ListNode *newNode = new ListNode(second->val);
            if (ans == NULL)
            {
                ans = newNode;
                temp = ans;
            }
            else
            {
                temp->next = newNode;
                temp = temp->next;
            }

            second = second->next;
        }

        return ans;
    }
};