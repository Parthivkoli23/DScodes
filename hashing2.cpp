#include <iostream>
using namespace std;
class hash 
{
	public:
		int max,x,key,a[10],j;
		
	void directhashing(int);
	void subtraction(int);
	void divisionmodulo(int);
	void foldshift(int);
	//void foldboundry(int);
	void linearprob(int,int);
	void display(int);
	
};

void hash::directhashing(int n)
{
	cout<<"entre0 key\n";
	for (int i = 0; i<10; i++)
	cout<<a[i];
	for(int key=0;key<n;key++)
	{
		cin>>x;
		a[x]=x;
		
	}
	display(n);
	
}
void hash::subtraction(int n)
{
	int b,index;
	cout<<"Enter the value to be subtracted";
	cin>>b;
	for (int i=0;i<n;i++)
	{
		cin>>x;//x is th key 
		index=x-b;
		a[index]=x;
	}
	display(n);

}
void hash::divisionmodulo(int n)
{
	for(int i=0;i<n;i++)
	{
		cin>>x;//x is a key
		j=x%10;
		if(a[j]==-1)
		a[j]=x;
		else 
		linearprob(j,x);
		
	}
	display(n);
}
void hash::foldshift(int n)
{
	int k,digit=1, hashval=0,array_size=10;
	k=array_size;
	while(k>0)
	{
		digit*=10;
		k=k/10;
	}
	for(int i=0;i<n;i++)
	{
		cin>>x;
		key=x;
		while(key>0)
		{
			hashval=hashval+key%digit;
			key=key/digit;
		}
		hashval=hashval%digit;
		hashval=hashval%array_size;
		
		if (a[hashval]=-1)
		a[hashval]=x;
		else 
		linearprob(hashval,x);
		
	}
	display(n);	
}
void hash::linearprob(int j, int x)
{
	while(a[j]!=-1)
	j=(j+1)%10;
	a[j]=x;
}
void hash::display(int n)
{
	cout<<"Elements are";
	for (int i=0;i<10;i++)
	cout<<"\nposition:"<<i<<"element:"<<a[i];
	
}
int main()
{
	hash h1;
	int key,c,n;
	cout<<"enter number of keys\n";
	cin>>n;
	for (int i=0;i<10;i++)
	h1.a[i]=-1;
	cout<<"1.direct hashing\n";
	cout<<"2.subtraction\n";
	cout<<"3.division modulo\n";
	cout<<"4.fold shift\n";
	cout<<"enter ur choice";
	cin>>c;
	switch(c)
	{
		case 1:
			{h1.directhashing(n);
			break;
			}
			case 2:{ h1.subtraction(n);
				break;
			}
			case 3:{h1.divisionmodulo(n);
				break;
			}
			case 4:{h1.foldshift(n);
				break;
			}
			default:cout<<"Enter correct choice:";
			
	}
	return 0;
}
