#include<iostream>
#include<vector>
#include<algorithm>
#include <string>

using namespace std;

int main()
{
    int n,m;
    cin>>n;
    vector<int> nums1;
    vector<char> nums2;

    
    int x;
    int i=0;
   while(i<n)
   {   cin>>x;
    	nums2.push_back(x);
        i++;
   }

  cout<<endl;

   sort(nums2.begin(), nums2.end());
    // sort(nums1.begin(), nums1.end());

   for (int i = 0; i < n; ++i)
   {
     cout<<nums2[i]<<endl;

   }



}