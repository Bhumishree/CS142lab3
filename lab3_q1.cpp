#include<iostream>
using namespace std;

class Node {
 public:
 int data;
 Node*next;
 Node*prev;
 
 Node(int value) {
      next=NULL;
      prev=NULL;
      data=value;
   }
 };

class DLL{
   public:
   Node*head;
   Node*tail;
   DLL() {
     head=NULL;
     tail=NULL;
  }

//INSERT
  
   void insert(int value) {
      Node*temp = new Node(value);
     if(head==NULL) {
          head=temp;
      }
     else {
      Node*current=head;
      while (current->next != NULL) {
        current=current->next;
        current->next=temp;
        temp->prev=current;
      }
     }
    }

//INSERT AT

   void insertAt (int pos,int value) {
   Node*current=head;
   int i=1;
   while (i<pos-1) {
     current=current->next;
     i++;
   }
  
  Node*temp= new Node(value);
  temp->data=value;
  temp->next=current->next;
  (current->next)->prev=temp;
  temp->prev=current;
  current->next=temp;
 }
 
//DISPLAY

 void display() {
   Node*current = head;
   Node *last;
   cout<< "print in order :";
   while (current != NULL) {
     cout<<current->data<<"->";
      last = current;
      current=current->next;
    }
    cout<<endl;
 }


//COUNT ITEMS
 
  int counter() {
   int i=1;
    Node*current=head;
    while (current !=NULL) {
     current=current->next;
      i++;
    }
   return i;
  }
    

//DELETE

 void delta() {
    Node*temp=tail;
    Node*current= head;
  while (current->next != tail) {
     current=current->next;
   }
    current->next=NULL;
    tail->prev=NULL;
  delete temp;
}
};


//MAIN FUNCTION

int main() {
  DLL l1;
  
   l1.insert(5);
   l1.insert(10);
   l1.insert(15);
   l1.insert(20);
   l1.display();
   l1.insertAt(1,3);
   l1.display();
   l1.delta();
   l1.display();
   l1.counter();


return 0;
}

    




  
    

 
