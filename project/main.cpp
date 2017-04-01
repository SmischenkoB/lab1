#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

struct countryData{
    public:
    string name;
    int scores[20];
};
void name(ifstream &input)
{
 input.open("eurovision.csv");
    if (input.is_open()){
        cout<<"otkrylos"<<endl;
    }
    else {
        cout<<"error"<<endl;
        exit(1);
    }
}

void copy_data(int n,ifstream &input, countryData* info){
    string  name1;
    for(int i=0;i<n;i++) {
    getline(input, name1,',');
    info[i].name=name1;
    for(int j=0;j<n-1;j++){
        getline(input, name1,',');
        info[i].scores[j]=atoi(name1.c_str());
        }
    getline(input, name1);
    info[i].scores[n-1]=atoi(name1.c_str());
    }
}
void creating_b(int *b, int n){
    b[0]=12;
    b[1]=10;
    for(int i=2;i<10;i++)
        b[i]=10-i;
    for(int i=10;i<n;i++)
        b[i]=0;
}
void changing_to_one_number (int n,countryData*info, int* b){
    for(int i=0;i<n;i++){
    int maximum= 0;
        for(int j=0;j<n;j++){
            for(int z=0;z<n;z++){
                if(maximum<info[i].scores[z])
                maximum=info[i].scores[z];
                }
            for(int z=0;z<n;z++) {
                if(maximum==info[i].scores[z])
                info[i].scores[z]=b[j-1];
            }
            maximum=0;
        }
    }

}
void console_out(int n,countryData* info){
    for(int i=0;i<n;i++){
        //printf("[%20s]",info[i].name);
        cout<<info[i].name;
        for(int j=0;j<n;j++)
        cout<<info[i].scores[j]<<' ';
        cout<<endl<<endl;
    }
}

void defining_max(int n,int* res,ofstream &fout, countryData* info){
    for(int i=0;i<n;i++){
    res[i]=0;
    for(int j=0;j<n;j++)
    res[i]+=info[j].scores[i];
}
for(int i=0;i<n;i++){
    cout<<info[i].name<<' '<<res[i]<<endl;
}
int res_i,res_max=0;
for(int i=0;i<10;i++){
    for(int j=0;j<n;j++){
        if(res_max<res[j]){
            res_i=j;
            res_max=res[j];
        }
    }
    for(int j=0;j<n;j++){
        if(res_max==res[j])
        {
            res[j]=-1;
        }
    }
    //cout<<info[res_i].name<<' '<<endl;
    fout<<info[res_i].name<<' '<<endl;
    res_max=0;
  }
}





int main() {
    ifstream a;
    ofstream fout("results.csv", ofstream::out);
    name(a);
    int n;
    a>>n;
    cout<<n<<endl;
    countryData* info=new countryData[n];
    copy_data(n,a, info);
    a.close();
    int* res= new int[n];
    int*b=new int[n];
    creating_b(b,n);
    console_out(n, info);
    changing_to_one_number(n,info, b);
    console_out(n, info);
    defining_max(n,res,fout,info);
    fout.close();
    delete[] info;
    delete[] res;
    delete[] b;
return 0;
}
