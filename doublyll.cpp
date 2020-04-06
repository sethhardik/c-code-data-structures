#include<iostream>

using namespace std;
//--------------------------------------------class node------------------------------------------------------
class node
{
public:
    int data;
    node* next;
    node* pre;
}*start,*beg,*save,*last;
//-----------------------------------------------functions------------------------------------------------------
void insert_from_start(node*);
void insert_from_mid(node*);
void insert_from_last(node*);
void delete_from_start();
void delete_from_mid();
void delete_from_last();
node* createnode(int d);
void display_start_end(int);
int search_ele(int,int);
//--------------------------------------------------start of main function-------------------------------------------
int main()
{
    node* new_node=NULL;
    int choice,ele,pos;
//---------------------------------------------- creating link list------------------------
    node* head=new node();
    head->data=0;
    head->next=NULL;
    head->pre=NULL;
    start=head;
    for(int i=1;i<=10;i++)
    {
        node* n=new node();
        n->data=i;
        n->next=NULL;
        n->pre=head;
        head->next=n;
        head=n;
        last=head;
    }
    save=start;
//-----------------------------------------------------main menu ---------------------------------------------------------
         cout<<"\n\t\t\tmain menu\n1> first to last print\n2> last to first print\n3> insert\n4> delete\n5> search\n";
        cin>>choice;
        switch(choice)
        {
        case 1:  //------------------display from start------------------------------
            display_start_end(2);
        break;
        case 2:  //-----------------display from end---------------------------------
            display_start_end(1);
        break;
        case 3:  //-------------------------insert menu-------------------------------------------------------------------
            cout<<"\n\t\t\tinsert menu\n1. start\n2. end\n3. mid\n";
            cin>>choice;
            new_node=createnode(100);
            switch(choice)
            {
            case 1:   //------------------insert from start--------------
                insert_from_start(new_node);
                display_start_end(2);
                cout<<"\n\nopposite\n\n";
                display_start_end(1);
                break;
            case 2:   //-----------------insert from end-----------------
                insert_from_last(new_node);
                display_start_end(2);
                cout<<"\n\nopposite\n\n";
                display_start_end(1);
                break;
            case 3: //------------------insert from mid------------------
                insert_from_mid(new_node);
                display_start_end(2);
                cout<<"\n\nopposite\n\n";
                display_start_end(1);
                break;
            default:
                cout<<"\nwrong";
            }
        break;
        case 4:   //------------------------------------------delete menu----------------------------------------------------
            cout<<"\n\t\t\tdelete menu\n1. start\n2. end\n3. mid\n";
            cin>>choice;
            switch(choice)
            {
            case 1:   //--------------------delete from start---------------------
                delete_from_start();
                display_start_end(2);
                cout<<"\n\nopposite\n\n";
                display_start_end(1);
                break;
            case 2:  //---------------------delete from end-----------------------
                delete_from_last();
                display_start_end(2);
                cout<<"\n\nopposite\n\n";
                display_start_end(1);
                break;
            case 3:  //---------------------delete from mid----------------------
                delete_from_mid();
                display_start_end(2);
                cout<<"\n\nopposite\n\n";
                display_start_end(1);
                break;
            default:
                cout<<"\nwrong";
            }
            break;
        case 5:   //---------------------------------------------------search menu----------------------------------------
            cout<<"\n\t\t\tsearch menu\n1. start\n2. end\n";
            cin>>choice;
            cout<<"\nenter element to search:";
            cin>>ele;
            switch(choice)
            {
            case 1:  //------------------search from start---------------------
                 pos=search_ele(ele,1);
                 break;
            case 2:  //-----------------search from last-----------------------
                pos=search_ele(ele,2);
                break;
            default:
                cout<<"\nwrong\n";
            }
            break;
        default:
            cout<<"\nwrong input";
        }
   return 0;
}
//----------------------------------------------------------end main-----------------------------------------------------
//-----------------------------------------------------------create node-------------------------------------------------
node* createnode(int d)
{
    node* new_node=new node();
    new_node->data=d;
    new_node->next=NULL;
    new_node->pre=NULL;
    return new_node;
}
//---------------------------------------------------------------insert-------------------------------------------------------------
void insert_from_start(node* new_node)   //------------------from start---------------
{
    save=start;
    start=new_node;
    save->pre=new_node;
    new_node->next=save;
}
void insert_from_last(node* new_node)   //-----------------from last-----------------
{
    save=last;
    last=new_node;
   save->next=new_node;
   new_node->pre=save;
}
void insert_from_mid(node* new_node)    //----------------from mid-----------------
{
    int ele,pos;
    cout<<"enter element:";
    cin>>ele;
    new_node->data=ele;
    cout<<"enter position from start:";
    cin>>pos;
    save=start;
    for(int i=0;i<pos;i++)
    {
        beg=save;
        save=save->next;
    }
    beg->next=new_node;
    new_node->pre=beg;
    new_node->next=save;
    save->pre=new_node;
}
//-------------------------------------------------------delete-----------------------------------------------------------------
void delete_from_start()  //------------delete from start-----------
{
    save=start;
    save=save->next;
    save->pre=NULL;
    delete(start);
    start=save;
}
void delete_from_last()  //------------delete from last--------------
{
    save=last;
    save=save->pre;
    save->next=NULL;
    delete(last);
    last=save;
}
void delete_from_mid()  //------------delete from mid--------------
{
    int ele,pos;
    cout<<"enter element:";
    cin>>ele;
    pos=search_ele(ele,1);
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
    (beg->next)->pre=save->pre;
    delete(save);
    }
}
//----------------------------------------------------function to display-------------------------------------------------------
void display_start_end(int a)
{
    if(a==1)      //----------------print last to first-----------------
    {
        while(last!=NULL)
        {
            cout<<"\n"<<last->data;
            last=last->pre;
        }
    }
    else if(a==2)             //------------------print first to last----------------
    {
        while(start!=NULL)
        {
            cout<<"\n"<<start->data;
            start=start->next;
        }
    }
}
//--------------------------------------------------------------searching--------------------------------------------------
int search_ele(int ele,int cn)
{
    int i=0;
    if(cn==1)        //-----------------------------search from start---------------------------------------
    {
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
    }
    else if (cn==2)    //--------------------------------search from end-------------------------------
    {
        save=last;
        while (save->pre !=NULL)
    {
        if(save->data == ele)
        {
            cout<<"element at location:"<<i;
            return i;
        }
        ++i;
        save=save->pre;
    }
    }
    return -1;
}
