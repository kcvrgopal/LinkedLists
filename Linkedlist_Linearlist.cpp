#include <iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
class Linkedlist_Linearlist
{
	private:
	int s;
	node *head,*tail;
	public :
	Linkedlist_Linearlist()
	{
		s=0;		
//		head=new node;
//		tail=new node;
		head=tail=NULL;
	}
	void insertAtPosition(int d, int pos)
	{
		node *p=new node;
		p->data=d;
			node *temp=head;
			node *temp2;
			for(int i=0;i<pos-2;i++)
			{
				temp=temp->next;
			}
			temp2=temp->next;
			temp->next=p;
			p->next=temp2;
		s++;
	}
	void remove()
	{
		if(head==tail)
		{
			head=tail=NULL;
		}
		else
		{
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
			bp->next=NULL;
		}
		s--;
	}
	
	void removeAtPosition(int pos)
	{
		if(pos==1)
		{
			head=tail=NULL;
		}
		else
		{
			cout<<"In else"<<endl;
			node *temp=new node;
			node *temp2=new node;
			temp=temp2=head;
			cout<<head->data<<"&&"<<temp->data<<"&&"<<temp2->data<<endl;

			for(int i=0;i<pos-2;i++)
			{
				temp=temp->next;
				cout<<"first\n";
			}
			cout<<temp->data;
			for(int j=0;j<pos;j++)
			{
				temp2=temp2->next;
			//	cout<<"second\n";
			}
			cout<<temp2->data;
		//	cout<<temp->data<<"&&"<<temp2->data<<endl;
			temp->next=temp2;
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
	void insert(int d)
	{
		node *p=new node;
		p->data=d;
		if(head==NULL)
		{
			head=p;
			tail=head;
		}
		else
		{
			tail->next=p;
		}
		tail=p;
		tail->next=NULL;
		s++;
	}
	void siz()
	{
		
		cout<<"Size : "<< s<<endl;
	}
	~Linkedlist_Linearlist()
	{
		
	}
};
int main()
{
	Linkedlist_Linearlist l;
	char ch;
	int o,data,pos;
	cout<<"MENU"<<endl;
	do{
		cout<<"1. Insert\n2. Remove\n3. Display\n4. Size\n5. Insert at Some Position\n6. Delete at Some Position\n";
		cin>>o;
		switch(o)
		{
			case 5: cout<<"Enter element to insert"<<endl;
					cin>>data;
					cout<<"Enter the position to insert"<<endl;
					cin>>pos;
					l.insertAtPosition(data,pos);
					break;
			case 1: cout<<"Enter element to insert"<<endl;
					cin>>data;
					l.insert(data);
					break;
			case 2: l.remove();
					break;
			case 6: cout<<"Enter the position to remove"<<endl;
					cin>>data;
					l.removeAtPosition(pos);
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
