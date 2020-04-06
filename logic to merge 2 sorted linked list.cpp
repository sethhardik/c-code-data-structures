SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* save1=NULL;
    SinglyLinkedListNode* save2=NULL;
    SinglyLinkedListNode* save=NULL;
    SinglyLinkedListNode* start=NULL;
    if(head1==NULL){
        return head2;
    }
    else if(head2==NULL){
        return head1;
    }
    else{
        if(head1->data<=head2->data){
            SinglyLinkedListNode* node=new SinglyLinkedListNode(head1->data);
            node->next=NULL;
            start=node;
            save1=head1->next;
            save2=head2;
        }
        else{
            SinglyLinkedListNode* node=new SinglyLinkedListNode(head2->data);
            node->next=NULL;
            start=node;
            save2=head2->next;
            save1=head1;
        }
    }
    save=start;
    while(save1!=NULL && save2!= NULL){
        if(save1->data<=save2->data){
            SinglyLinkedListNode* node=new SinglyLinkedListNode(save1->data);
            node->next=NULL;
            save->next=node;
            save1=save1->next;
            save=save->next;
        }
        else{
            SinglyLinkedListNode* node=new SinglyLinkedListNode(save2->data);
            node->next=NULL;
            save->next=node;
            save2=save2->next;
            save=save->next;
        }
    }
    if(save1!=NULL){
        while(save1!=NULL){
            save->next=save1;
            save1=save1->next;
            save=save->next;
        }
    }
    else if(save2!=NULL){
        while(save2!=NULL){
            save->next=save2;
            save2=save2->next;
            save=save->next;
        }
    }
    return start;
    
}
