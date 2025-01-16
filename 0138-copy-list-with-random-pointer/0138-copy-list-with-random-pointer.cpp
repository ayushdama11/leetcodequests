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
    Node* copyRandomList(Node* head) {
        // step 1 -> creating the deep copy without random pointer
        Node* dummy = new Node(-1);
        Node* temp = head;
        Node* tempC = dummy;
        while(temp) {
            Node* a = new Node(temp->val);
            tempC->next = a;
            temp = temp->next;
            tempC = tempC->next;
        }
        Node* a = head;
        Node* b = dummy->next;
        // making a map of <original,duplicate>
        unordered_map<Node*,Node*> m;
        Node* tempa = a;
        Node* tempb = b;
        while(tempa!=NULL) {
            m[tempa] = tempb;
            tempa = tempa->next;
            tempb = tempb->next;
        }
        for(auto x : m) {
            Node* o = x.first;  // original node
            Node* d = x.second;     // duplicate node
            if(o->random!=NULL) {
                Node* oRandom = o->random;
                Node* dRandom = m[o->random];
                d->random = dRandom;  
            } 
        }
        return b;
    }
};