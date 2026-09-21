#include <iostream>


using namespace std;

template <typename T>
class Vector{
    private:
    int _size;
    int _capacity;
    T* _elem;
    public:
    //构造函数
    Vector(int n){
        _size=n;
        _capacity=n;
        _elem=new T[n];
    }

    //析构函数
    ~Vector(){
        delete[] _elem;
    }
    //重载下标运算符
    T& operator[](int i){
        return _elem[i];
    }

    int size(){
        return _size;
    }

    //查找
    int find(T const& e,int lo,int hi){

        while((lo<hi--)&&(e!=_elem[hi]));

        return hi;
    }
    //删除区间
    int remove(int lo, int hi) {
        if (lo == hi) {
            return 0;
        }

        while (hi < _size) {
            _elem[lo++] = _elem[hi++];
        }

        _size = lo;

        return hi - lo;
    }

    //重载
    T remove(int r){
        T e=_elem[r];

        remove(r,r+1);

        return e;
    }

    //删除重复元素
    int deduplicate(){
        int oldsize=_size;

        for(int i=1;i<_size;){
            if(find(_elem[i],0,i)<0){
                i++;
            }else{
                remove(i);
            }
        }
        return oldsize-_size;
    }
    //输出
    void print(){
        for(int i=0;i<_size;i++){
            cout<<_elem[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    int n;
    cin>>n;
    Vector<int> v(n);

    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    v.deduplicate();

    cout<<v.size()<<endl;

    v.print();
    return 0;

}