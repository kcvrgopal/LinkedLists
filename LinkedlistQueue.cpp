#include <iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
class Linkedlist
{
	private:
	int s;
	node *head,*tail;
	public :
	Linkedlist()
	{
		s=0;		
		head=NULL;
		tail=NULL;
	}
	void insert(int d)
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
	void remove()
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
	void display()
	{
		cout<<"Here you go\n";
		node *p=new node;
		p=head;
		int l=0;
		while(p!=NULL)
		{
			cout<<p->data<<"->";
			p=p->next;
			l++;
		}
		//cout<<tail->data<<endl;
		cout<<"Done!\n";
	}
	void siz()
	{
		
		cout<<"Size : "<< s<<endl;
	}
	~Linkedlist()
	{
		
	}
};
int main()
{
	Linkedlist l;
	char ch;
	int o,data;
	cout<<"MENU"<<endl;
	do{
		cout<<"1. Insert\n2. Remove\n3. Display\n4. Size\n";
		cin>>o;
		switch(o)
		{
			case 1: cout<<"Enter element to insert"<<endl;
					cin>>data;
					l.insert(data);
					break;
			case 2: l.remove();
					break;
			case 3: l.display();
					break;
			case 4: l.siz();
					break;
			default: cout<<"Choose a correct option\n";
		}
		cout<<"Do you want to continue? Y or N\n";
		cin>>ch;
	}while(ch=='Y'||ch=='y');
	return 0;
}
