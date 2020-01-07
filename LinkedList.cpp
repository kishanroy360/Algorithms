#include<iostream>
using namespace std;

class Node{
private:
    int data;
    Node* next;
public:
    Node (int d){
        data=d;
        next=NULL;
    }
friend class LinkedList;
};

class LinkedList{
private:
    Node* head;
public:
    LinkedList(){
        head=NULL;
    }
    void InsertAtBegin(int d){
        Node* n=new Node(d);
        n->next=head;
        head=n;
    }
   void InsertAtEnd(int d){
        if (head==NULL){
            InsertAtBegin(d);
            return;
        }
        Node* n=new Node(d);
        Node* temp=head;
        while (temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=n;
    }
    void InsertAtK(int d, int k){
        if (head==NULL || k==1){
            InsertAtBegin(d);
            return;
        }
        int cnt=1;
        Node* temp=head;
        while (temp->next!=NULL && cnt<k-1){
            cnt++;
            temp=temp->next;
        }
        Node* n=new Node(d);
        n->next=temp->next;
        temp->next=n;
    }
    void DeleteAtBegin(){
      if (head==NULL) return;
        Node* temp=head;
        head=head->next;
        delete temp;
    }

    void DeleteAtEnd(){
        if (head==NULL) return;
        if (head->next==NULL){
            DeleteAtBegin();
            return;
        }
        Node* temp=head;
        while (temp->next->next!=NULL){
            temp=temp->next;
        }
        delete temp->next;
        temp->next=NULL;
    }
    void DeleteAtK(int k){

    }
    int Length(){

    }

    void Print(){
        Node* temp=head;
        while (temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    void Print(ostream &o){
        Node* temp=head;
        while (temp!=NULL){
            o<<temp->data<<" ";
            temp=temp->next;
        }
        o<<endl;
    }
private:
    bool Search(Node* hd, int k){
        /// this is a internal function so it is private
        if (hd==NULL) return false;
        if (hd->data==k) return true;
        return Search(hd->next,k);
    }

public:
    bool Search(int k){
        ///public interface
        return Search(head,k);
    }

    Node* ReverseDataRec(Node * hd){
        if (hd==NULL) return head;
        Node *ans=ReverseDataRec(hd->next);
        if( ans==NULL) return NULL;
        if (ans==hd || hd->next==ans) return NULL;
        swap(ans->data,hd->data);
        return ans->next;
    }

    void ReverseDataRec(){
        ReverseDataRec(head);
    }

    Node * ReverseNodeRec(Node* hd){
        if (hd==NULL||hd->next==NULL) return hd;
        Node * ans=ReverseNodeRec(hd->next);
        hd->next->next=hd;
        if (hd==head) hd->next=NULL;
        return ans;
    }

    Node * ReverseNodeRec(Node* hd, Node* prev){
        if (hd==NULL) return NULL;
        if (hd->next==NULL){
            hd->next=prev;
            return hd;
        }
        Node* ans=ReverseNodeRec(hd->next,hd);
        hd->next=prev;
        return ans;
    }

    void ReverseNodeRec(){
        ///head=ReverseNodeRec(head);
        head = ReverseNodeRec(head,NULL);
    }

    void PrintLastKth(int k){
        Node* temp=head;
        int cnt=1;
        while (cnt<=k){
            temp=temp->next;
            if (temp==NULL) return;
            cnt++;
        }
        Node* temp1=head;
        while (temp!=NULL){
            temp=temp->next;
            temp1=temp1->next;
        }
        cout<<temp1->data<<endl;
    }
    void ReverseNodeIt(){
        if (head==NULL || head->next==NULL) return;
        Node* pre=NULL, *cur=head, *nxt;
        while (cur!=NULL){
            nxt=cur->next;
            cur->next=pre;
            pre=cur;
            cur=nxt;
        }
        head=pre;
    }

    Node* SelectionSort(Node* hd){
        if (hd==NULL || hd->next==NULL) return hd;
        Node* smallest=hd, *smallestprev;
        Node* prev=hd, *cur=hd->next;
        while (cur!=NULL){
            if (cur->data<smallest->data){
                smallest=cur;
                smallestprev=prev;
            }
            prev=cur;
            cur=cur->next;
        }
        if (smallest!=hd){
            smallestprev->next=smallest->next;
            smallest->next=hd;
        }
        smallest->next=SelectionSort(smallest->next);
        return smallest;
    }

    void SelectionSort(){
        head=SelectionSort(head);
    }

    void OddEvenAlign(){
        Node * temp=head;
        Node* odd=NULL, *even=NULL, *oddTail=NULL, *evenTail=NULL;
        while (temp!=NULL){
            if (temp->data%2==0){
                if (even==NULL){
                    even=temp;
                    evenTail=temp;
                } else {
                    evenTail->next=temp;
                    evenTail=temp;
                }
            } else {
                if (odd==NULL){
                    odd=temp;
                    oddTail=temp;
                } else {
                    oddTail->next=temp;
                    oddTail=temp;
                }
            }
            temp=temp->next;
        }
        if (odd!=NULL && even!=NULL){
            head=odd;
            oddTail->next=even;
            evenTail->next=NULL;
        }
    }

    Node* Merge (Node*FL, Node* SL){
        if (FL==NULL) return SL;
        if (SL==NULL) return FL;

        if (FL->data<SL->data){
            FL->next=Merge(FL->next,SL);
            return FL;
        } else {
            SL->next=Merge(FL,SL->next);
            return SL;
        }
    }

    Node* SplitinHalf(Node* hd){
        if (hd==NULL||hd->next==NULL) return NULL;
        Node* s=hd, *f=hd;
        while (f->next!=NULL && f->next->next!=NULL){
            s=s->next;
            f=f->next->next;
        }
        Node* t=s->next;
        s->next=NULL;
        return t;
    }

    Node * MergeSort(Node* hd){
        if (hd==NULL||hd->next==NULL) return hd;
        Node* FL=hd;
        Node* SL=SplitinHalf(hd);
        FL=MergeSort(FL);
        SL=MergeSort(SL);
        return Merge(FL,SL);
    }

    void MergeSort(){
        head=MergeSort(head);
    }

    Node* BubbleSort(Node* hd){
        if (hd==NULL || hd->next==NULL) return hd;
        Node *cur=hd,*prev=NULL,*nxt=cur->next;
        bool IsSorted=true;
        while (nxt!=NULL){
            if (cur->data>nxt->data){
                cur->next=nxt->next;
                nxt->next=cur;
                if (prev==NULL) hd=nxt; else prev->next=nxt;
                prev=nxt;
                nxt=cur->next;
                IsSorted=false;
            } else{
                prev=cur;
                cur=nxt;
                nxt=cur->next;
            }
        }
        if (!IsSorted) hd=BubbleSort(hd);
        return hd;
    }

    void BubbleSort(){
        head=BubbleSort(head);
    }
};

ostream &operator<<(ostream &o, LinkedList &LL){
    LL.Print(o);
    return o;
}

int main(){
    LinkedList LL;
    LL.InsertAtBegin(1);
    LL.InsertAtBegin(2);
    LL.InsertAtBegin(3);
    LL.InsertAtBegin(4);
    LL.InsertAtEnd(5);
    LL.InsertAtK(6,3);
    LL.InsertAtK(7,10);
    LL.InsertAtBegin(8);
    cout<<LL;
    /*LL.DeleteAtBegin();
    LL.DeleteAtEnd();
    cout<<LL;*/
    cout<<LL.Search(7)<<" "<<LL.Search(10)<<endl;
    ///LL.ReverseDataRec();
    ///LL.ReverseNodeRec();
    LL.ReverseNodeIt();
    cout<<LL;
    LL.PrintLastKth(4);
    LL.SelectionSort();
    cout<<LL;
    LL.OddEvenAlign();
    cout<<LL;
    ///LL.MergeSort();
    LL.BubbleSort();
    cout<<LL;

}
