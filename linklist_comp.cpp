#include<iostream>

using namespace std;            // used to replace std:: from all the statement that we are using like cout and cin

class node{                          //class to make link list
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
//--------------------------------------------------main function-------------------------------------
int main()
{
    node* new_node=NULL;
    int choice,pos,ele;
    //---------------------------------------------- creating link list------------------------
    node* head=new node();
    head->data=0;
    head->next=NULL;
    start=head;
    for(int i=1;i<=10;i++)
    {
        node* n=new node();
        n->data=i;
        n->next=NULL;
        head->next=n;
        head=n;
    }
    //-------------------------------------------------- menu-----------------------------------
    cout<<"\t\t\tMain menu\n1> insertion \n2> deletion \n3> search\n";
    cin>>choice;
    switch(choice)
    {
    case 1:   //------------------------------------- insertion----------------------------------
        cout<<"\t\t\tSecondary Menu\n1. from start\n2. from end\n3. from mid\n";
        cin>>choice;
        new_node=createnode(100);
        switch (choice)
        {
        case 1:               //----------beg---------------
            insertion_from_start(new_node);
            break;
        case 2:             // ----------end---------------
            insertion_from_end(new_node);
            break;
        case 3:            //-----------mid----------------
            insertion_from_mid(new_node);
            break;
        default: cout<<"wrong";
        }

        break;
    case 2: //-----------------------------------------deletion------------------------------------
        cout<<"\t\t\tSecondary Menu\n1. from start\n2. from end\n3. from mid\n";
        cin>>choice;
        switch(choice)
        {
        case 1: //---------------start------------------
            deletion_from_start();
            break;
        case 2: //--------------end--------------------
            deletion_from_end();
            break;
        case 3: //-------------mid---------------------
            deletion_from_mid();
            break;
        default: cout<<"wrong";
        }

        break;
    case 3:                  //----------------------------------------- search---------------------------
        cout<<"enter element:";
        cin>>ele;
        pos=search_element(ele);
        break;
    default: cout<<"wrong input";
    }
    while(start!=NULL)            //-----------------------printing area---------------------------------
    {
        cout<<"\n"<<start->data;
        start=start->next;
    }
    return 0;
}  //---------------------------------------------------------end main-------------------------------------
//-----------------------------------------------insertion from start-------------------------------------------------
void insertion_from_start(node* new_node)
{
    save=start;
    start=new_node;
    new_node->next=save;
    save=NULL;

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
    start=save;;
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
