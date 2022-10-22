/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        
        if(head==NULL)
            return head;
        
        Node* p=NULL,*q=NULL;
        
        stack<Node*>st;
        st.push(head);
        
        while(!st.empty() || p!=NULL){
            if(p==NULL){
                while(!st.empty() && st.top()==NULL)
                    st.pop();
                if(st.empty())break;
                p=st.top();
                st.pop();
                if(q==NULL)
                    q=p;
                else{
                    q->next=p;
                    p->prev=q;
                }
            }
            if(p->child){
                st.push(p->next);
                p->next=p->child;
                p->child->prev=p;
                p->child=NULL;
            }
            q=p;
            p=p->next;
        }
        q->next=NULL;
        return head;
    }
};
