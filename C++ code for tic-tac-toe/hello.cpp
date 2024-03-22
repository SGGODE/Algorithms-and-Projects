#include <iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
   //here we get the size of board need
  //  int n;cin>>n;
    //define board
    vector<vector<int>>v(3,vector<int>(3,-1));
    //geting board input 0 for player1 and 1 for player2
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        cin>>v[i][j];
      }
    }
    // will give you correct output
    for(int i=0;i<1;i++){
      for(int j=0;j<3;j++){
        if(j==0){
          bool first=0;
          if(v[i][j]==v[i+1][j+1]==v[i+2][j+2]){
            if(v[i][j]==0){
              cout<<"Player 1 Wins Congratulation"<<endl;
              return;
            }
            if(v[i][j]==1){
              cout<<"Player 2 Wins Congratulation"<<endl;
              return;
            }
          }
          if(v[i][j]==v[i+1][j]==v[i+2][j]){
            if(v[i][j]==0){
              cout<<"Player 1 Wins Congratulation"<<endl;
              return;
            }
            if(v[i][j]==1){
              cout<<"Player 2 Wins Congratulation"<<endl;
              return;
            }
          }
        }
        if(j==1){
          if(v[i][j]==v[i+1][j]==v[i+2][j]){
            if(v[i][j]==0){
              cout<<"Player 1 Wins Congratulation"<<endl;
              return;
            }
            if(v[i][j]==1){
              cout<<"Player 2 Wins Congratulation"<<endl;
              return;
            }
          }
        }
        if(j==2){
          if(v[i][j]==0){
            cout<<"Player 1 Wins Congratulation"<<endl;
            return;
          }
          if(v[i][j]==1){
            cout<<"Player 2 Wins Congratulation"<<endl;
            return;
          }
        }
      }
      for(int k=0;k<3;k++){
        if(k==0){
          bool first=0;
          if(v[k][i]==v[k][i+1]==v[k][i+2]){
            if(v[k][i]==0){
              cout<<"Player 1 Wins Congratulation"<<endl;
              return;
            }
            if(v[k][i]==1){
              cout<<"Player 2 Wins Congratulation"<<endl;
              return;
            }
          }
        }
        if(k==1){
          bool first=0;
          if(v[k][i]==v[k][i+1]==v[k][i+2]){
            if(v[k][i]==0){
              cout<<"Player 1 Wins Congratulation"<<endl;
              return;
            }
            if(v[k][i]==1){
              cout<<"Player 2 Wins Congratulation"<<endl;
              return;
            }
          }
        }
        if(k==2){
          bool first=0;
          if(v[k][i]==v[k][i+1]==v[k][i+2]){
            if(v[k][i]==0){
              cout<<"Player 1 Wins Congratulation"<<endl;
              return;
            }
            if(v[k][i]==1){
              cout<<"Player 2 Wins Congratulation"<<endl;
              return;
            }
          }
        }
      }
    }
      return;
}

signed main() {
	// your code goes here
	// int t;cin>>t;
  // while(t--){
    solve();
  //
//}
	return 0;
}
