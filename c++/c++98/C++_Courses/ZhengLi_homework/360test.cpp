#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

 int n,t,x;
 cin>>n>>t;
 vector<int> nums;
 for(int i=0;i<n;i++)
 {
  cin>>x;
  nums.push_back(x);
 }



 sort(nums.begin(),nums.end());

 cout<<endl;

 //  for(int i=0;i<n;i++)
 // {
 //  cout<<nums[i]<<"\n";
 // }
 int k=0,i=0,temp=0;
 do
 {
 	temp=k;
 k+=nums[i];
 i++;
 }
 while(k<t && i<=n);
// cout<<k<<" "<<t<<' '<<temp<<endl;
 if(i<n)
  k=temp + nums[nums.size()-1];

 cout<<k<<endl;
 return 0;
}



for (int i = 0; i < count; ++i)
{
	for (int i = 0; i < ; ++i)
	{
		/* code */
	}
}

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    
    int n,m;
    cin>>n;
    int a[n];
   while(i<n)
   {   cin>>a[i];
       i++;}
    cout<<endl;
   
    cin>>m;
    int b[m];
	int j=0
   while(j<m)
   {
       cin>>b[j];
       j++;
   }
    
    //sort?
    
    
    
    int c[m+n];
        
    for(int t=0; t<m+n; ++t){
        
    for (int i = 0; i < n; ++i)
{
	for (int j = 0; j<m ; +j)
	{
        if (a[i]>b[j])
    {
        c[i]=a[i];
    }
    else if (a[i]=b[i]){
    c[i]=b[i];
        continue;
        }
        else {
            c[i]=
        }
        
	
	}
}
}
   
    
    
    
    

    
    return 0;
    
}