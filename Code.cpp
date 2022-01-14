#include <bits/stdc++.h>
using namespace std ; 
using ll =  long long   ;
using db  = long double;
using str = string ;
//Loops/jhlhuk htgv fjfcchg jhg ghf vfghf gff
gjf hf
wor jkljue rlkfkklsdfjkfdkjj
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
// Reverse through Recursion
struct Node* ReverseRec(Node* head , Node* prevPtr = NULL){
  Node* temp = head;
    if(temp == NULL){
    return prevPtr;
  }
   head = temp->next;
   temp->next = prevPtr;
   prevPtr = temp;
   return ReverseRec(head,prevPtr);
}
// Mergeing Sorted LL through Extra Space means Creating new LinkedList
Node* MergeSortedLL(Node* head1 , Node* head2){
            
   Node* trav1 = head1;
   Node* trav2 = head2;
   Node* newLL = NULL;
   Node* travNew = newLL ;
 Node* temp ;
    while(trav1 != NULL && trav2 != NULL ){
        if(trav1->data <= trav2->data){
        temp  = createNode(trav1->data);
        trav1 = trav1->next;
        }
        else { 
         temp = createNode(trav2->data);
        trav2 =  trav2->next;
      }
      if(newLL == NULL){
         newLL = temp ;
         travNew = temp;
      }
      else {
         travNew->next = temp ;
         travNew  = temp ;
      }
    }
    while(trav1 != NULL){
      temp = createNode(trav1->data);
         trav1 = trav1->next;
     if(newLL == NULL){
         newLL = temp ;
         travNew = temp;
      }
      else {
         travNew->next = temp ;
         travNew  = temp ;
      }    
}
    while(trav2 != NULL){
      temp = createNode(trav2->data);
      trav2 = trav2->next;
     if(newLL == NULL){
         newLL = temp ;
         travNew = temp;
        
      }
      else {
         travNew->next = temp ;
         travNew  = temp ;
        
      }    
}
return newLL;
}
// I am doing that work through Insertion sort...
// Merging Through Insertion technique 
Node* MergeSortedLLInsertion(Node* head1, Node* head2){
    Node* trav1 = head1;
    Node* trav2 = head2;
   
   if(head1 == NULL ) return head2 ;
   if(head2 == NULL) return head1;
    if(trav1->data > trav2->data)
      swap(trav1 ,trav2);
    Node*  prevPtr = trav1;
    Node* mergeLL  = trav1;
    
     while(trav1 !=  NULL && trav2 != NULL){
      
           while( trav1 != NULL && trav1->data <= trav2->data){
                 prevPtr  = trav1;
                 trav1 = trav1->next;
           }
           prevPtr->next = trav2;
           swap(trav1,trav2);
 }  
    return mergeLL ;
}
//1 2 3 4 5 
/// Finding Middle element O(N) + O(N/2)
void displayMiddleElementBy1andHalf(Node* head){ 
    Node* temp = head;
    int cElement = countLL(head);
    if(head == NULL) return;
    if(head->next == NULL) return ;
    for(int i = 0 ; i < cElement/2-1; i++)
       temp = temp->next;
    cout<<"Middle Element : ";
      if(cElement%2 == 0) cout<<temp->data<<" and ";
    cout<<temp->next->data<<endl;
 }
 //Finding Middle Element through O(N) OR One Pass
// One Pointer 2X and second Pointer 1X
 void displayMiddleElementByOnePass(Node* head){
  Node* t2X = head;
  Node* t1X = head;
// this code work for 1 Node perfectly but not run  on 0 node means 
 // when head is null 
  if(head == NULL) return ;
          // 1 2 3 4 5 6 7
         // 1 2 3 4 5 6
              // ODD                     // Even
      while(t2X->next !=  NULL && t2X->next->next != NULL ){
             
            t2X = t2X->next->next;
            t1X = t1X->next;
         }
          cout<< "Second Middle : ";
         // Odd number of Elements
         if(t2X->next == NULL)
          cout<<t1X->data<<endl;
       else 
       cout<<t1X->data<< " and "<< t1X->next->data<<endl;
 }
Node* DleteMiddleOnePass(Node* head){
   Node* txo = head;
   Node* txs = head;
 if(head == NULL ) return NULL ;
 if(head->next == NULL || head->next->next == NULL) return NULL;
 Node* prevPtr = head;
  int i  = 0 ;
   while(txs->next != NULL && txs->next->next != NULL){
     if(i != 0)
      prevPtr = prevPtr->next;
      i++;
      txo = txo->next;
      txs  = txs->next->next; 
   }
if(txs->next == NULL){
    Node* temp2 = txo;
    Node* temp = txo;
    temp2 = txo->next;
    free(temp);
    prevPtr->next = temp2;
}
else {
      Node* temp2 = txo;
    Node* temp = txo;
    Node* temp1 = txo->next;
    temp2 = txo->next->next;
    free(temp);
    free(temp1);
    prevPtr->next = temp2;
}
return head ;
}
Node* InsertAtMiddle(int val , Node* head){
   Node* txo = head;
   Node* txs = head;
Node* newNode = createNode(val);
if(head == NULL) return newNode;
 Node* prevPtr = head;
  int i  = 0 ;
   while(txs->next != NULL && txs->next->next != NULL){
     if(i != 0)
      prevPtr = prevPtr->next;
      i++;
      txo = txo->next;
      txs  = txs->next->next; 
   }
if(txs->next == NULL){
  
    Node* temp2 = txo->next;
    newNode->next = temp2;
    txo->next = newNode;
    
    
   
}
else {
      Node* temp2 = txo->next;
    newNode->next = temp2;
    txo->next = newNode;
}
return head ; 
}
void displayLL (Node* head){
   if(head == NULL) cout<<"This is empty" ;
 Node* temp = head ;
   while(temp != NULL ){
       cout << temp->data<<endl;
       temp = temp->next;
     
   }

}
/****  
Day- 11 Oct I am doing Detection of loop in LinkedList  through
two method 1 - through unordered_set.
    method 2 - through Amazing cs sir Algo
Node* initLL(vector<int >& v )
{ 
   
  if(v.size() == 0) return NULL; 
Node* head = createNode(v[0]);
Node* trav = head;
int i =  1;
  while(i < v.size()){
   trav->next = createNode(v[i]);
trav = trav->next;
i++;
  }
   return  head ; 
}
bool DetectLoopLL(Node* head){
   unordered_set<Node*> set;
   Node* trav = head; 
while(trav != NULL){
      if(set.find(trav) != set.end())
         return true;
      
      set.insert(trav);
     trav =  trav->next ;}
     return false; 
}
bool DetectLoopLL2(Node* head){
   Node* trav1 = head , *trav2 = head;
   while(trav2 != NULL && trav2->next->next != NULL){
      trav2  = trav2->next->next;
      trav1 =  trav1->next ;
      if(trav1 == trav2) return true;
   }
   return false;
}
void displayLL(Node* head){
   Node* temp = head;
  while(temp != NULL){
   cout<<temp->data<<" " ;
   temp = temp ->next ; 
  }
}
void test(){
  vector<int> v{1,2,3,4,5,6};
  Node* head =  NULL; 
  head = initLL(v);
 displayLL(head) ;
 cout<<endl;
 cout<<DetectLoopLL2(head);
 head->next->next->next->next->next->next = head->next->next;
 cout<<DetectLoopLL2(head);
}
****/



   void test(){
  
 Node* head1 = NULL ; 
 head1 = InsertAtEnd(3,head1);
 head1 = InsertAtEnd(5,head1);
 head1 = InsertAtEnd(5,head1);
 head1 = InsertAtEnd(7,head1);
 head1 = InsertAtEnd(8,head1);
displayMiddleElementBy1andHalf(head1);
 displayMiddleElementByOnePass(head1);
 Node* head2 = NULL ;
 head2 = InsertAtEnd(2,head2);
 head2 = InsertAtEnd(3,head2);
 head2 = InsertAtEnd(6,head2);
 head2 = InsertAtEnd(7,head2);
 head2 = InsertAtEnd(9,head2);
 displayMiddleElementBy1andHalf(head2);
displayMiddleElementByOnePass(head2);
Node* head3 = MergeSortedLLInsertion (head1 , head2);
displayMiddleElementBy1andHalf(head3);
displayMiddleElementByOnePass(head3);
displayLL(head3);
 }
int main(){
        ll t ;cin>>t;
        while(t--){
           test();}}
