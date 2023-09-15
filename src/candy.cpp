#include <iostream>
#include <stack>
#include <vector>
#include <numeric>
#include <cstring>

using namespace std;
int candy(vector<int>& ratings) {
    unsigned char* candies_rec=new unsigned char[ratings.size()];
    unsigned char byte=0x01;
    memset(candies_rec,byte,ratings.size());
    for(unsigned char i=0x0;i<ratings.size();i++){
        if(ratings[i]>ratings[i+1]){
            candies_rec[i+1]+=candies_rec[i];
        }
    }
    for(unsigned char i=ratings.size();i>0x0;i--){
        if(ratings[i]>ratings[i-1]){
            candies_rec[i-1]+=candies_rec[i];
        }
    }
    int sum=0;
    for(int i=0;i<ratings.size();i++){
        sum+=candies_rec[i];
    }
    return sum;
}

/*int main(){
    vector<int> ratings={1,2,87,87,87,2,1};
    vector<int> ratings2={1,0,2};
    vector<int> ratings3={1,2,2};
    cout<<candy(ratings2)<<endl;
}*/
