#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n,num=0;
    cin>>n;
    int a[n];
    cout<<"please initialize the array a."<<endl;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    
    for (int i = 0; i <n/2+1; ++i)
    {
        num=0;
        for (int j = i+1; j < n; ++j)
        {
            if(a[i]==a[j])
            {
                ++num;
                if(num>=n/2)
                {
                    cout<<a[i];
                    break;
                }
                
                
            }
        }
        
    }
    cout<<endl;
    
    return 0;
}
