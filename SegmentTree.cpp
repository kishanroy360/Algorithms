#include<bits/stdc++.h>
#define ll long long
#define lld long long double
#define pb push_back
#define mp make_pair
using namespace std;
void buildTree(int *arr,int *tree,int s,int e,int c){
	if(s==e) {
		tree[c]=arr[s];
		return;
	}
	int mid=(s+e)/2;
	buildTree(arr,tree,s,mid,2*c);
	buildTree(arr,tree,mid+1,e,2*c+1);
    tree[c]=tree[2*c]+tree[2*c+1];
}
void updateTree(int *arr,int *tree,int s,int e,int c,int idx,int value){
	if(s==e){
		arr[idx]=value;
		tree[c]=value;
		return;
	}
	int mid=(s+e)/2;
	if(idx>mid) updateTree(arr,tree,mid+1,e,2*c+1,idx,value);
	else updateTree(arr,tree,s,mid,2*c,idx,value);
	tree[c]=tree[2*c]+tree[2*c+1];
}
int query(int *tree,int s,int e,int c,int left,int right){


	//Completely outside given range
	if(s>right || e<left) return 0;
	//Completely inside given range
	if(s>=left && e<=right) return tree[c];
	//Partially inside and outside the given range
    int mid=(s+e)/2;
    int ans1=query(tree,s,mid,2*c,left,right);
    int ans2=query(tree,mid+1,e,2*c+1,left,right);
    
    return ans1+ans2;
}
int main(){
    int arr[]={1,2,3,4,5};
    int *tree=new int[10];
    buildTree(arr,tree,0,4,1);
    for(int i=1;i<10;i++){
    	cout<<tree[i]<<" ";
    }
    cout<<endl;
    updateTree(arr,tree,0,4,1,2,10);
     for(int i=1;i<10;i++){
    	cout<<tree[i]<<" ";
    }
    cout<<endl;
    int ans=query(tree,0,4,1,2,4);
    cout<<"sum between 2 ans 4 "<<ans;
	return 0;
}
