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

/*..........................stack using array........................*/
class StackArr{
   private:
      int size;
      int top;
      char* ch;
   public:
      StackArr(int x){
         size = x;
         top = -1;
         ch = new char[size];      
      }
      void Push(char x);
      int Pop();
      int Peek(int pos);
      void Display();
      bool isFull();
      bool isEmpty();
      char stackTop();   

};
void StackArr::Push(char x){
     if(isFull()){
        cout << "Overflow Stack"<<endl;
        return;
     }
     top++;
     ch[top]=x;
}
int StackArr::Pop(){
    if(isEmpty()){
        cout <<"Underflow Stack"<<endl;
        return -1;
    }
    int x = ch[top--];
    return x;
}
int StackArr::Peek(int pos){
    int x = -1;
    if(top-pos+1 <0)return x;
    return ch[top-pos+1];
}
void StackArr::Display(){
     for (int i = top; i >= 0; i--)
     {
         cout << ch[i] << endl;
     }
     cout << endl;
}
bool StackArr:: isFull(){
     return top == size-1;
}
bool StackArr::isEmpty(){
     return top == -1;
}
char StackArr:: stackTop(){
     return ch[top];
}
/*..........................stack using linked list...................*/
class Node{
   public:
    int data;
    Node* next;
};

class Stack{
   private:
    Node* top;
   public:
    Stack(){
        top = NULL;
    }
    void Push(int x);
    int Pop();
    int Peek(int pos);
    void Display();
    bool isEmpty();
    bool isFull(); 
};

void Stack::Push(int x){
    

    Node* t = new Node;
    if(t== NULL){
        cout <<"Stack Overflow"<<endl;
        return;
    }
    t->data = x;
    t->next = top;
    top = t;
}
int Stack::Pop(){
    
    int x = -1;
    if(top == NULL){
        cout <<"Stack Underflow"<<endl;
        return x;
    }
    
    Node* p = top;
    x = top->data;
    top = top->next;
    delete p;
    return x;
}
int Stack::Peek(int pos){
    Node* p = top;
    for (int i = 0; i < pos-1; ++i)
    {
        p=p->next;
    }
    if(p)return p->data;
    else return -1;
}
void Stack::Display(){
    Node* p = top;
    while(p){
        cout << p->data <<endl;
        p=p->next;
    }
    cout << endl;
}
bool Stack::isEmpty(){
    if(top) return false;
    else true;
}
bool Stack::isFull(){
    Node *t = new Node;
    if(t)return true;
    else return false;
}
/*............................Balanced parenthesis problem................*/
bool balanced_parenthesis_problem_firstBracketonly(string s){
     
     StackArr st(s.size());
     for (int i = 0; i < s.size(); ++i)
     {
         if(s[i]=='(')st.Push(s[i]);
         else if(s[i]==')'){
            if(st.isEmpty())return false;
            st.Pop();
         }
     }
     if(st.isEmpty())return true;
     else return false;
}
bool balanced_parenthesis_problem(string s){
     StackArr st(s.size());
     for (int i = 0; i < s.size(); ++i)
     {
         if(s[i]=='('||s[i]=='{'||s[i]=='[')st.Push(s[i]);
         else if(s[i]==')'|| s[i]=='}'||s[i]==']'){
            if(st.isEmpty())return false;
            char top = st.Peek(1);
            if((s[i]==')'&& top !='(')||(s[i]=='}'&& top !='{')||(s[i]==']'&& top !='[')){
                return false;
            }
            else  st.Pop();
         }
    

     }
     if(st.isEmpty())return true;
     else return false;     
}

/*........................infix to postfix conversion...................*/
bool isOperand(char c){
    if(c=='+'||c=='-'||c=='*'||c=='\\') return false;
    return true;
}

int precedence(char c){
    if(c=='*'||c=='\\')return 2;
    else if(c=='+'||c=='-')return 1;
}
string infix_to_postfix(string infix){
       StackArr st(infix.size());
       string postfix="";
       int i = 0;
       while(i < infix.size())
       {
           if(isOperand(infix[i])){
             postfix += infix[i++];
           }
           else{
             if(st.isEmpty() || precedence(infix[i])>precedence(st.stackTop())){
               st.Push(infix[i++]);
             }
             else{
                
                   postfix += st.Pop();
                
             }
           }

       }

       while(!st.isEmpty()){
         postfix += st.Pop();
       }

       return postfix;
}


int main(){
    FastIO;
/*.......................Stack using array........................*/
  // StackArr stt(5);
  // stt.Push('(');
  // stt.Push(')');
  // stt.Push('{');
  // stt.Display();
  // string s = "[[[{((a+b))+(a-b)}]]]";
  // cout << balanced_parenthesis_problem(s)<<endl;

/*......................infix to postfix problem..................*/
  string s = "a+b*c-d/e";
  string t = infix_to_postfix(s);
  cout << t << endl;


/*.......................Stack using linked list..................*/    
    // Stack st;
    // st.Push(5);
    // st.Push(4);
    // st.Push(3);
    // st.Display();
    // st.Pop();
    // st.Display();
    // st.Pop();
    // st.Display();
    // st.Push(6);
    // st.Push(7);
    // st.Push(8);
    // st.Display();
    // cout << st.Peek(2)<<endl;
    


    return 0;
}