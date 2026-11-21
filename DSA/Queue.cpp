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
/*............................Queue using linked list....................*/
class Node{
      public:
      	int data;
      	Node* next;
};

class Queue_using_linkedList{
	  private:
	  	Node* front;
	  	Node* rear;
	  public:
	    Queue_using_linkedList(){
	    	front = rear = NULL;
	    }
	    void enqueue(int x);
	    int dequeue();
	    void display();	
};
void Queue_using_linkedList::enqueue(int x){
	 Node* t = new Node;
	 if( t ==  NULL) {
	 	cout <<"Heap full"<< endl;
	 	return;
	 }

	 t->data = x;
	 t->next = NULL;

	 if(front == NULL){
	 	front = rear = t;
	 }
	 else{
	 	rear->next = t;
	 	rear = t;
	 }
}
int Queue_using_linkedList::dequeue(){
	 int x = -1;
	 if(front ==  NULL){
	 	cout <<"Queue empty"<<endl;
	 	return x;
	 }
     
     Node* p = front;
     front = front->next;
     x = p->data;
     delete p;
     return x;
}
void Queue_using_linkedList::display(){
	if(front == NULL) return;
    Node *p = front;

    while(p){
    	cout << p->data <<" ";
    	p = p->next;
    }
    cout << endl;
}
/*............................Circular queue.............................*/
class Circular_queue{
	  private:
	  	int size;
	  	int front;
	  	int rear;
	  	int *q;
	  public:
	  	Circular_queue(int size){
	  		this->size = size+1;
	  		front = rear = 0;
	  		q = new int[size];
	  	}
      	void enqueue(int x);
      	int dequeue();
      	void display();
      	bool isEmpty();
      	bool isFull();	  	
};
void Circular_queue:: enqueue(int x){
     if(isFull()){
     	cout <<"Queue full"<<endl;
     	return;
     }
     rear = (rear+1)%size;
     q[rear] = x;
}
int Circular_queue::dequeue(){
	if(isEmpty()){
		cout <<"Queue empty"<<endl;
		return -1;
	}

	front = (front+1)%size;
	return q[front];
}
void Circular_queue:: display(){
	 if(isEmpty())return;
	 int i = (front+1)%size;
     while(i!= (rear+1)%size)
     {
     	cout << q[i] <<" ";
     	i = (i+1)%size;

     }
     cout << endl;
}
bool Circular_queue:: isEmpty(){
	return rear == front;
}
bool Circular_queue:: isFull(){
	return (rear+1)%size == front;
}
/*............................Queue using array..........................*/
class QueueArr{
      private:
      	int size;
      	int front;
      	int rear;
      	int *q;
      public:
      	QueueArr(int size){
      		this->size = size;
      		front = rear = -1;
      		q = new int[size];
      	}
      	void enqueue(int x);
      	int dequeue();
      	void display();
      	bool isEmpty();
      	bool isFull();

};

void QueueArr:: enqueue(int x){
     if(isFull()){
     	cout <<"Queue full"<<endl;
     	return;
     }
     q[++rear] = x;
}
int QueueArr::dequeue(){
	if(isEmpty()){
		cout <<"Queue empty"<<endl;
		return -1;
	}
	return q[++front];
}
void QueueArr:: display(){
	 if(isEmpty())return;
     for (int i = front+1; i <= rear; ++i)
     {
     	cout << q[i] <<" ";
     }
     cout << endl;
}
bool QueueArr:: isEmpty(){
	return rear == -1;
}
bool QueueArr:: isFull(){
	return rear == size-1;
}

int main(){
    FastIO;
/*......................Queue using array.................................*/    
    // QueueArr q1(5);
    // q1.enqueue(5);
    // q1.enqueue(4);
    // q1.enqueue(3);
    // q1.enqueue(2);
    // q1.enqueue(1);
    // q1.display();
    // cout << q1.dequeue() << endl;
    // cout << q1.dequeue() << endl;
    // q1.enqueue(5);
    // q1.display();// this problem is solved by cicular queue
/*......................Circular queue using array........................*/
    
   // Circular_queue q1(5);
   // q1.enqueue(5);
   // q1.enqueue(4);
   // q1.enqueue(3);
   // q1.enqueue(2);
   // q1.enqueue(1);
   // q1.display();
   // cout << q1.dequeue() << endl;
   // q1.enqueue(5);
   // q1.enqueue(4);
   // q1.display();
/*.....................Queue using linked list............................*/
    Queue_using_linkedList q1;
    q1.enqueue(5);q1.enqueue(4);q1.enqueue(3);
    q1.display();
    q1.dequeue();
    q1.dequeue();
    q1.display();


    return 0;
}