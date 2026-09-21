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
    T&operator[](int i){
        return _elem[i];
    }

    //遍历
    void traverse(void(*visit)(T&)){
        for(int i=0;i<_size;i++){
            visit(_elem[i]);
        }
    }
 
    //输出大小
    int size(){
        return _size;
    }
    
    //输出向量元素
    void print(){
        for(int i=0;i<_size;i++){
            cout<<_elem[i]<<" ";
        }
        cout<<endl;
    }
};
//自减
void decrease(int &e){
    e--;
}

//加倍
void doubleNum(int &e){
    e*=2;
}


int main(){
    int n;
    int m;
    cin>>n>>m;

    Vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    
    if(m==1){
        v.traverse(decrease);
        v.print();
    }else if(m==2){
        v.traverse(doubleNum);
        v.print();
    }else{
        int sum=0;
        for(int i=0;i<v.size();i++){
            sum+=v[i];
        }
        cout<<sum<<endl;
    }

    return 0;
}