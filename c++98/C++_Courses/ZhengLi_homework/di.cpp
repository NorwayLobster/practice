#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main(int argc, char const *argv[])
{	

    int m,n,k,t=0;
    cin>>m>>n>>k;
    vector<int> ans;
    vector<vector<int> > mp = vector<vector<int> > (m,vector<int> (n,0));
    // vector<vector<int>> mp = vector<vector<int> > 临时无名对象名(m,vector<int> 无名临时对象名(n,0));

    int dre[4][2];
    //down
    dre[0][0]=0;//x 
    dre[0][1]=-1;//y 
    dre[1][0]=1;dre[1][1]=0;//right
    dre[2][0]=-1;dre[2][1]=0;//left
    dre[3][0]=0;dre[3][1]=1;//up
    while(t<k){
        int x,y;
        cin>>x>>y;
        if(x>=m||x<0 || y>=n ||y<0)
        {//超过边界 
                if(ans.size()!=0)          
                ans.push_back(ans[ans.size()-1]);
                else ans.push_back(0);
            t++;
        	continue;
        }


// tesy the addLand-ed point every round
        //addLand makes the value of point(x,y) frome 0 to 1
        if(!mp[x][y])// not 1 i.e. the point is addLanded by first time.
        {
            int nx,ny,cnt1=0,cnt2=0;



        	for(int i=0;i<4;i++)
            {
                nx = x+dre[i][0];
                ny = y+dre[i][1];
                if( !(nx>=0 && nx<m && ny<n && ny>=0) )//该方向出去就是超过边界
                    cnt2++;
                else if(mp[nx][ny]==0)//周围那个方向是 水
                    cnt1++;
                else break;
            }

            if(cnt1+cnt2==4)
            {  //  四个 都是上述两个 情况 他是岛
                if(ans.size()!=0)
                ans.push_back(ans[ans.size()-1]+1);
                else 
                    ans.push_back(1);//at the first time test, and get first one island
            }
            else 
            {      
                if(ans.size()!=0)          
                ans.push_back(ans[ans.size()-1]);//after addLand, the number of islands is the same with last time 
                else ans.push_back(0);//at first time test, and get no island
            }
        }


        else//alreay is island
            ans.push_back(ans[ans.size()-1]);

        mp[x][y]=1;//after testing, make this point be island
    	t++;
    }




    for(int i=0;i<ans.size();i++) 
    {
        if(i>0)
            cout<<" ";
        cout<<ans[i];
    } 

    cout<<endl;
    
	return 0;
}








