
#include <stdio.h>

// template <class X>
// struct Derived;
// 
// template <class Custom = void>
// struct Foo : public Custom {
// 
//     
// };
// 
// template <>
// struct Foo<void> {
//     
//     template <class X>
//     struct rebind {
//         typedef Foo<X> Other;
//     };
// };
// 
// template <class Base>
// struct Derived : public Base::template rebind <Derived<Base> >::Other {
// 
//     int foo() {
//         printf("here we are\n");
//     };
//     
// };
// 
// template <>
// struct Derived<Foo<> > : public Foo<Derived<Foo <> > > {
// 
// };

struct Param {

protected:
    int foo() {
        return 1;
    }

    int xxx2;

    virtual int xxx() {
        return 1;
    }
    
    virtual double xxx3(int) {
        return 22.0;
    }
};

struct Param2 :
        public Param {

//     friend int func(Param2& x) {
//           
//         return x.foo();
//     }


    virtual int xxx() {
        return 1;
    }
};

template < template < template < class > class, class > class Param >
struct Foo {

    //typedef typename Param::XXX XXX;

    int foo() {

        printf("ok\n");;
    }

};

// template <>
// struct Foo<void> {
//     
//     template <class X>
//     struct rebind {
//         typedef Foo<X> Other;
//     };
// };

// template <class Base>
// struct Derived : public Base::template rebind < Derived<Base> >::Other {
// 
//     int foo() {
//         printf("here we are\n");
//     };
//     
// };

template < template < class > class T, class B >
class TT { };

main() {

//     Foo< TT > tt;
    
    printf("%d\n", sizeof(Param2));

//     Param2 xx;
//     func(xx);

    return 1;
} 

