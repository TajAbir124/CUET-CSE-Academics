#include <bits/stdc++.h>
using namespace std;
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr);
#define gcd(a,b) __gcd(a,b)
#define sqr(a) ((a) * (a))
#define endl "\n"             
#define pb push_back
typedef long long ll;
#define MOD 1000000007
#define all(x) x.begin(),x.end()
#define yes cout << "YES" <<endl
#define no cout <<"NO" <<endl

class Node{
  public:
    int data;
    Node* next;
};
class DNode{
  public:
    DNode* prev;
    int data;
    DNode* next;
};

/*..............................................Circular doubly list.................................*/
class Circular_doubly{
  private:
    DNode* head;
  public:
    Circular_doubly(){
      head = NULL;
    }
    void create_linkedlist_of_array(int a[],int n);
    void display_linkedList();
    int circular_doubly_length();
    void insert_in_circular_doubly(int x, int index);
    void delete_in_circular_doubly(int index);
};

void Circular_doubly::create_linkedlist_of_array(int a[],int n){
     head = new DNode;
     head->data = a[0];
     head->prev = NULL;
     head->next = NULL;

     DNode* last = head;

     for (int i = 1; i < n; ++i)
     {
       DNode* p = new DNode;
       p->data = a[i];
       p->next = NULL;
       p->prev = last;
       last->next = p;
       last = p;
     }

     last->next = head;
     head->prev = last;     
}
void Circular_doubly::display_linkedList(){
     if(head == NULL) return;
     DNode *p = head;
      do{
        cout << p->data <<" ";
        p=p->next;
      }while(p!=head);

      cout << endl;
}
int Circular_doubly::circular_doubly_length(){
    DNode *p = head;
    int l = 0;
    do{
      l++;
      p=p->next;
    }while(p!= head);

    return l;
}
void Circular_doubly::insert_in_circular_doubly(int x,int index){
     if(index < 0 || index > circular_doubly_length()) return;  
     DNode *t = new DNode;
     t->data = x;
    

     if(head == NULL){
       head = t;
       t->next = head;
       t->prev = head;
       return;
     }
     if(index == 0){
        t->next = head;
        t->prev = head->prev;
        head->prev->next = t;
        head->prev = t;
        head = t;
     }
     else{
        DNode *p = head;
       for (int i = 0; i < index-1; ++i)
       {
         p=p->next; 
       }
       t->next = p->next;
       t->prev = p;
       p->next = t;
       
       t->next->prev = t;
      
     }
}
void Circular_doubly::delete_in_circular_doubly(int index){
     if(index < 1 || index > circular_doubly_length()) return;
     DNode *p = head; 
     if(index == 1){
        if(head->next == head){
           delete head;
           head = NULL; return;
        }
        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;
        delete p;
     }
     else{
        for (int i = 0; i < index-1; ++i)
        {
          p = p->next;
        }
        p->next->prev =p->prev;
        p->prev->next = p->next;
        delete p;
     }    
}
/*................................................Doubly Linked list.................................*/
class Doubly_linkedList{
  private:
    DNode* head;
  public:
    Doubly_linkedList(){
      head = NULL;
    }
    void create_linkedlist_of_array(int a[],int n);
    void display_linkedList();
    void insert_in_doubly(int x,int index);
    int doubly_list_length();
    void delete_in_doubly(int index);
    void reversing_linkedlist();
};

void Doubly_linkedList::create_linkedlist_of_array(int a[],int n){
     head = new DNode;
     head->data = a[0];
     head->prev = NULL;
     head->next = NULL;

     DNode* last = head;

     for (int i = 1; i < n; ++i)
     {
       DNode* p = new DNode;
       p->data = a[i];
       p->next = NULL;
       p->prev = last;
       last->next = p;
       last = p;
     }     
}
void Doubly_linkedList::display_linkedList(){
     DNode* p = head;
     while(p){
       cout << p->data <<" ";
       p=p->next;
     }
     cout << endl;
}
int Doubly_linkedList::doubly_list_length(){
    DNode* p = head;
    int l = 0;
    while(p){
     l++;
     p=p->next;
    }
    return l;
}
void Doubly_linkedList::insert_in_doubly(int x,int index){
     if(index < 0 || index > doubly_list_length()) return;
    
     DNode* t = new DNode;
     t->data = x;
     t->prev = NULL;
     t->next = NULL;
     if(index == 0){
        t->next = head;
        head->prev = t;
        head = t;
     }
     else
     {
       DNode* p = head;
       for (int i = 0; i < index-1; ++i)
        {
          p=p->next;
        }
        t->next = p->next;
        t->prev = p;
        p->next = t;
        if(t->next){
          t->next->prev = t;
        }

     }
}
void Doubly_linkedList::delete_in_doubly(int index){
     if(index < 0 || index > doubly_list_length())return;
     DNode* p = head;
     if(index == 1){
       head = head->next;
       head->prev = NULL;
       delete p;
     }
     else{
        for (int i = 0; i < index-1; ++i)
        {
          p=p->next;
        }
        p->prev->next = p->next;
        if(p->next){
          p->next->prev = p->prev;
        }
        delete p;
     }
}
void Doubly_linkedList::reversing_linkedlist(){
     DNode* p = head;
     while(p){
       DNode* tmp = p->next;
       p->next=p->prev;
       p->prev = tmp;
       p =  p->prev;
       if(p!=NULL && p->next == NULL){
         head = p;
       }
     }
}
/*..................................................Circular Singly Linked List...........................................*/
class Circular_LinkedList{
    private:
      Node* head;
    public:
      Circular_LinkedList(){
        head = NULL;
      }
      void create_linkedlist_of_array(int a[],int n);
      void display_linkedList();
      int circular_list_length();
      void insert_in_circular(int x,int index);
      void delete_in_circular(int index);
};
void Circular_LinkedList::create_linkedlist_of_array(int a[],int n){
     head = new Node;
     head->data = a[0];
     head->next = head;

     Node* last = head;

     for (int i = 1; i < n; ++i)
     {
       Node* p = new Node;
       p->data = a[i];
       p->next = head;
       last->next = p;
       last = p;
     }     
}
void Circular_LinkedList::display_linkedList(){
     if(head == NULL) return;
     Node* p = head;

     do{
       cout << p->data <<" ";
       p = p->next;
     }while(p!=head);

     cout << endl;     
}
void Circular_LinkedList::insert_in_circular(int x,int index){
     Node* t = new Node;
     t->data = x;
     
     if(head == NULL){
       head = t;
       head->next = head;
       return;
     }
     
     Node* p = head;
     if(index == 0){

           while(p->next != head){
              p = p->next;
            }
            p->next = t;
            t->next = head;
            head = t;
     }
     else
     {

         for (int i = 0; i < index-1; ++i)
         {
           p = p->next;
         }

         t->next = p->next;
         p->next = t;      
     }
}
void Circular_LinkedList::delete_in_circular(int index){
     if(index <0 || index >circular_list_length()) return;
     Node* p = head;

     if(index == 1){
          while(p->next != head){
            p=p->next;
          }

          if(p == head){
            delete head;
            head = NULL;
          }
          else{
            p->next = head->next;
            delete head;
            head = p->next;
          }
     }
     else{
        for (int i = 0; i < index-2; ++i)
        {
          p=p->next;
        }
        Node* q=p->next;
        p->next = q->next;
        delete q;

     }
}
int Circular_LinkedList:: circular_list_length(){
    int l = 0;
    Node* p = head;
    do{
      l++;
      p=p->next;
    }while(p!=head);

    return l;
}

/*....................................................Singly Linked List..........................................*/
class LinkedList{
  private:
    Node* head;
  public:
    LinkedList(){
      head = NULL;
    }

    void insert_at_beginning(int x);
    void insert_at_end(int x);
    void insert_at_any_position(int x,int position);
    int list_length();
    void display_linkedList();
    void create_linkedlist_of_array(int a[],int n);
    Node* linearSearch_in_list(int key);
    int delete_from_list(int index);
    void reversing_linkedlist();
    void remove_duplicates_from_sorted();
    void concatenate_two_list(LinkedList &q);
    LinkedList merge_as_sorted(LinkedList &q);
    void find_middle_element();
};

void LinkedList::insert_at_beginning(int x){
     Node* p = new Node;
     p->data = x;
     p->next = head;
     head = p;
}
void LinkedList::insert_at_end(int x){
     Node* q = new Node;
     q->data = x;
     q->next = NULL;

     if(head == NULL){
        head = q;
        return;
     }

     Node* p = head;
     while(p->next != NULL){
      p = p->next;
     }

     p->next = q;
}
void LinkedList::display_linkedList(){
     if(head == NULL) return;
     Node* p = head;
     while(p){
       cout << p->data <<" ";
       p = p->next;
     }
     cout << endl;
}
void LinkedList::insert_at_any_position(int x,int position){

     if(position < 0 || position > list_length()) return;
     Node* q = new Node;
     q->data = x;
     q->next = NULL;
     
     Node* p = head;

     if(head == NULL){
      head = q;
      return;
     }

     if(position == 0){
      q->next = p;
      head = q;
      return; 
     }
     
     
     for (int i = 0; i < position-1; ++i)
     {
       p = p->next;
     }

     q->next = p->next;
     p->next = q;
}
int LinkedList::list_length(){
    if(head == NULL)return -1;
    Node* p = head;
    int l = 0;
    while(p){
      p = p->next;
      l++;
    }

    return l;
}
void LinkedList::create_linkedlist_of_array(int a[],int n){
     head = new Node;
     head->data = a[0];
     head->next = NULL;

     Node* last = head;

     for (int i = 1; i < n; ++i)
     {
       Node* p = new Node;
       p->data = a[i];
       p->next = NULL;
       last->next = p;
       last = p;
     }
}
Node* LinkedList::linearSearch_in_list(int key){
     //Binary search doesn't work in LinkedList, not consecutive memory
     Node* p = head;
     while(p){
       if(p->data == key){
        return p;
       }
       p = p->next;
     }

     return NULL;
}
int LinkedList::delete_from_list(int index){
     if(index < 1||index > list_length()) return -1;

     Node* p = head;
     if(index == 1){
        head = head->next;
        int x = p->data;
        delete p;

        return x;
     }

     
     Node* q = NULL;
     for (int i = 0; i < index-1; ++i)
     {
       q=p;
       p = p->next;
     }

     q->next = p->next;
     int x = p->data;
     delete p;
     return x;
}
void LinkedList::reversing_linkedlist(){
     Node*p = head;
     Node*q = NULL; Node* r = NULL;

     while(p){
       r=q;
       q=p;
       p=p->next;

       q->next = r;
     }
     head = q;
}
void LinkedList::remove_duplicates_from_sorted(){
     Node* p = head->next;
     Node* q = head;
     while(p){
         if(p->data == q->data){
           q->next = p->next;
           delete p;
           p = q->next;
         }
         else
         {
           q=p;
           p=p->next;
         }
     }
}
void LinkedList::concatenate_two_list(LinkedList &q){
     
     if(head == NULL){
      head = q.head;
      q.head = NULL;
     }

     if(q.head == NULL)return;


     Node* p = head;
     while(p->next){
       p=p->next;
     }
     p->next = q.head;
     q.head=NULL;
}
LinkedList LinkedList::merge_as_sorted(LinkedList &q){

     Node* p = head;
     Node* t = q.head;
     LinkedList merge_result;

     if(p == NULL){
        merge_result.head = q.head;
     }
     if(t == NULL){
      merge_result.head = p;
     }
     
     Node* third,*last;
     third = last = NULL;


     if(p->data < t->data){
       third = last = p;
       p = p->next;
       last->next = NULL;
     }
     else{
       third = last = t;
       t = t->next;
       last->next = NULL;      
     }

     while( p && t){
       if(p->data < t->data){
         last->next = p;
         last = p;
         p = p->next;
         last->next = NULL;
       }
       else
       {
         last->next = t;
         last = t;
         t = t->next;
         last->next = NULL;        
       }
     }

     if(p)last->next = p;
     if(t)last->next = t;

     merge_result.head = third;
     return merge_result;
}
void LinkedList::find_middle_element(){
     //if someone's velocity is double of you , you will reach half of the track when him reaching the finishline
     //finding middle element without length 
     Node *p,*q;
     p=q=head;
     while(q){
       q=q->next;
       if(q) q=q->next;
       if(q) p=p->next;
     }
     cout << p->data <<endl;
}

int main(){
    // LinkedList l1,l2,l3;
/*..........................................Code test part-01.............*/
    // l1.insert_at_end(5);
    // l1.display_linkedList();
    // l1.insert_at_end(6);
    // l1.display_linkedList();
    // l1.insert_at_beginning(4);
    // l1.display_linkedList();
    // l1.insert_at_any_position(1,0);
    // l1.display_linkedList();
    // l1.insert_at_any_position(2,1);
    // l1.display_linkedList();
    // l1.insert_at_any_position(7,5);
/*..........................................Code test part-02.............*/    
    // l1.display_linkedList();
    // l1.insert_at_any_position(5,3);
    // l1.display_linkedList();
    // l1.insert_at_end(6);
    // l1.insert_at_beginning(4);
    // l1.display_linkedList();
    // cout << l1.list_length() << endl;
/*..........................................Code test part-03.............*/    
    // int a[]={4,5,6,7,8,9,10};
    // l1.create_linkedlist_of_array(a,7);
    // l1.display_linkedList();
    // l1.find_middle_element();
    // Node* q = l1.linearSearch_in_list(4);
    // (q)?cout << q->data:cout<<-1; cout <<endl;

    // cout << l1.delete_from_list(10) <<endl;
    // cout << l1.delete_from_list(1) << endl;

    // l1.display_linkedList();
    // l1.reversing_linkedlist();
    // l1.display_linkedList();
    // l1.reversing_linkedlist();
    // l1.display_linkedList();

    // l1.insert_at_any_position(6,2);
    // l1.insert_at_any_position(6,2);
    // l1.insert_at_end(9);
    // l1.display_linkedList();

    // l1.remove_duplicates_from_sorted();
    // l1.display_linkedList();
/*..........................................Code test part-04.............*/    
    // l1.insert_at_end(2);
    // l1.insert_at_end(4);
    // l1.insert_at_end(8);

    // l2.insert_at_end(3);
    // l2.insert_at_end(6);
    // l2.insert_at_end(9);

    // //l1.concatenate_two_list(l2);
    // l1.display_linkedList();
    // l3 = l1.merge_as_sorted(l2);
    // l3.display_linkedList();
/*.........................................Code test part-05.............*/
   // int a[]={4,5,6,7,8};
   // Circular_LinkedList cl1;
   // cl1.create_linkedlist_of_array(a,5);
   // cl1.display_linkedList();
   // cl1.insert_in_circular(9,5);
   // cl1.display_linkedList();
   // cl1.insert_in_circular(1,0);
   // cl1.display_linkedList();
   // cout << cl1.circular_list_length() <<endl;
   // cl1.delete_in_circular(3);
   // cl1.display_linkedList();
   // cl1.delete_in_circular(1);
   // cl1.display_linkedList();    
/*.........................................Code test part-06.............*/    
   // int a[]={11,12,13,14,15};
   //  Doubly_linkedList dl1;
   //  dl1.create_linkedlist_of_array(a,5);
   //  dl1.display_linkedList();
   //  dl1.insert_in_doubly(10,0);
   //  dl1.display_linkedList();
   //  dl1.insert_in_doubly(16,6);
   //  dl1.display_linkedList();
   //  dl1.insert_in_doubly(7,3);
   //  dl1.display_linkedList();
   //  dl1.delete_in_doubly(1);
   //  dl1.display_linkedList();
   //  dl1.delete_in_doubly(7);
   //  dl1.display_linkedList();
   //  dl1.delete_in_doubly(3);
   //  dl1.display_linkedList();
   //  dl1.reversing_linkedlist();
   //  dl1.display_linkedList();
/*.........................................Code test part-07.............*/
// int a[]={20,21,22,23,24,25};
// Circular_doubly l1;
// l1.create_linkedlist_of_array(a,6);
// l1.display_linkedList();
// l1.insert_in_circular_doubly(19,0);
// l1.display_linkedList();
// l1.insert_in_circular_doubly(26,7);
// l1.display_linkedList();
// l1.insert_in_circular_doubly(69,3);
// l1.display_linkedList();
// l1.delete_in_circular_doubly(1);
// l1.display_linkedList();
// l1.delete_in_circular_doubly(8);
// l1.display_linkedList();
// l1.delete_in_circular_doubly(3);
// l1.display_linkedList();    

  return 0;
}