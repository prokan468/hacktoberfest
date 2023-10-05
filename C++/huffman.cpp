#include <iostream>
using namespace std;


// Given a string S of distinct character of size N and their corresponding frequency f[ ] 
// i.e. character S[i] has f[i] frequency. Your task is to build the Huffman tree print all the huffman codes in 
// preorder traversal of the tree.

struct Node{
    int data;
    string c;
    struct Node *left;
    struct Node *right;
}*start;

void createTree(int s, string c, int f[]){
    for(int i=0;i<s;i+=2){
        if(i==0){
            int initial= f[i]+f[i+1];
            start->data= initial;
            start->c= c[i]+"+"+c[i+1];
            start->left->data= f[i];
            start->left->c= c[i];
            start->right->data= f[i+1];
            start->right->c= c[i+1];
            continue;
        }
        struct Node *q;
        q= start;
        if((q->data+f[i])<(f[i]+f[i+1])){
            struct Node *temp= (struct Node *) malloc(sizeof(struct Node));
            temp->data= q->data+f[i];
            temp->c= c[i]+"+"+q->c;
            if(q->data<f[i]){
                temp->left= q;
                temp->right->data= f[i];
                temp->right->c= c[i];
            }else{
                temp->left->data= f[i];
                temp->left->c= c[i];
                temp->right= q;
            }
            start=q;
            i-=1;
        }else{
            struct Node *temp= (struct Node *) malloc(sizeof(struct Node));
            temp->data= f[i]+f[i+1];
            temp->c= c[i]+c[i+1];
            temp->left->data= f[i];
            temp->left->c= c[i];
            temp->right->data= f[i+1];
            temp->right->c= c[i+1];
        }
    }
}

int main(){
    string charactrs;
    cin>> charactrs;
    int stringsize= charactrs.size();
    int frequency[stringsize]= {};
    for(int i=0;i<stringsize;i++){
        cin>>frequency[i];
    }
    for(int i=0;i<stringsize;i++){
        for(int j=0;j<stringsize;j++){
            if(frequency[i]<frequency[j]){
                int temp= frequency[i];
                frequency[i]= frequency[j];
                frequency[j]= temp;
                int temp2= charactrs[i];
                charactrs[i]= charactrs[j];
                charactrs[j]= temp2;
            }
        }
    }
    createTree(stringsize, charactrs, frequency);
}