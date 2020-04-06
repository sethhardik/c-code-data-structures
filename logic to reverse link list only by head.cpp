SinglyLinkedListNode* save=NULL;
    SinglyLinkedListNode* start=NULL;
    SinglyLinkedListNode* temp=NULL;
    if(head!=NULL){
        save=head;
        while(save!=NULL){
            int a=save->data;
            SinglyLinkedListNode* n =new SinglyLinkedListNode(a);
            n->next=NULL;
            if(start==NULL){
                start=n;
            }
            else{
                n->next=start;
                start=n;
            }
            temp=save;
            save=save->next;
            delete(temp);
            
        }
    while(start!=NULL){
        cout<<start->data<<endl;
        start=start->next;

    }
    }
}
