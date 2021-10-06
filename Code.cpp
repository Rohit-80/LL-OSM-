#include <bits/stdc++.h>
using namespace std ; 

using ll =  long long   ;
using db  = long double;
using str = string ;
//Loops
#define FOR(i,a,b) for(int i = (a) ; (a) < (b) ; i++);
#define F0R(a,b) FOR(a,0,b);
#define each(a,x) for(auto a : x);



using pi = pair<int,int>;
using pll = pair<long,long>;
#define mp make_pair
#define f first
#define s second

//Vectors
using vi = vector<int> ;
using vb = vector<bool> ;
using vd = vector<double> ;
using vs = vector<string> ;
using vpi = vector<pi> ;
using vpl = vector<pll>;
using vpd = vector<pair<double,double>>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

// Operations On Vectors
#define sz(x) int((x).size())


#define bg(x)  begin(x)
#define all(x) bg(x),end(x)
#define pb push_back
#define rsz resize
#define ins insert
#define ft front()
#define bk back()

// Templates
// Comperator
bool cmp(const pair<ll,ll> &a , const pair<ll,ll> &b){
   return (a.second < b.second); 
 } 

struct Node
{
    int data;
    Node* next;
};

struct Node* createNode(int val){
       Node* newNode = new Node;
       newNode->data = val;
       newNode->next = NULL;
       return newNode;
            
} 

struct Node* InsertNodeAtEnd(int val  , Node* head){

    Node* newNode = createNode(val);
    if(head == NULL){
      return newNode;
    }
    Node* temp = head;
    while(temp->next != NULL){
       temp = temp->next;
    }
    temp->next = newNode;
    return head;
};

struct Node* DeleteATend(Node* head){

            Node* temp = head;
            if(head == NULL){
               cout<<"Little Bit error";
               return head;
            }
           
           while(temp->next->next != NULL){
            temp = temp->next ;
           }
          free(temp->next);
                 
           temp->next = NULL;
           return head ;
           
}

struct Node* InsertAtBegin(int val , Node* head){
   Node* temp = createNode(val);
   temp->next = head;
   return temp;
}

struct Node* DeleteAtBegin(Node* head){
   Node* temp = head;
   if(head == NULL) {cout<<"Error" ; return head ;}
    head = head -> next;
    free(temp);
return head;
}



struct Node* InsetAtNth(int val , int pos ,Node* head){
      if(pos == 1) { Node* temp = InsertAtBegin(val,head);   return temp;}
       Node* temp = head;
   for(int i= 0 ; i< pos- 2 ; i++){
          temp = temp->next;
   }
    Node* nth = createNode(val);
    nth->next = temp->next;
    temp->next =nth;
     return head;
}





struct Node* DeleteAtNth(int pos , Node* head){
               Node* trav = head;
               if(pos == 1) {
                 return DeleteAtBegin(head);
               }
               for(int i = 0 ; i < pos - 2  ; i++){
                  trav = trav->next;}
                Node* temp = trav->next;
                trav->next = temp->next;
                 free(temp);
               
                return head; }
int count(Node* head){
   Node* trav = head;
   int count =0 ;
    while(trav != NULL){
      count++;
      trav= trav->next;
    }
    return count; 
}
// Deleting Nth elements form end


struct Node* DeleteAtNthEndLL(int pos , Node* head){
         return DeleteAtNth(count(head) - pos + 1, head);
}

//Write  this for 1 pass
struct Node* DeleteAtNthEnd2LL(int pos , Node* head){
   Node* trav1 = head;
   Node* trav2 = head;

   

   for(int i = 0 ; i < pos+1 ; i++){
      if(trav1 == NULL){
       
         return DeleteAtBegin(head);
      }
      trav1 = trav1->next;
   }

   while(trav1 != NULL){
      trav1 = trav1->next;
      trav2 = trav2->next;
   }

   Node* temp = trav2->next;
   trav2->next = temp->next;
   free(temp);
   return head;
}



void displayLL (Node* head){
   if(head == NULL) cout<<"This is empty" ;

 Node* temp = head ;

   while(temp != NULL ){
       cout << temp->data<<endl;
       temp = temp->next;
     
   }

}

 


  void test(){
  Node* head = NULL ;
   head = InsertNodeAtEnd(3,head);
   head =  InsertNodeAtEnd(5,head);
   head =  InsertNodeAtEnd(7,head);       
   head =  InsertNodeAtEnd(8,head);
   head = InsertAtBegin(98,head);
   head = DeleteAtBegin(head);
   head = InsetAtNth(97,4,head);
   // head = DeleteAtNth(3,head);
   head = DeleteAtNthEnd2LL(2,head);
   displayLL(head);

  }
int main(){
        ll t ;cin>>t;
        while(t--){
           test();}}

