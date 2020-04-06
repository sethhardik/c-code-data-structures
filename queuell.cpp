#include"linklist_comp.h"           // custom header file made for our own use
#include<iostream>

using namespace std;
int main()
{
    char ch;
    node* new_node=NULL;
    int choice,pos,ele;
    //---------------------------------------------- creating link list------------------------
    node* head=new node();
    head->data=0;
    head->next=NULL;
    start=head;
    for(int i=1;i<=5;i++)
    {
        node* n=new node();
        n->data=i;
        n->next=NULL;
        head->next=n;
        head=n;
    }
    save=start;
    do
    {
        cout<<"\n1> Push\n2> Pop\n";
        cin>>choice;
        switch (choice)
        {
        case 1 :
            cout<<"\nPUSH";
            start=save;
            new_node=createnode(100);
            insertion_from_start(new_node);
            beg=start;
            display();
            save=beg;
            break;
        case 2:
            cout<<"\nPOP";
            deletion_from_end();
            beg=start;
            display();
            start=beg;
            break;
        default:
            cout<<"wrong";
        }
        cout<<"\nTo go back to main menu press \"y\" and to quit press \"n\"";
        cin>>ch;
    }while(ch=='y');
}
