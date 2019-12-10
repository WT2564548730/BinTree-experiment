#include <iostream>
using namespace std;

#define MaxSize 100
typedef int ElementType;
//二叉树
typedef struct TNode{
    ElementType Data;
    struct TNode *Left;
    struct TNode *Right;
    int Height;
}*BinTree;
//堆
typedef struct HNode{
    ElementType Data;
    int Size;
    int Capacity;
}*Heap,*MinHeap,*MaxHeap;
//哈夫曼树
typedef struct HTNode{
    int Weight;
    struct HTNode *Left;
    struct HTNode *Right;
}*HuffmanTree;

//求树高（用于打印树形，平衡二叉树的调整）
int GetHeight(BinTree T);
//树的创建
BinTree BuildTree(int tag);                                         //二叉树(层次遍历）和二叉搜索树的创建
BinTree CreateBinTree();                                            //二叉搜索树树的初始化
BinTree InsertBinTree(BinTree T,ElementType X);                     //向树中插入元素
BinTree InsertBinTree(BinTree T,ElementType L,ElementType R);
//树的遍历（非递归）
void LeverTraversal(BinTree T);                                     //层序遍历
void PreOrderTraversal(BinTree T);                                  //先序遍历非递归算法
void InOrderTraversal(BinTree T);                                   //中序遍历非递归算法
void PostOrderTraversal(BinTree T);                                 //后序遍历非递归算法
//二叉搜索树的删除
ElementType Delete(BinTree T,ElementType X);
//二叉搜索树的判定
bool IsBinSearchTree1(BinTree T);                                   //定义判断二叉搜索树
bool IsBinSearchTree2(BinTree T);                                   //中序遍历判断
//平衡二叉树的调整
BinTree SingleRotation(BinTree T,int Tag);                          //左（右）单旋
BinTree LeftRightRotation(BinTree T,int Tag);                       //左右（右左）双旋
//堆的创建（最小堆为例）
Heap BuildMinHeap(MinHeap H);                                       //最小堆的创建
MinHeap CreateMinHeap();                                            //初始化堆
//堆的插入删除及调整（最小堆为例）
ElementType DeleteMin(MinHeap H);                                   //最大堆的删除
ElementType InsertMin(MinHeap H,ElementType X);                     //最小堆的插入
//哈夫曼树的构造
HuffmanTree Huffman();
//打印树形
void PrintTree(BinTree T,int nLayer);

int main(){
    //树的创建
//presentedViewController?.dismiss(animated: true, completion: nil);    cout<<"构造普通二叉树"<<endl;
//    BinTree BT=BuildTree(0);
    cout<<"构造二插搜索书"<<endl;
    BinTree BST=BuildTree(1);                                       //内含平衡二叉树的调整
    //树的遍历（非递归）
    LeverTraversal(BST);
//    PreOrderTraversal(BST);
//    InOrderTraversal(BST);
//    PostOrderTraversal(BST);
//    //二叉搜索树的删除
//    int n;
//    cout<<"请输入要删除结点 : ";
//    cin>>n;
//    Delete(BST,n);
//    //二叉搜索树的判定
//    IsBinSearchTree1(BT);
//    IsBinSearchTree2(BT);
    //哈夫曼树的构造
//    HTNode HT=Huffman();                                //内含最小堆的创建，插入删除等操作
//    //打印树形
//    int Height=GetHeight(HT);
    
    return 0;
}

//树
BinTree BuildTree(int tag){
    BinTree T;
    if(tag==0){
        T=CreateBinTree();
        int n;
        //输入待插入结点
        cin>>n;
        T->Data=n;
        BinTree Q[MaxSize];
        int front=0;
        int rear=0;
        
        Q[rear++]=T;
        while(front!=rear){
            BinTree tmp=Q[front++];
            
            int l,r;
            cout<<"请输入 tmp 的左右子树值 : ";
            cin>>l>>r;
            
            tmp=InsertBinTree(tmp,l,r);
        }
        PrintTree(T,GetHeight(T));
    }else{
        T=CreateBinTree();
        while(1){
            int n;
            cout<<"请输入待插入结点 : ";
            cin>>n;
            if(n==0)    break;
            
            T=InsertBinTree(T,n);
        }
    }
    return T;
}

BinTree CreateBinTree(){
    BinTree T=new TNode;
    T->Left=T->Right=NULL;
    T->Height=0;
    
    return T;
}

BinTree InsertBinTree(BinTree T,ElementType L,ElementType R){
    T->Left=CreateBinTree();
    T->Right=CreateBinTree();
    
    T->Left->Data=L;
    T->Right->Data=R;
    return T;
}

BinTree InsertBinTree(BinTree T,ElementType X){
    if(!T){
        T=new TNode;
        T->Data=X;
        T->Right=T->Left=NULL;
    }else{
        if(X<T->Data)    T->Left=InsertBinTree(T->Left,X);
        else    T->Right=InsertBinTree(T->Right,X);
    }
    return T;
}

void LeverTraversal(BinTree T){
    BinTree Q[MaxSize];
    int front=0;
    int rear=0;
    
    Q[rear++]=T;
    while(rear!=front){
        BinTree Tmp=Q[front++];
        if(front==1)    cout<<Tmp->Data;
        else    cout<<" "<<Tmp->Data;
        if(Tmp->Left)   Q[rear++]=Tmp->Left;
        if(Tmp->Right)  Q[rear++]=Tmp->Right;
    }
}
