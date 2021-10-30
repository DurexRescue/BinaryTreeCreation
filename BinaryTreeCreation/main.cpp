//
//  main.cpp
//  BinaryTreeCreation
//
//  Created by 雷思奇 on 2019/10/30.
//  Copyright © 2019 雷思奇. All rights reserved.
//


#include <iostream>
#include <algorithm>
#include <unistd.h>


using namespace std;
template <class T>
struct BinTreeNode {          //二叉树结点类定义
    T data;                   //数据域
    BinTreeNode<T> *leftChild, *rightChild;
    //左子女、右子女链域
    BinTreeNode()                //构造函数
    {
        leftChild = NULL;
        rightChild = NULL;
    }
    BinTreeNode(T x, BinTreeNode<T> *l = NULL, BinTreeNode<T> *r = NULL)
    {
        data = x;
        leftChild = l;
        rightChild = r;
    }
};

template<class T>
bool Judge(T* S1, T* S2, int n) {
    T s3[30], s4[30];
    for (int i = 0; i < n; i++) {
        s3[i] = S1[i];
        s4[i] = S2[i];
    }
    sort(s3, s3 + n);
    sort(s4, s4 + n);
    for (int i = 0; i < n; i++) {
        if (s3[i] != s4[i]){
            cout<<s3[i]<<" Errors！";
            return false;
        }
    }//序列判断
    for(int i=0;i<n-1;i++){
        if(s3[i]==s3[i+1]||s4[i]==s4[i+1])return false;
    }//重复判断
    
    return true;
}

template<class T>
BinTreeNode<T> *PMcreateBinaryTree(T*VLR, T*LVR, int n) {
    if (Judge(VLR,LVR,n) == false){
        cout<<"序列错误，请检查！";
        return NULL;
    }
    if (n == 0)return NULL;
    int k = 0;
    while (VLR[0] != LVR[k])k++;
    BinTreeNode<T> *t = new BinTreeNode<T>(VLR[0]);
    t->leftChild = PMcreateBinaryTree(VLR + 1, LVR, k);
    t->rightChild = PMcreateBinaryTree(VLR + k + 1, LVR + k + 1, n - k - 1);
    
    return t;
}//靠前序和中序序列来创建树

template<class T>
BinTreeNode<T> *MLcreateBinaryTree(T*LVR, T*LRV, int n) {
    if (Judge(LRV, LVR, n) == false){
        cout<<"序列错误，请检查！";
        return NULL;
    }
    if (n == 0)return NULL;
    int k = 0;
    while (LRV[n - 1] != LVR[k])k++;
    BinTreeNode<T> *t = new BinTreeNode<T>(LRV[n - 1]);
    t->leftChild = MLcreateBinaryTree(LVR, LRV, k);
    t->rightChild = MLcreateBinaryTree(LVR + k+1, LRV + k, n - k - 1);
    return t;
}//靠中序和后序序列来创建树

template<class T>
void PrintBiTree(BinTreeNode<T>* &t, int level) //二叉树t第level层结点数据域显示
{
    if (t == NULL) return;       //如果空二叉树返回
    PrintBiTree(t->rightChild, level + 1);    //二叉树t->Right()第level+1层结点数据域显示
    if (level != 0)
    {//走过6*(level-1)个空格
        for (int i = 0; i < 3 * (level - 1); i++) cout << "   ";
        cout << "----";    //显示横线
    }
    cout << t->data << endl;  //显示结点数据域
    PrintBiTree(t->leftChild, level + 1);  //二叉树t-> Left()第level+1层结点数据域显示
    sleep(1);
}

int main()
{
    char a[] = "ABDFGCEH";
    char b[] = "BFDGACEH";
    char c[] = "FGDBHECA";
    
    /*
     char a[] = "ABDEC";
     char b[] = "CADBE";
    */
    if(strlen(a)==strlen(b)){
        BinTreeNode<char> *t=PMcreateBinaryTree(a,b,int(strlen(a)));
        PrintBiTree(t, 0);
        cout<<"Complete"<<endl;
    }
       else cout<<"两个序列长度不一致";
    
    
    if(strlen(b)==strlen(c)){
        BinTreeNode<char> *t1 = MLcreateBinaryTree(b, c, int(strlen(a)));
        PrintBiTree(t1, 0);
         cout<<"Complete"<<endl;
    }
    
    
}



