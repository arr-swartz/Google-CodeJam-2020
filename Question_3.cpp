//Parenting Partenering Returns

#include<bits/stdc++.h>
#include<string>
#define fast std::ios_base::sync_with_stdio(false);
#define ll long long int
#define T vector<int>
#define pb push_back
#define rep(i,n) for (ll i = 0; i < n; ++i) 
#define repk(i,k,n) for (ll i = k; i <= n; ++i) 
#define repkr(i,k,n) for (ll i = k; i >= n; --i) 

using namespace std;

int main()
{
    fast
    cin.tie(0);
	  int t;     //number of testcase
    cin >> t;
    rep(k,t){
       int n;
       cin >> n;    //number of activity
       T s;           //vector for storing starting time of activities
       T s1;             //copy of s
       multimap<int,int> m;  //map for storing pair<staring time , ending time> for every activity

       rep(i,n){
           int a,b;      //starting time , ending time
           cin >> a >> b; 
           s.pb(a);       
           s1.pb(a);
           m.insert(pair<int,int>(a,b));
       }  
       int flag = 1;    //flag that indicate scheduling is possible or impossible
       int c_end = 0;   //ending time of last activity of cameron
       int j_end = 0;    //ending time of last activity of jamie
       string g = "";      //output string
       
       sort(s.begin(),s.end());     //sorting according to starting time
       
       rep(i,n){
           if(s[i]>=j_end){           //if jamie is free assign activity to jamie
               g+="J";
               j_end = m.find(s[i])->second;
               m.erase(m.find(s[i]));
           }
           else if(s[i]>=c_end){        //if cameron if free assign activity to cameron
               g+="C";
               c_end = m.find(s[i])->second;
               m.erase(m.find(s[i]));
           }
           else{                 //if both are busy then it is impossible to schedule activity
               flag = 0;
               break;
           }
       }
       
       if(flag == 0){
           cout<<"Case #"<<k+1<<": IMPOSSIBLE"<<endl;
       }
       else{
           string result="";                //assigning J or C to activities in the sequence which is given in input
           vector<int> :: iterator itr;
           for(itr=s1.begin();itr!=s1.end();++itr){
               int p = distance(s.begin(),find(s.begin(),s.end(),*itr));
               s[p]=-1;
               result+=g[p];
           }
           cout<<"Case #"<<k+1<<": "<<result<<" "<<endl;  //printing result
       }
    }

    return 0;
}
