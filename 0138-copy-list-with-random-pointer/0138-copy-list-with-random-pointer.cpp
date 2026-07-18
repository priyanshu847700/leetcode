/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*> m;
    Node* copyRandomList(Node* head) {

        if(head == NULL) return head;
        
        Node *newhead=new Node(head->val);
        Node *oldtemp=head->next;
        Node *newtemp=newhead;

        m[head]=newhead;

        while(oldtemp!=NULL){
            Node *copynode =new Node(oldtemp->val);

            m[oldtemp]=copynode;

            newtemp->next=copynode;
            //updation!!
            oldtemp=oldtemp->next;
            newtemp=newtemp->next;
        }

        oldtemp=head; 
        newtemp=newhead;
        while(oldtemp!=NULL){
            if(oldtemp->random!=NULL){
                newtemp->random=m[oldtemp->random];
            }
            else{
                newtemp->random=NULL;
            }
            oldtemp=oldtemp->next;
            newtemp=newtemp->next;
        }

        return newhead;
    }
};