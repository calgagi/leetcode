class Foo {
public:
    int stage = 1;
    
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        while (stage != 1) ;
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        stage = 2;
    }

    void second(function<void()> printSecond) {
        while (stage != 2) ;
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        stage = 3;
    }

    void third(function<void()> printThird) {
        while (stage != 3) ;
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        stage = 1;
    }
};
