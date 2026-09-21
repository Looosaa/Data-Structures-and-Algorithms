#include <iostream>
#include <vector>

using namespace std;

class Vector{
    private:
    int _size;
    int _capacity;
    int*_elem;

    public:
    //构造函数
    Vector(int n){
        _size=n;
        _capacity=n;
        _elem=new int[n];
    }

    //重载下标运算符
    int& operator[](int i){
    return _elem[i];
    }
    
    //析构函数
    ~Vector(){
        delete[] _elem;
    }

    int remove(int lo,int hi){
        if(lo==hi){
            return 0;
        }
        while(hi<_size){
            _elem[lo++]=_elem[hi++];
        }
        _size=lo;
        return hi-lo;
    }

    void print(){
        for(int i=0;i<_size;i++){
            cout<<_elem[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    int n;
    int k;
    cin>>n>>k;

    Vector v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    vector<vector<int> > a(k, vector<int>(2)); 
    for(int i=0;i<k;i++){
        cin>>a[i][0]>>a[i][1];
    }
    
    for(int i=0;i<k;i++){
        int lo=a[i][0];
        int hi=a[i][1];
        v.remove(lo,hi);
    }

    v.print();

}