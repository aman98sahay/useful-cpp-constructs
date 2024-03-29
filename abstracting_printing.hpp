# pragma once 
#include<iostream>
// abstract printing to cout 
// set mode to NOT_PRINTING, if you want to stop printing through the print object
// So print can be used while debuging and when u just want to run your code without debug cosole outputs (also by not removing all the print ,
// because u might not be sure that you have caught the bug) u can directly use the print 
// print provides SRP for all debug output and the change point being the mode set inside of the class once which can be changed directly.
static class print_class {
    
public :
enum class PRINT_MODE{
    PRINTING,
    NOT_PRINTING
};

PRINT_MODE mode = PRINT_MODE::PRINTING;

template <typename TT> 
print_class & operator << (TT pAnythingPrintable) {
    using std::cout;
    if (mode == PRINT_MODE::PRINTING)
        cout << pAnythingPrintable;
    else 
        ;
    return *this;
}
}print;

using std::endl;

typedef std :: ostream & (*endl_Func_ptr)(std :: ostream &);

static print_class & operator << (print_class& some_obj,  endl_Func_ptr fn) {

    if (print.mode == print_class::PRINT_MODE::PRINTING) {

        fn (std :: cout);
    } else {

        ;
    }
}
