#include <bits/stdc++.h>
#include <fstream>
#include <iostream>

using namespace std ; 


#define ll long long 
#define All(x) sort(x.begin(), x.end());
#define nl cout<<"\n";
#define debug(x) cerr << #x<<" : "; _print(x); cerr << endl;

// Templates
// Comperator
// const ll mod =  998244353;
// const ll N = 1005;

// bool used[N];

// ll col[N];

// // ll counter[2]={0,0};
// bool All_ok = true;
// vector<ll > adj[N];
// vector<ll> col(N);

// ll t ;
// ll connected[N] ;
// ll id[N];


//  map<ll,ll> prime;

// void PreAllPrime(){
//     vector<bool> visted(1e7+200,false);

//       for(ll i = 2 ; i < visted.size() ; i++){
//            if(!visted[i]){
//                // prime.emplace_back(i);
//              prime[i]++;
            
//          for(ll j = i*i ; j < visted.size() ; j += i){
//              visted[j] = true;
//          }
//       } }}
 //  Logic ------------------------------------------------------------------
 //   for(auto a : v){
  //   q.push_back({a.second,o,a.first});
  //    o *= -1;
  //    if(o > 0) o++; 
  // }------------------------------------------------------------------------
// *
 //   ll w = 0 ,b = 0;
 // for(ll i = 0 ; i < n ; i++){
 //        if(s[i] == 'W') {
 //            if(w == 0) v.push_back(0);
 //            w++;
 //            b = 0 ;
 //        }
 //        else {
 //            if(b == 0) v.push_back(1);


struct Node
{
     int data ;
     Node* left;
     Node* right;
     Node(int datas){
        data = datas;
        left = right = NULL;
     }
};

void preorder(Node* root){
    if(root == NULL) return ;
     cout<<root->data<<"\n";
     preorder(root->left);
     preorder(root->right);
}
void  Inorder(Node* root){
    if(root == NULL) return;
      Inorder(root->left);
      cout<<root->data;
      Inorder(root->right);
}
void postOrder(Node * root){
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data;
}
void test (){
   
   Node *root = new Node(2);
   root->left = new Node(6);
   root->right= new Node(4);
   root->left->left = new Node(7);
   preorder(root); 
   Inorder(root);nl;
   postOrder(root);

 }




 
int main(){
 ios_base::sync_with_stdio(0);
    cin.tie(0);
    // cout.tie(0);


 // ll t ; cin>>t;
 // T = 1;
  // test();
  // while(t--)
    test();


return 0 ;
}
