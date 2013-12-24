#include <iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
class Linkedlist_Dequeue
{
	private:
	int s;
	node *head,*tail;
	public :
	Linkedlist_Dequeue()
	{
		s=0;		
		head=NULL;
		tail=NULL;
	}
	void insertAtEnd(int d)
	{
		node *p=new node;
		p->data=d;
		if(head==NULL)
		{
			head=p;
			//head->next=NULL;
			cout<<"First"<<endl;
			tail=head;
		}
		else
		{
			
			tail->next=p;
			//tail=p;
		}
		tail=p;
		p->next=NULL;
		cout<<"head->data : "<<head->data<<" tail : "<<tail->data<<endl;
		s++;
	}
	void insertAtBeg(int d)
	{
		node *temp=new node;
		temp->data=d;
		if(head==NULL)
		{
			head=temp;
			//head->next=NULL;
			//cout<<"First"<<endl;
			tail=head;
		}
		else
		{
			//cout<<head->data<<"&"<<head->next<<endl;
			temp->next=head;
			head=temp;
		}
	}
	void removeFromBeg()
	{
		if(head==tail)
		{
			delete head;
			delete tail;
		}
		else
		{/*
			node *p=new node;
			node *bp=new node;
			p=head->next;
			bp=head;
			while(p->next!=NULL)
			{
				p=p->next;
				bp=bp->next;
			}
			tail=bp;
			bp->next=NULL;*/
			head=head->next;
		}
		s--;
	}
	void removeFromEnd()
	{
		if(head==tail)
		{
			head=tail=NULL;
		}
		else
		{
			
			node *p=head->next;
			node *bp=head;
			while(p->next!=NULL)
			{
				p=p->next;
				bp=bp->next;
			}
			tail=bp;
			tail->next=NULL;
		}
	}
	void display()
	{
		if(s!=0)
		{
			cout<<"Here you go\n";
			node *p=new node;
			p=head;
			int l=0;
			while(p!=tail)
			{
				cout<<p->data<<"->";
				p=p->next;
				l++;
			}
			cout<<tail->data<<endl;
			cout<<"Done!\n";
			
		}
		else
		{
			cout<<"No Elements to display\n";
		}
	}
	void siz()
	{
		
		cout<<"Size : "<< s<<endl;
	}
	~Linkedlist_Dequeue()
	{
		
	}
};
int main()
{
	Linkedlist_Dequeue l;
	char ch;
	int o,data;
	cout<<"MENU"<<endl;
	do{
		cout<<"1. Insert in the Front\n2. Insert at End\n3. Delete from beginning\n4. Delete from End\n5. Display\n";
		cin>>o;
		switch(o)
		{
			case 1: cout<<"Enter element to insert"<<endl;
					cin>>data;
					l.insertAtBeg(data);
					break;
			case 2: cout<<"Enter element to insert"<<endl;
					cin>>data;
					l.insertAtEnd(data);
					break;
			case 3: l.removeFromBeg();
					break;
			case 4: l.removeFromEnd();
					break;
			case 5: l.display();
					break;
			default: cout<<"Choose a correct option\n";
		}
		cout<<"Do you want to continue? Y or N\n";
		cin>>ch;
	}while(ch=='Y'||ch=='y');
	return 0;
}