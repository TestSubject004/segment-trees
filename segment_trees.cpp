# include <iostream>
# include <vector>
# include <fstream>
# include <string>

using namespace std;

int sum(vector<int>& vec,int l,int r){
    int sum = 0;
    for (int i = l; i<=r;i++){
        sum+=vec[i];
    }
    return sum;
}

void build(vector<int>& vec, int l, int r,vector<int>& v,int i){
    
    int m = (l+r)/2;
    if(l!=r){
        
        
        v[i] = (sum(vec,l,r));
        build(vec,l,m,v,2*i);
        build(vec,m+1,r,v,2*i+1);
    }
    
    else{
        v[i] = (sum(vec,l,r));
        return;
    }


}

int calcSum(vector<int>& v,int l,int r,int sl, int sr,int i){
    cout<<"flag"<<endl;
    int m = (l+r)/2;
    if (l==sl&&r==sr){
        cout<<"flag1"<<endl;
            return v[i];
    }
    
    if (sl>m){
        cout<<"flag2"<<endl;
        int sum = calcSum(v, m+1, r, sl,  sr,2*i+1);
        return sum;
        
    }
    else if (sr<=m){
        cout<<"flag3"<<endl;
        int sum = calcSum(v,l, m, sl,  sr,2*i);
        return sum;
        
    }
    else{
        cout<<"flag4"<<endl;
        int sum = calcSum(v,l,m,sl,m,2*i);
        int sum1 = calcSum(v,m+1,r,m+1,sr,2*i+1);
        return sum+sum1;
    }
    
        
    
}

void populate(vector<int>& vec){
    cout<<"enter file name"<<endl;
    string name;
    cin>>name;
    ifstream ist{name};
    //vector<int> vec;
    int val;
    for (int val;ist>>val;){
        vec.push_back(val);
    }
    
    //return vec;

}

int main(){
    vector<int> vec;
    vector<int> v;
    populate(vec);
    v.resize(vec.size()*4);
    build(vec,0,vec.size()-1,v,1);
   int sum = calcSum(v,1,vec.size(),1,6,1);
    cout<<sum<<endl;
    
    return 0;
    
}



