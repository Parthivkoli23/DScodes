#include<iostream>
using namespace std;

struct node
{
   struct node *prev;
   int data;
   struct node *next;
}*start;

class doubly

{

    public :
    
    void create(int value);
    void insert_beg(int DATA);
    void insert_end(int DATA);
    void insert_after(int DATA , int pos);
    void delete_beg();
    void delete_end();
    void delete_position(int pos);
    void display(struct node *ptr1);
    int count(struct Node *ptr1);
};

void doubly :: create(int value)
{
    int i,DATA;
    struct node *ptr , *ptr1;
    start  = new node;
    
    cout<<"Enter the data of node 1 : ";
    cin>>DATA;
    start -> data = DATA;    
    start -> next = start -> prev = NULL;  
    ptr1 = start; 
    for(i = 1;i<value;i++)
    { 
        ptr  =  new node;
        cout<<"Enter the data of node "<<i+1<<" : ";
        cin>>DATA;
        ptr -> data =  DATA; 
        ptr -> prev =  ptr1;
        ptr -> next =  NULL;
        ptr1 -> next = ptr; 
        ptr1 = ptr; 
    }
}

void doubly::insert_beg(int DATA)  // to Insert at Beginning
{
    struct node *ptr;
    ptr  =  new node;
    ptr -> data =  DATA;
    ptr -> next =  start;
    ptr -> prev =  NULL;
    start -> prev = ptr;
    start = ptr;

}

void doubly::insert_after(int DATA , int pos)
{
    struct node* ptr  = new node , *ptr1  = start; 
	ptr -> data = DATA; 
	for(int i = 0;i<pos-1;i++)
    { 
	    ptr1 = ptr1 -> next;
	}
	ptr -> next = ptr1 -> next;
	ptr -> prev = ptr1;
	if(ptr1 -> next != NULL)
    {
	    ptr1 -> next -> prev = ptr;
	}
	ptr1 -> next = ptr; 	
}

void doubly::insert_end(int DATA) // Insert at end
{
    struct node *ptr, *ptr1;
    ptr1 = start;
    ptr  =  new node;
    ptr -> data =  DATA;
    ptr -> next =  NULL;
    while(ptr1 != NULL)
    {
        if(ptr1 -> next == NULL)
        {
           ptr1 -> next = ptr;
           ptr -> prev = ptr1;
           break;
		}
		ptr1 = ptr1 -> next;       
    }
}

void doubly::delete_beg() // Delete beginning
{
    struct node *ptr;
	ptr = start;
	start = start -> next;
	if(start != NULL)
    {
	start -> prev = NULL;
	}
	cout<<ptr -> data<< " HAS BEEN DELETED";
	delete(ptr);
}

void doubly::delete_position(int pos) //Delete at given Position
{
    struct node *ptr1 = start;
	for(int i = 0;i<pos-1 && ptr1 != NULL;i++)
    { 
	ptr1 = ptr1 -> next;  
	}
	ptr1 -> prev -> next = ptr1 -> next;
	if(ptr1 -> next != NULL)
    {
	ptr1 -> next -> prev = ptr1 -> prev;
	}
	cout<<ptr1 -> data<< " HAS BEEN DELETED";
	delete(ptr1);		
}

void doubly::delete_end()  //delete at end
{
    struct node *ptr1 = start;
	while(ptr1 != NULL)
    {
	if(ptr1 -> next == NULL)
    {
	   cout<<ptr1 -> data<< " HAS BEEN DELETED";
	   ptr1 -> prev -> next = NULL;
	   delete(ptr1);
	   break;
	}
	ptr1 = ptr1 -> next;	
    }
}

void doubly::display(struct node *ptr1) // Display the elements 
{
     while(ptr1 != NULL)
    {
        cout<<ptr1 -> data<<" ";//print current node
        ptr1 = ptr1 -> next; //move to next node, here we can also call it recursively by : display(p -> next);
    }
}


int count(struct node *ptr1){
	int c=0;
    while(ptr1!=NULL){
        c=c+1;
        ptr1=ptr1->next; 
    }
    return c;
}

int main()
{
int value,ch,DATA, pos;
doubly list;
do{
cout<<"\n1.CREATE"<<endl<<"2.DISPLAY"<<endl<<"3.INSERT AT BEGINNING"<<endl
    <<"4.INSERT AT THE END"<<endl<<"5.INSERT AT ANY POSITION"<<endl<<"6.DELETE FROM BEGINNING"<<endl
	<<"7.DELETE FROM END"<<endl<<"8.DELETE FROM ANY POSITION"<<endl<<"9.EXIT"<<endl;
cout<<"ENTER YOUR CHOICE :";
cin>>ch;
cout<<"\n";
switch(ch){
case 1:
	cout<<"HOW MANY NODES YOU WANT TO INSERT : ";
    cin>>value;
    list.create(value);
    break;
case 2:
	cout<<"LIST ELEMENTS : ";
	list.display(start);	
    break;

case 3:
	cout<<"ENTER ELEMENT TO INSERT AT BEGINNING :";
	cin>>DATA;
	list.insert_beg(DATA);
	break;
case 4:
	cout<<"ENTER ELEMENT TO INSERT AT THE END :";
	cin>>DATA;
	list.insert_end(DATA);
	break;
case 5:
	cout<<"AFTER WHAT POSITION YOU WANT TO INSERT ELEMENT :";
	cin>>pos;
	cout<<"ENTER ELEMENT TO INSERT AT POSITION "<<pos+1<<" : ";
	cin>>DATA;

	list.insert_after(DATA,pos);
	break;
case 6:
	list.delete_beg();
	break;
case 7:
	list.delete_end();
	break;
case 8:
	cout<<"ENTER THE POSITION OF THE NODE TO DELETE:";
	cin>>pos;
	list.delete_position(pos);
	break;

case 9:
	return 0;
		
default :
	cout<<"INVALID CHOICE";
	break;
}
}while(ch<=9);
}