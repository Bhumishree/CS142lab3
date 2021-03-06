#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node*next;
  Node(int value) {
      next=NULL;
      data=value;
    }
};

class Circlist{
   public:
   Node*head;
  Node*tail;
   Circlist() {
      head=NULL;
     tail=NULL;
   }

//INSERT
  void insrt(int value) {
   Node*temp= new Node(value);
      if(head==NULL) {
        head=temp;
      }
      else {
               tail->next=temp;
         }
       tail=temp;
       temp->next=head;
      }

//INSERT AT
  void insertAt(int pos,int value) {
   Node*current=head;
    int i=1;
    while (i<pos-1) {
      i++;
     current=current->next;
    }
  Node*temp=new Node(value);
  temp->data=value;
  temp->next=current->next;
  current->next=temp;
 }

//DELETE

void delta() {
 Node*temp=tail;
 Node*current=head;
   while(current->next!=tail){
      current=current->next;
    }
   current->next=NULL;
   tail=current;
   tail->next=head;
   delete temp;
}

//DELETE AT

void deleteAt (int pos) {
 Node*current=head;
  int i=1;

 Node*temp2=head;
 while(i<pos)  {
   temp2=temp->next;
    i++;
  }
 Node*temp=head;
 while(i<pos-1) {
  temp=temp->next;
     i++;
  }

while(i<pos) {
  current=current->next;
   i++;
  }
 temp->next=current ;
 delete temp2;
}

//COUNT ITEMS
 int counter() {
   int i=1;
   Node*current=head;
   while(current!=head){
      cout<<current->data<<"->";
      current=current->next;
       }
   cout<<endl;
}

//DISPLAY
   void display() {
      Node*current = head;
      if(current==NULL){
          cout<< "No elements"<<endl;
          return;
       }
     else {
      while(current->next!= head){
        cout<< current->data<< "->";
        current= current->next;
       }
        cout<<current->data;
        cout<<endl;
      }
   }
};

//MAIN FUNCTION

  int main() {
   Circlist l1;
    l1.insrt(5);
    l1.insrt(10);
    l1.insrt(15);
    l1.insrt(20);
    l1.display();
    l1.insertAt(1,3);
    l1.display();
    l1.delta();
    l1.display();
    l1.deleteAt(2);
    l1.display();
    l1.counter();

  return 0;
 }
