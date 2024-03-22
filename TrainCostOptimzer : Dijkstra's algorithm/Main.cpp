#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int find_min_cost(int start,int end,vector<pair<int,int>>adj[]){
  vector<int>res(9,1e9);
  res[start]=0;
  queue<pair<int,int>>pq;
  pq.push({start,0});
  while(!pq.empty()){
    int node=pq.front().first;
    int cost=pq.front().second;
    pq.pop();
    for(auto&i:adj[node]){
      if(res[i.first]>cost+i.second){
        res[i.first]=cost+i.second;
        pq.push({i.first,cost+i.second});
      }
    }
  }
  return res[end];
}

int main(){
  vector<vector<int>>train_info{
  {1,2,720,4000,500},{1,3,730,4100,520},{1,4,905,6000,600},
  {1,5,700,4500,550},{1,6,650,4100,450},{1,7,1700,7100,900},
  {1,8,600,3095,490},{2,3,200,1300,125},{2,4,600,3500,400},
  {2,5,500,2700,300},{2,6,1200,6800,450},{2,7,600,3000,300},
  {2,8,400,2100,200},{3,4,600,2700,300},{3,5,350,2100,150},
  {3,6,1200,3700,600},{3,7,600,2800,300},{3,8,400,2200,200},
  {4,5,400,2400,200},{4,6,1700,6700,900},{4,7,270,1550,130},
  {4,8,700,4400,400},{5,6,700,4400,400},{5,7,450,2600,200},
  {5,8,650,4000,250},{6,7,700,4400,300},{6,8,850,5200,400},
  {7,8,800,5000,350}};
  vector<pair<int,int>>adjac[9];
  vector<pair<int,int>>adjsleeper[9];
  vector<pair<int,int>>adjgeneral[9];
  vector<string>citys{"Delhi","Mumbai","Pune","Bangalore","Hyderabad",
  "Kolkata","Chennai","Ahemdabad"};
  cout<<"Keep in Mind The Number in According to Ur Source And Destination City :"<<endl;
  for(int i=0;i<8;i++){
     cout<<citys[i]<<" "<<i+1<<endl;
  }
  int start=-1;
  cout<<"Enter Source City Number :"<<endl;
  cin>>start;
  if(start<=0||start>8){
     cout<<"Please Enter Valid Number :"<<endl;
     cin>>start;
     if(start<=0||start>8){
       cout<<"FUCK YOU HARD"<<endl;
       return 0;
     }
  }
  int end=-1;
  cout<<"Enter Destination City Number :"<<endl;
  cin>>end;
  if(end<=0||end>8){
     cout<<"Please Enter Valid Number :"<<endl;
     cin>>end;
     if(end<=0||end>8){
       cout<<"FUCK YOU HARD"<<endl;
       return 0;
     }
  }
  cout<<"Enter From Which Kind of Set U Want to Go :"<<endl;
  int set=-1;
  cout<<"AC "<<" - "<<1<<endl;
  cout<<"Sleeper "<<" - "<<2<<endl;
  cout<<"General "<<" - "<<3<<endl;
  cout<<"Enter Valid Set Type :"<<endl;
  cin>>set;
  if(set==1){
    for(int i=0;i<train_info.size();i++){
      adjac[train_info[i][0]].push_back({train_info[i][1],train_info[i][3]});
      adjac[train_info[i][1]].push_back({train_info[i][0],train_info[i][3]});
    }
    int x = find_min_cost(start,end,adjac);
    cout<<"This Is The Possible Minimum Cost Required to Go "<<citys[end-1]<<" From "
    <<citys[start-1]<<" in AC set : "<<x<<endl;
  }else if(set==2){
    for(int i=0;i<train_info.size();i++){
      adjsleeper[train_info[i][0]].push_back({train_info[i][1],train_info[i][2]});
      adjsleeper[train_info[i][1]].push_back({train_info[i][0],train_info[i][2]});
    }
    int x = find_min_cost(start,end,adjsleeper);
    cout<<"This Is The Possible Minimum Cost Required to Go "<<citys[end-1]<<" From "
    <<citys[start-1]<<" in Sleeper set : "<<x<<endl;
  }else if(set==3){
    for(int i=0;i<train_info.size();i++){
      adjgeneral[train_info[i][0]].push_back({train_info[i][1],train_info[i][4]});
      adjgeneral[train_info[i][1]].push_back({train_info[i][0],train_info[i][4]});
    }
    int x = find_min_cost(start,end,adjgeneral);
    cout<<"This Is The Possible Minimum Cost Required to Go "<<citys[end-1]<<" From "
    <<citys[start-1]<<" in General set : "<<x<<endl;
  }
  else{
    cout<<"GO to The SSGMCE And Do Eng......"<<endl;
  }
  return 0;
}
