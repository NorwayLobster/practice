
int main(int argc, const char * argv[]) {
   int a,b;
   char c,d;
   
   cin>>a>>b>>c>>d;
   int swap(int &a,int &b);
   int swap(char &a,char &b);

   // insert code here...
   std::cout << "Hello, World!\n";
   cout<<"a="<<a<<"\n";
   cout<<"b="<<b<<"\n";
   swap(a,b);
   cout<<"\n";
   cout<<"a="<<a<<"\n";
   cout<<"b="<<b<<"\n";

   cout<<"c="<<c<<"\n";
   cout<<"d="<<d<<"\n";
   swap(c,d);
   cout<<"\n";
   cout<<"c="<<c<<"\n";
   cout<<"d="<<d<<"\n";


//    double e;
//    cin>>e;
//    cout<<"e="<<e<<"\n";
//    cout<<d<<"\n";
//    long f;
//    double g;
//    cout<<"a="<<a<<"\n";
//    cin>>d>>e>>f>>g;
//    cout<<"a="<<a<<"\n";
//    cout<<"b="<<b<<"\n";
//    cout<<c<<"\n";
//    cout<<"d="<<d<<"\n";
//    cout<<"e="<<e<<"\n";
   return 0;
}

int swap(int &a,int &b){
   int temp;
   temp=a;
   a=b;
   b=temp;
   return 0;
   
}


int swap(char &a,char &b){
   char temp;
   temp=a;
   a=b;
   b=temp;
   return 0;
   
}

