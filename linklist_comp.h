// header file made
#ifndef linklist_comp_H
#define linklist_comp_H
#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
}*save,*start,*beg;
//--------------------------------------------function declaration-------------------------------------
void insertion_from_start(node*);
void insertion_from_end(node*);
void insertion_from_mid(node*);
node* createnode(int d);
void deletion_from_start();
void deletion_from_end();
void deletion_from_mid();
int search_element(int ele);
void display();

//-----------------------------------------------insertion from start-------------------------------------------------
void insertion_from_start(node* new_node)
{
    save=start;
    start=new_node;
    new_node->next=save;

}
// -----------------------------------------------create node----------------------------------------
node* createnode(int d)
{
    node* new_node=new node();
    new_node->data=d;
    new_node->next=NULL;
    return new_node;
}
    //---------------------------------------------deletion from start------------------------------------------------
void deletion_from_start()
{
    save=start;
    save=save->next;
    delete(start);
    start=save;

}
//--------------------------------------------deletion from end-----------------------------------------------------
void deletion_from_end()
{
    save=start;
    while(save->next!=NULL)
    {
        beg=save;
        save=save->next;
    }
    beg->next=NULL;
    delete(save);
}
//-------------------------------------------------search element------------------------------------------------------
int search_element(int ele)
{
    int i=0;
    save=start;
    while (save->next !=NULL)
    {
        if(save->data == ele)
        {
            cout<<"element at location:"<<i;
            return i;
        }
        ++i;
        save=save->next;
    }
    return -1;
}
//---------------------------------------------------deletion from mid-----------------------------------
void deletion_from_mid()
{
    int ele,pos;
    cout<<"enter element:";
    cin>>ele;
    pos=search_element(ele);
    if(pos==-1)
    {
        cout<<"\nelement not found";
    }
    else
    {
    save=start;
    for(int i=0;i<pos;++i)
    {
        beg=save;
        save=save->next;
    }
    beg->next=save->next;
    delete(save);
    }

}
//----------------------------------------------------insertion from end-------------------------------------
void insertion_from_end(node* new_node)
{
   save=start;
   while(save->next!=NULL)
   {
       save=save->next;
   }
   save->next=new_node;
}
//-------------------------------------------------------insertion from mid-------------------------------------------
void insertion_from_mid(node*new_node)
{
    int ele,pos;
    cout<<"enter element:";
    cin>>ele;
    new_node->data=ele;
    cout<<"enter position:";
    cin>>pos;

    save=start;
    for(int i=0;i<pos;i++)
    {
        beg=save;
        save=save->next;
    }
    beg->next=new_node;
    new_node->next=save;

}
void display()
{
     while(start!=NULL)            //-----------------------printing area---------------------------------
    {
        cout<<"\n"<<start->data;
        start=start->next;
    }
}
#endif // linklist_comp_H
