/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2021-01-27 20:30:08
 * @LastEditors: ChengWang
 * @LastEditTime: 2021-01-27 14:03:12
 * @FilePath: /practice/algorithm/interview/next_&_find-baidu.cc
 */
//sorted vector: small to big, no duplicate element
//next(): 
//find(target):  x<=target return x;
//lower_bound: 
class  A{
  public:
  A(const vector<int>& a)
 :index(a.size())
 ,v(a)
  {}
 void push(){
   v.push_back();
 }
  int next(){
    if(index==0){
      return -1;
    }
    index--;
    return v[index];
  }
  int find(int target){
    // int res_index1;
    auto iter=lower_bound(v.begin(),v.end(), target);
    if(v.end()!=iter){
       int d=distance(iter,v.begin());
      if(*iter==target){
       index=d;
      }else{
        if(d==0){
          return -1;
        }
        index=d-1;
      }
    }else{
      index=v.size()-1;
    }
    return v[index1];
  }
  private:
    int index;
    vector<int> v;
};