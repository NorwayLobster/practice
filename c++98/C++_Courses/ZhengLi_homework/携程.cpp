#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int middleNumberIn2Array(vector<int> arr1,vector<int> arr2){

  int st1= 0;
  int st2= 0;
  int end1 = arr1.size()-1;
  int end2 = arr2.size()-1;
  
  int midIndex1;
  int midIndex2;

  while(st1<end1 || st2<end2){
   midIndex1 = (st1 + end1)/2; 
   midIndex2 = (st2 + end2)/2; 
   if(arr1[midIndex1] == arr2[midIndex2]){
    return arr1[midIndex1];
   }
   
   if (arr1[midIndex1] < arr2[midIndex2]){
    if(((end1-st1)%2 == 0) && ((end2-st2)%2==0)){
     st1 = midIndex1;
     end2 = midIndex2;
    }else {
     st1 = midIndex1+1;
     end2 = midIndex2;
    }
   }else {
    if(((end1-st1)%2 == 0) && ((end2-st2)%2==0)){
     st2 = midIndex2;
     end1 = midIndex1;
    }else {
     st2 = midIndex2+1;
     end1 = midIndex1;
    }
   }
  }
  return (arr1[st1]<arr2[st2]? arr1[st1]:arr2[st2]);
 }

int main()
{
    int n,m;
    cin>>n;
    vector<int> nums1;
    vector<int> nums2;
    int x;
    int i=0;
   while(i<n)
   {   cin>>x;
    	nums1.push_back(x);
        i++;
   }
 
   
    cin>>m;
	int j=0;
    
   while(j<m)
   {
       cin>>x;
       nums2.push_back(x);
       j++;
   }
    cout<<middleNumberIn2Array(nums1,nums2)<<endl;
}


