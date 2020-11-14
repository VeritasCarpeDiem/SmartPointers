# Smart Pointers and Lambda

## C++11 functors:
```C++
 std::function<void(int)> myFunc = [](int x) -> void{ std::cout << "Hello" << x << std::endl;};

    myFunc(11);
    int foo = 5;
    [&foo]()-> void
    {
        foo++;
        std::cout << "Hello " << foo <<std::endl;
    }();

    std::cout << foo << std::endl;
```
