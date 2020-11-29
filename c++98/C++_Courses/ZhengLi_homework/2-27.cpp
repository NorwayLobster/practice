#include <iostream>
using namespace std;

// int main(){
//  int a;
//  Again: cout<<"你考了多少?(0~100.)"<<endl;
   
//     cin>>a;

//     if (a<0||a>100)
//     	cout<<"invalid input"<<endl;
//     else if (a<60)
//     	cout<<"cha"<<endl;
//     else if (a<80)
//     	cout<<"zhong"<<endl;
//     else if (a<90)
//     	cout<<"liang"<<endl;
//     else 
//     	cout<<"you"<<endl;

//     return 0;
// }











//worng code 

// int main(){
//  const int a;
//  Again: cout<<"你考了多少?(0~100.)"<<endl;
   
//     cin>>a;
//     switch(a){


//     case a<60:
//     	cout<<"cha"<<endl;
// 	case a<80:
//     	cout<<"zhong"<<endl;
// 	case a<90:
//     	cout<<"liang"<<endl;
//     	case a<=100:
//     	cout<<"you"<<endl;
//     default: // case (a<0||a>100):
//     	cout<<"invalid input"<<endl;}

//     return 0;
// }





int main(){
	int score,a;
 cout<<"你考了多少?(0~100.)"<<endl;
     cin>>score;
 	if(score<0 || score>100)
       cout<<"invalid input,please input a number between 0 and 100."<<endl;
   else 
   {
    a=score/10;
    switch(a){


    case 10:
    case 9 :
    	cout<<"you"<<endl;break;

	case 8:
	cout<<"liang"<<endl;break;

	case 7:
	case 6:
		cout<<"zhong"<<endl;break;

    	
    default:     	cout<<"cha"<<endl;// case (a<0||a>100):
    	}
	}//else
    return 0;
}





