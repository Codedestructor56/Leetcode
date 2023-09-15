#include <iostream>
#include <stack>
#include <vector>
#include <numeric>
#include <cstring>

using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* n) : val(x), next(n) {}
};

void printList(ListNode* n) {
    while (n != nullptr) {
        cout << " " << n->val << endl;
        n = n->next;
    }
}
ListNode* sort_and_merge(ListNode* n1, ListNode* n2){
    ListNode* dummy=new ListNode(0);
    ListNode* merged=dummy;
    while (n1 != nullptr && n2 != nullptr) {
        if (n1->val <= n2->val) {
            merged->next = n1;
            n1 = n1->next;
        } else {
            merged->next = n2;
            n2 = n2->next;
        }
        merged = merged->next;
    }
    if (n1 != nullptr) {
        merged->next = n1;
    } else if (n2 != nullptr) {
        merged->next = n2;
    }

    ListNode* result=dummy->next;
    delete dummy;
    return result;
}
ListNode* mergeKLists(vector<ListNode*>& lists){
    int splits=lists.size()/2;
    ListNode* last=new ListNode();
    ListNode* resultNode=new ListNode(0);
    if(lists.size()%2!=0){
        last=lists.back();
    }
    while(lists.size()>1){
        for(int i=0;i<splits;i++){
            vector<ListNode*> sub(lists.begin()+(2*i),lists.begin()+(2*(i+1)));
            lists[i]=sort_and_merge(sub[0],sub[1]);    
        }
        lists.resize(splits);
        splits=lists.size()/2;
    }
    if(last->val!=0){
        lists.push_back(last);
        resultNode=sort_and_merge(lists[0],lists[1]);
        return resultNode;
    }
    return lists[0];
}

int main() {
    ListNode* n1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode* n2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* n3 = new ListNode(2, new ListNode(6));
    ListNode* n4 = new ListNode(4, new ListNode(7, new ListNode(8)));
    ListNode* n5 = new ListNode();
    vector<ListNode*> n_all=vector{n1,n3,n2,n4};
    printList(mergeKLists(n_all));
    //printList(sort_and_merge(n1,n2));
    
    delete n1;
    delete n2;
    delete n3;
    delete n4;

    return 0;
}
