#include<iostream>
using namespace std;
void TOH(int n,char fm,char to,char us,int &cnt)
{
	if(n==0) return;
	TOH(n-1,fm,us,to,cnt++);
	cout<<"ring # "<<n<<" "<<fm<<" to "<<to<<" using "<<us<<endl;
	TOH(n-1,us,to,fm,cnt++);
}
int main()
{
	inr cnt=0;
	TOH(3,'A','B','C',cnt);
}
