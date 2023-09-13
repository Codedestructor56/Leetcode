#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

vector<vector<int>> groupThepeople(vector<int>& groups){
    vector<vector<int>> megagroup;
    unordered_map<int,vector<int>> assoc;
    if(!groups.empty()){
        int elem;
        for(int i=0;i<groups.size();i++){
            elem=groups[i];
            assoc[elem].push_back(i);
        }
    }

    for (auto entry : assoc) {
        int elem=entry.first;
        int acq_vecs=assoc[elem].size()/elem;
        cout<<"FOR: "<<elem<<" partition size is: "<<acq_vecs<<endl;
        for(int piece=0; piece<acq_vecs;piece++){
            vector<int> pie(assoc[elem].begin()+(piece*elem),assoc[elem].begin()+((piece+1)*elem));
            megagroup.push_back(pie);
        }
    }
    return megagroup;
}

/*int main(){
    vector<int> group={3,3,3,3,3,1,3};
    vector<int> group2={2,1,3,3,3,2};
    vector<vector<int>> res=groupThepeople(group2);
    cout<<"just checking: "<<res.size()<<endl;
    for(auto groups:res){
        for(auto ind:groups){
            cout<<ind<<endl;
        }
        cout<<"\n"<<endl;
    };
}*/

