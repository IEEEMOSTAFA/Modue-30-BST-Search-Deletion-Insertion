#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int value;
    node*Left;
    node*Right;
    //node*parent;    //BST te parent node besi help korce na tai parent node ta Bad dicci


};
class BST{
public:
    node*root;

    BST()
    {
        root = NULL;
    }
    node*CreateNewNode(int value)
    {
        node*newnode = new node;
        newnode->value = value;
        newnode->Left = NULL;
        newnode->Right= NULL;
        return newnode;
    }


    ///
    void BFS()
{
    if(root == NULL)
        return;
    queue<node*>q;
    q.push(root);


    while(!q.empty())
    {
        node*a =q.front();
        q.pop();
        int p= -1 , l= -1 , r= -1 ;
        if(a->Left !=NULL)
        {
           l=a->Left->value;
        q.push(a->Left);
        }


        if(a->Right !=NULL)
        {
          r=a->Right->value;
            q.push(a->Right);
        }




        cout<<"Node Value =   "<<a->value << "   Left Child =   "<<l;

        cout<<" Right Child =   " << r <<"\n";
         cout<<endl;
    }
}


void Insert(int value)
{
  node*newnode = CreateNewNode(value);

  if(root == NULL)
  {
      root = newnode;
      return;
  }
  node*cur =root;
  node*prv = NULL;
  while(cur != NULL)
  {
      if(newnode->value > cur->value)
      {
          prv = cur;
          cur = cur->Right;
      }
      else
      {
          prv =cur;
          cur = cur->Left;
      }
  }
  if(newnode->value > prv->value)
  {
    prv->Right = newnode;
  }
  else
  {
      prv->Left = newnode;
  }


}
bool Search(int value)
{
    node*cur = root;
    while(cur !=NULL)
    {
        if(value > cur->value)
        {
            cur = cur->Right;

        }
        else if(value < cur->value)
        {
            cur = cur->Left;

        }
        else          // else dara equal condition bojjacce
        {
            return true;
        }
    }
    return false;   //loop teke ber hole current NULL bojjacce tai false return korbe;
}

void Delete(int value)
{
    node*cur = root;
    node*prv = NULL;
    while(cur != NULL)
    {
        if(value > cur->value)
        {
            prv = cur;
            cur = cur->Right;
        }
        else if(value < cur->value)
        {
            prv = cur;
            cur = cur->Left;
        }
        else
        {
            break;
        }
    }
    if(cur == NULL)
    {
        cout<<"value id not present in BST \n";
        return;
    }
    // case 1 :both child is NULL
    if(cur->Left == NULL && cur->Right == NULL)
    {
        if(prv->Left!=NULL &&  prv->Left->value == cur->value)
        {
            prv->Left = NULL;
        }
        else
        {
            prv->Right = NULL;
        }
        delete cur;
        return;
    }
    //case 2 : node has only one child
    if(cur->Left == NULL && cur->Right != NULL)
    {
     if(prv->Left!=NULL &&  prv->Left->value == cur->value)
        {
            prv->Left = cur->Right;
        }
        else
        {
            prv->Right = cur->Right;
        }
        delete cur;
        return;
    }
     if(cur->Left != NULL && cur->Right == NULL)
    {
     if(prv->Left!=NULL &&  prv->Left->value == cur->value)
        {
            prv->Left = cur->Right;
        }
        else
        {
            prv->Right = cur->Right;
        }
        delete cur;
        return;
    }
}

};
int main()
{
BST bst;
bst.Insert(6);
bst.Insert(4);
bst.Insert(3);
bst.Insert(5);
bst.Insert(7);
bst.Insert(8);

//bst.BFS();



//Case 1-
//bst.Delete(8);
//bst.BFS();
//Case 2-
bst.Delete(7);
bst.BFS();

}
