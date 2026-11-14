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
struct Node{
	   int data;
	   struct Node* next;
}*first=NULL,*last=NULL;



void createLinkedList_of_an_array(int a[],int n){
    first = new Node;
    first->data = a[0];
	first->next=NULL;
	last = first;     
    for (int i = 1; i <n; ++i)
    {
        struct Node *p = new Node;
        p->data = a[i];
        p->next = NULL;
        last->next = p;
        last = p;    	
    }

}




void display(struct Node *p){

	 while(p != NULL){
	 	cout << p->data <<" ";
	 	p=p->next;
	 }
	 cout << endl;
}
void recur_display(struct Node *p){

	 if(p!=NULL){
	 	cout << p->data <<" ";
	 	recur_display(p->next);
	 }

}

int count(struct Node *p){
     int cnt = 0;
     while(p != NULL){
        cnt++;
        p=p->next;
     }
     return cnt;    
}

int recur_count(struct Node *p){
    if(p){
        return recur_count(p->next)+1;
    }
    else return 0;
}

int sum(struct Node *p){
     int sum = 0;
     while(p != NULL){
        sum+=p->data;
        p=p->next;
     }
     return sum;    
}

int recur_sum(struct Node *p){
    if(p){
        return recur_sum(p->next)+p->data;
    }
    else return 0;
}

int max_in_list(struct Node *p){

    int mx = INT_MIN;
    while(p!=NULL){
        mx = max(mx,p->data);
        p=p->next;
    }
    return mx;
}

int recur_max_in_list(struct Node *p){

    if(p){
        int x = recur_max_in_list(p->next);
        return (x>p->data)?x:p->data;
    } 
    else return INT_MIN;
}

struct Node* linear_search(struct Node*p,int key){
    //Binary search doesn't work for Linked List
     while(p!=NULL){
        if(p->data == key) return p;
        p = p->next;
     }

     return NULL;
}

struct Node* linear_search_improved(struct Node*p,int key){
    // Improved linear search by moving the key in front
    struct Node*t=NULL;
     while(p!=NULL){
        if(p->data == key){
           t->next = p->next;
           p->next = first;
           first = p;
           return p; 
        }
        t=p;
        p = p->next;
     }

     return NULL;
}

void insert_in_any_pos_of_list(struct Node*p,int pos,int x){

     // can create linked list if there's no list
    // can insert in any existing list
     if(pos < 0)return;
     if(pos == 0){
        struct Node*t = new Node;
        t->data = x;
        t->next = p;
        first=t;
     }
     else
     {
        struct Node*t = new Node;
        for (int i = 0; i < pos-1; ++i)
        {
            p=p->next;
        }
        
            t->data = x;
            t->next = p->next;
            p->next = t;
        
      
     }
}

void insert_at_last(struct Node*&p,int x){
     if(p == NULL){
        struct Node*t = new Node;
        t->data = x;
        t->next = p;
        p = t;

     }
     else{
        
        struct Node*t = p;
        while(t->next!=NULL)
        {
            t=t->next;
        }
         struct Node*q=new Node;
            q->data = x;
            q->next = t->next;
            t->next = q;        
     }
}

void insert_in_sortedlist(struct Node*p,int x){
    struct Node *t,*q;
    t=new Node;
    t->data = x;
    t->next = NULL;

    if(first == NULL){
      first = t;  
    }
    else{

        while(p && p->data <x){
            q=p;
            p=p->next;
        }
        if(p == first){
            t->next = first;
            first = t;
        }
        else{
            t->next=q->next;
            q->next = t;
        }
    }

}

int delete_from_linkedList(struct Node*&p,int index){
    if(index < 1 || index > count(p)) return -1;
    
    
    int x = -1;
    if(index == 1){
      struct Node*q=p;  
      x = p->data;
      p = p->next;
      delete q;
      return x;
    }
    else
    {
        struct Node*q=NULL;
        struct Node*target=p;
       for (int i = 0; i < index-1; ++i)
        {
            q=target;
            target=target->next;
        }
    
        q->next=target->next;
        x=target->data;
        delete target;
        return x; 
    }
}

bool Check_sorted_linkedList(struct Node*p){
     int x = INT_MIN;
     while(p!=NULL){
        if(p->data < x) return false;
        x=p->data;
        p=p->next;

     }
     return true;
}

void remove_duplicates_in_sortedList(struct Node*p){
     struct Node*q=p->next;
     while(q!=NULL){
        if(q->data == p->data){
           p->next=q->next;
           delete q;
           q=p->next;
        }
        else
        {
            p=q;
            q=q->next;
        }
     }
}

void reversing_linkedList_by_reversing_links(struct Node*p){
     struct Node*r=NULL,*q=NULL;
     while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
     }
     first=q;

}

void recur_reversing_linkedList_by_reversing_links(struct Node*p,struct Node*q){
     
     if(p!=NULL){

        recur_reversing_linkedList_by_reversing_links(p->next,p);
        p->next = q;
        
     }
     else{
        first = q;
     }
}

struct Node*second=NULL;
struct Node*third=NULL;
void concatenating_two_linked_list(struct Node*&p,struct Node*q){
     struct Node*t=p;
     while(t->next !=NULL){
        t=t->next;
     }
     t->next = q;
     
}
struct Node*fourth=NULL;
void merge_as_sort_sorted(struct Node*p,struct Node*q){
    struct Node*last=NULL;
    if(p->data < q->data){
        fourth=last=p;
        p=p->next;
        last->next=NULL;
    }
    else{
        fourth=last=q;
        q=q->next;
        last->next=NULL;        
    }

    while(p&&q){
        if(p->data < q->data){
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;

        }
        else {
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }

    if(p)last->next=p;
    if(q)last->next=q;     
}

int main(){
    FastIO;
    // int a[]={2,3,5,6,7,8,9};
    // createLinkedList_of_an_array(a,7);
    // display(first);
    // recur_display(first);
    // cout << count(first) << endl;
    // cout << recur_count(first) << endl;
    // cout << sum(first) << endl;
    // cout << recur_sum(first) << endl;
    // cout << max_in_list(first) << endl;
    // cout << recur_max_in_list(first) << endl;

    // struct Node*t = linear_search_improved(first,8);
    // cout << ((t!=NULL)?t->data:-1) <<endl;
    // display(first);

    // struct Node *x= linear_search_improved(first,3);
    // cout << ((x!=NULL)?x->data:-1) <<endl;
    // display(first);
////////////////////////////////////////// Creating LL with inserting
    // insert_in_any_pos_of_list(first,0,10);
    // display(first);
    // //int n = count(first);
    // insert_in_any_pos_of_list(first,1,11);
    // display(first);

    // insert_in_any_pos_of_list(first,0,12);
    // display(first);
    // insert_in_any_pos_of_list(first,3,23);
    // display(first);

    // insert_in_any_pos_of_list(first,0,22);
    // display(first);

///////////////////////////////////////Creating LL with inserting at last    
    insert_at_last(first,2);
    display(first);
    insert_at_last(first,3);
    display(first);
    insert_at_last(first,5);
    display(first);
    insert_in_sortedlist(first,10);
    display(first);
    insert_in_sortedlist(first,7);
    display(first);
//////////////////////////////////////Deleting from a LL    
    cout << delete_from_linkedList(first,2)<<endl;
    display(first);
    cout << delete_from_linkedList(first,3)<<endl;;
    display(first);
/////////////////////////////////////check sorted LL    
    cout<<Check_sorted_linkedList(first)<<endl;
    insert_at_last(first,7);
    display(first);
    //cout << Check_sorted_linkedList(first)<<endl;
////////////////////////////////////remove duplicate from sorted
    insert_at_last(first,7);
    insert_at_last(first,7);
    insert_in_any_pos_of_list(first,3,10);
    insert_in_any_pos_of_list(first,3,10);
    display(first);
    remove_duplicates_in_sortedList(first);
    display(first);
/////////////////////////////////// REVERSING a LINKED LIST 
    reversing_linkedList_by_reversing_links(first);
    display(first);
    recur_reversing_linkedList_by_reversing_links(first,NULL);
    display(first);
//////////////////////////////////Concatenate + Merge(sorted)    
    insert_at_last(second,1);
    insert_at_last(second,3);
    insert_at_last(second,4);
    display(second);
    //concatenating_two_linked_list(first,second);
    //display(third);
    display(first);
    insert_at_last(third,3);
    insert_at_last(third,4);
    insert_at_last(third,6);
    //concatenating_two_linked_list(first,third);
    delete_from_linkedList(first,3);
    display(first);
    display(third);
    merge_as_sort_sorted(first,third);
    display(fourth);



    return 0;
}