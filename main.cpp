#include<iostream>
#include <vector>
#include "stl_iterator.h"
#include <cstdio>
#include "stl_vector.h"
class A {
public:
    A(int* __value):x(__value) {
        std::cout << "构造函数" << std::endl;
    }
    ~A(){
        std::cout << "析构函数" << x << std::endl;
    }
    int *x;
};

int main() {
//    int ia = 1;
//    int ib = 2;
//    int ic = 3;
//    A a(&ia);
//    A b(&ib);
//    A c(&ic);
//    std::vector<A> x{a,b,c};
    sakura_stl::vector<int> x(1,2);
//    x.erase(x.end()-1);
    printf("x\n");
}
//#include <iostream>
//#include <vector>
//#include <string>
//
//void f() {
//    int a = 0;
//    a++;
//    a++;
//}
//
//class Int {
//public:
//    Int() = default;
//
//    ~Int() {
////        printf("%p\n",this);
//        std::cout << "析构" << std::endl;
//    }
//
//    Int(int _i) : i(_i) { std::cout << "构造函数" << std::endl; }
//
//    Int(const Int &_I) {
//        *this = _I;
//        std::cout << "拷贝构造函数" << std::endl;
//    }
//
////    const int operator+(const Int &rhs)  {
////        int a= i + rhs.i;
////        printf("%p\n",&a);
////        return a;
////    }
//    int &test() {
//        return i;
//    }
//
//protected:
//    void mf(int _m) {
//        std::cout << i << std::endl;
//    }
//
//private:
//    int i;
//};
//
//class Int2 : private Int {
//public:
//    Int2(int _i) : Int(_i) {};
//
//    void mmf(int _m) {
//        mf(_m);
//    }
//};
//
////class Int1:public Int{
////    void test(){
////        i++;
////    }
////};
////const Int test(const Int &_I) {
////    printf("%p\n", &_I);
////    return _I;
////}
////bool f2(Int *iw);
////
////template<typename T>
////void f(T param) {
////    f2(param);
////}
////
////bool f2(Int *iw) {
////    std::cout << "f2" << std::endl;
////    return false;
////}
////
////bool f3(int i) {
////    std::cout << "f3-0" << std::endl;
////    return true;
////}
////
////decltype(auto) yin(int &x) {
////    x++;
////    return x;
////}
////
////template<typename FuncType, typename PtrType>
////auto lockAndCall(FuncType func, PtrType ptr) -> decltype(func(ptr)) {
////    return func(ptr);
////}
////
////template<typename T>
////class Wine {
////public:
////    enum class WineType {
////        White, Red
////    };
////    static WineType type;
////};
////
////template<typename T>
////void func(T &&param) {
////    std::cout << "1";
////}
////
////class StrBlob {
////public:
////    using size_type = std::vector<std::string>::size_type;
////
////    StrBlob();
////
////    StrBlob(std::initializer_list<std::string> il);
////
////    size_type size() const { return data->size(); }
////
////    bool empty() const { return data->empty(); }
////
////private:
////    std::shared_ptr<std::vector<std::string>> data;
////
////};
////
////StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
////
////StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {}
////
////class HasPtr {
////public:
////    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0), use(new std::size_t(1)) {}
////    HasPtr(const HasPtr &p):ps(p.ps),i(p.i),use(p.use){++*use;}
////    ~HasPtr();
////private:
////    std::string *ps;
////    int i;
////    std::size_t *use;
////};
////
////
////#include <iostream>
////#include <vector>
////#include <algorithm>
////#include <stdlib.h>
////#include <stdio.h>
////using namespace std;
////struct list {
////    int data;
////    struct list *next;
////};
////void init(struct list *l, int x) {
////    for(int i = 1; i <= x; i++) {
////        l->data = i;
////        struct list *tmp = (struct list *)malloc(sizeof(struct list));
////        l->next = tmp;
////        l = l->next;
////    }
////    l->next = NULL;
////}
////void delete_num(struct list ** L, int x) {
////    struct list *P;
////    if(*L == NULL) return;
////    if((*L)->data == x) {
////        P = *L;
////        *L = (*L)->next;
////        free(P);
////        delete_num(L, x);
////    }
////    else
////        delete_num(&(*L)->next, x);
////}
////struct list *head;
////struct Parent
////{
////    std::string a;
////    virtual ~Parent()
////    {
////        std::cout<<"parent"<<std::endl;
////    }
////
////};
////
////struct Child: public Parent
////{
////    std::string b;
////    ~Child() override{
////        std::cout<<"child"<<std::endl;
////    }
////};
//class wrap_vector{
//public:
//    wrap_vector(wrap_vector && other) noexcept { Swap(other); }
//    wrap_vector(const wrap_vector & other)= default;
//    void Swap(wrap_vector &other) { data_.swap(other.data_); }
//    wrap_vector():data_(std::vector<unsigned char>(10)){};
//    std::vector<unsigned char> data_;
//};
//class state{
//public:
//    state(wrap_vector w_data):w_data_(std::move(w_data)){
//        printf("%p\n",w_data_.data_.data());
//    }
//    wrap_vector w_data_;
//};
//
//class AesGcmImplementation{
//public:
//    AesGcmImplementation():data_(std::vector<unsigned char>(11)){}
//    std::vector<unsigned char> data_;
//};
//std::unique_ptr<AesGcmImplementation> CreateAesGcmImplementation() {
//    return std::make_unique<AesGcmImplementation>();
//}
//int main() {
////    Int a(100), b(2);
////    printf("%p\n", &a);
////    const Int d = test(a);
////    printf("%p\n", &d);
////    for(int i = 0;i<10;i++){
////        Int a(i);
////    }
////    Int a(1);
////    printf("%d\n",a.test());
////    int& b = a.test();
////    b = 2;
////    printf("%d\n",a.test());
////    Int2 a(1);
////    a.mmf(1);
////    int x=1;
//////    int& y=x;
//////    auto z = y;
//////    std::cout<<x;
//////    std::cout<<yin(x);
//////    std::cout<<x;
//////    yin(x)=100;
//////    std::cout<<x;
////    const int& x = 1;
////    f(x);
////    auto result = lockAndCall(f2, nullptr);
////f2(0);
////    Wine<int>::type;
////    const int &w = 1;
////    func(w);
////    auto p1 = std::make_shared<int>(42);
////    auto p2(p1);
////    int x=1;
////    int& y=x;
////    func(y);
////    head = (struct list *)malloc(sizeof(struct list));
////    init(head, 4); // 1 to 4
////    delete_num(&head, 2); // delete when data == 2
////    Parent *p = new Child();
////    delete p;
////    std::vector<int> s{1,2,3,4};
////    auto it = std::find_if(s.begin(), s.end(),
////                           [](const auto& field_data) {
////                               return  field_data==5;
////                           });
////    if(it == s.end())
////        std::cout<<1<<std::endl;
////    else{
////    }
////    wrap_vector w;
////    printf("%p\n",w.data_.data());
////    state(std::move(w));
////    std::unique_ptr<AesGcmImplementation> p(CreateAesGcmImplementation());
////    p.release();
////    printf("%p",p.get());
////    void *x = std::move(p).get();
////    printf("%p",x);
////    return 0;
//}