#include <iostream>
#include <cstring>
using namespace std;


struct node{
    char data[20];
    struct node * next;
    struct node * prev;
}*head=NULL,*tail=NULL,*curr=NULL;
//At last insertion.
void insert(){
    struct node *temp,*neww;
    neww=(struct node *)(malloc(sizeof(struct node)));
    fflush(stdin);
    cout <<"Enter song name:";
    cin >> neww->data;
    neww->next=0;
    neww->prev=0;
    if(head==NULL){
        head=neww;
        tail=neww;
        neww->next=tail;
        neww->prev=head;
    }
    else{
        neww->prev=tail;
        neww->next=head;
        tail->next=neww;
        head->prev=neww;
        tail=neww;
    }
    cout <<"Song inserted.";
}
void display(){
    struct node *temp;
    if(head==NULL){
        cout << "Empty Play List.";
    }
    else{
        temp=head;
        int i=1;
        cout <<"**Playlist**\n";
        do{
            printf("%d.%s\n",i,temp->data);
            i++;
            temp=temp->next;
        }while(temp!=head);
    }
}
void delete_(){
    struct node *neww;
    neww=head;
    if(neww==NULL){
        cout <<"Playlist Empty!!";
    return;
    }
    char file[20];
    cout <<"Enter Song to be deleted:";
    cin >>file;
    int ch=0;
    do{
        if(strcmp(file,neww->data)==0){
            ch=1;
            neww->prev->next=neww->next;
            neww->next->prev=neww->prev;
        if(neww==tail && neww!=head){
            tail=neww->prev;
        }
        else if(neww==head && neww!=tail){
            head=neww->next;
        }
        else if(neww==head && neww==tail){
            head=NULL;
            tail=NULL;
        }
            cout <<"File deleted!!";
            free(neww);
            break;
        }
        else{
            neww=neww->next;
    }
}
    while(neww!=head);
    if(ch==0){
        cout << "File not found";
    }
}


void play_next();

void play_next() {
    if (head==NULL && tail==NULL)
    {
        cout <<"Empty Playlist";
    }
    else
    {
        if (curr == NULL)
        {
            curr=head;
            cout <<"Playing song "<<curr->data;
        }
        else
        {
            curr=curr->next;
            cout <<"Playing song "<<curr->data;
        }
    }
}

void play_previous()
{
    if (head==NULL && tail==NULL)
    {
        cout <<"Empty Playlist.";
    }
    else
    {
        if (curr == NULL)
        {
            curr=head;
            cout << "Playing song " << curr->data;
        }
        else
        {
            curr=curr->prev;
            cout <<"Playing song "<<curr->data;
        }
    }
}
void play_given(){
    if(head==NULL){
        cout <<"Empty playlist.";
    }
    else{
        cout <<"Enter file: ";
        char file[20];
        while ((getchar())!='\n');
        cin >> file;
        int ch=0;
        struct node *temp=head;
        do{
            if(strcmp(file,temp->data)==0){
                cout <<"Playing song "<<temp->data;
                curr=temp;
                ch=1;
                break;
            }
            else{
                temp=temp->next;
                curr=temp;
            }
        }while(temp!=head);
        if(ch==0){
            cout <<"File not found.";
        }
    }
}
void play_first(){
    struct node *temp;
    if(head==NULL){
        cout <<"Empty play list.";
    }
    else{
        temp=head;
        curr=temp;
        cout <<"Playing song "<<temp->data;
    }
}
void play_last(){
    struct node *temp;
    if(tail==NULL){
        cout <<"Empty play list.";
    }
    else{
        temp=tail;
        curr=temp;
        cout <<"Playing song "<<temp->data;
    }
}
int main()
{
    int ch;
    while(1){
        cout << "\n***MENU***";
        cout <<"\n1--Insert Song.";
        cout <<"\n2--Delete Song.";
        cout <<"\n3--Display List.";
        cout <<"\n4--Play Next Song.";
        cout <<"\n5--Play Previous Song.";
        cout <<"\n6--Play First Song.";
        cout <<"\n7--Play Last Song.";
        cout <<"\n8--Play Given Song.";
        cout <<"\n9--Exit.";
        cout <<"\nEnter your choice:";
        cin >> ch;
        switch(ch){
            case 1:
                insert();
                break;
            case 2:
                delete_();
                break;
            case 3:
                display();
                break;
            case 4:
                play_next();
                break;
            case 5:
                play_previous();
                break;
            case 6:
                play_first();
                break;
            case 7:
                play_last();
                break;
            case 8:
                play_given();
                break;
            case 9:
                exit(1);
            default:
                printf("Invalid choice!!!");
                break;
        }
    }
}