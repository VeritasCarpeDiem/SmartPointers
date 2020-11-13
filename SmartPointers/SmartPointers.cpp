// SmartPointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include <functional>
#include <vector>

struct A
{
    int val{};
    A(int v): val(v) { std::cout << "Constructor called on " << val << std::endl; }
    ~A() { std::cout << "Destructor called on " << val << std::endl; }
    friend std::ostream& operator<<(std::ostream& os, A& a)
    {
        os << a.val;

        return os;
    }
};

std::unique_ptr<A> GetA(int val)
{
    auto ptr = std::make_unique<A>(val);
    
    //return std::move(ptr);
    return ptr;
}


void sort(std::vector<int>& vec, std::function<bool(int, int)> comp)
{
    for (auto i = 0; i < vec.size(); i++)
    {
        for (auto j = 0; j < vec.size(); j++)
        {
            if (comp(vec[i], vec[j]))
            {
                std::swap(vec[i], vec[j]);
            }
        }
    }

}


int main()
{
    // standard library has 3 types of smart pointers
    // (unique_ptr) unique ownership (only 1 thing owns/pointing to a resource)
    // (shared_ptr) shared ownership (multiple things can own/point to a resource)
    // (weak_ptr) non ownership (can point to another shared ownership without owning it)
   
    //std::unique_ptr<int> xptr(new int(5));  // dont use this way anymore, make_unique is safer
    //std::unique_ptr<int> xptr = std::make_unique<int>(5);
    // unique ptr has only one owner, itself, only it can point to the resource
    //std::unique_ptr<int> aptr = xptr; // not allowed

    // make aptr the new owner of xptr, relieving xptr as the owner
    //std::unique_ptr<int> aptr = std::move(xptr);
  
    //std::cout << *xptr << std::endl;


    //auto a = std::make_unique<A>(6);

    /*auto a = GetA(6);
    std::cout << a.get() << std::endl;
    std::cout << *(a.get()) << std::endl;
    std::cout << a->val << std::endl;*/

    
    //std::shared_ptr<A> xptr = std::make_shared<A>(5);

   

    /*auto xptr = std::make_shared<A>(5);
    auto xxptr = xptr;
    auto xxxptr = xptr;
    
    std::cout << xptr.unique() << std::endl;
    xxxptr.reset();
    xxptr.reset();
    std::cout << xptr.unique() << std::endl;
    xptr.reset();

    if (xptr != nullptr)
    {
        std::cout << "is not nullptr";
    }
    else
    {
        std::cout << "NUll ptr";
    }*/
    //std::cout << xptr.use_count() << std::endl;


   /* std::shared_ptr<A> obj = std::make_shared<A>(5);

    std::cout << obj.use_count() << std::endl;

    std::weak_ptr<A> weakObj = obj;

    if (!weakObj.expired())
    {
        std::shared_ptr<A> sharedAgain = weakObj.lock();
        std::cout << obj.use_count() << std::endl;
    }
    std::cout << obj.use_count() << std::endl;
    ;*/


    //std::vector<A> vec = { A(5), A(6), A(3), A(-5), A(10) };

    std::vector<int> vec = { 5,6,3,-5,10 };

    std::function<bool(int, int)> comp = [](int a, int b) -> bool {
        return a > b;
    };


    sort(vec, comp);

    return 0;
}

