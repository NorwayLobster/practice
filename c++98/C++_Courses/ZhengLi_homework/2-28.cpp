#include <iostream>
using namespace std;

int main(){
 char a,b;
cout<<"Menu:A(dd) D(elte) S(ort) Q(uit)"<<endl;
   

while(cin>>b){
    a=toupper(b);
    if (a=='A'){
    	   cout<<"data was added."<<endl;
           continue;}
    else if (a=='D'){
    	cout<<"data was deleted."<<endl;
     continue;}
    else if (a=='S'){
    	cout<<"data was sorted."<<endl;
     continue;}
    else if (a=='Q')
    	break;
    else 
    {
    cout<<"invalid input"<<endl;
    continue;}
 }//while

    return 0;
}













// int main(){
//     char a;
//     cout<<"Menu:A(dd) D(elte) S(ort) Q(uit)"<<endl;
   
// cin>>a;
//     switch(a){
//     case 'A':
//     {
//      cout<<"data was added."<<endl;break;
//      }
// 	case 'D':
//     	cout<<"data was deleted."<<endl;break;
// 	case 'S':
//     	cout<<"data was sorted."<<endl;break;
//     case 'Q':
//     	break;
//     default: 
//     	cout<<"invalid input"<<endl;}

//     return 0;
// }









// int main(){
//     char a;
//     // cout<<"Menu:A(dd) D(elte) S(ort) Q(uit)"<<endl;
   
//     while(cout<<"Menu:A(dd) D(elte) S(ort) Q(uit)"<<endl,cin>>a){
//                switch(toupper(a)){
//     case 'A':
//     {
//      cout<<"data was added."<<endl;break;
//      }
//     case 'D':
//         cout<<"data was deleted."<<endl;
//         break;
//     case 'S':
//         cout<<"data was sorted."<<endl;break;
//     case 'Q':
//         exit(0);
//         // break;
//     default: 
//         cout<<"invalid input"<<endl;}
//         // if (a=='Q')
//         //     break;
//         continue;
//     }//while

//     return 0;
// }