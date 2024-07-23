#include "./Types.h"

// Types class

Types::~Types() {}

// -------------------------------

// Int Object

Int::Int(std::string val) : val{val} {}
std::string Int::get()
{
    return val;
}

// -------------------------------

// Bool Object

Bool::Bool(std::string val) : val{val} {}
std::string Bool::get()
{
    return val;
}

// --------------------------------

// Double Object

Double::Double(std::string val) : val{val} {}
std::string Double::get()
{
    return val;
}

// ----------------------------------

// String Object

String::String(std::string val) : val{val} {}

std::string String::get()
{
    return val;
}


// --------------------------------

// Output Object

std::ostream& operator<<(std::ostream& out, Types* obj)
{
    // Int
    if ( Int* ptr = dynamic_cast<Int*>(obj) )
    {
        out << obj->get();
        return out;
    }
    if ( Double* ptr = dynamic_cast<Double*>(obj) )
    {
        out << obj->get();
        return out;
    }
    if ( Bool* ptr = dynamic_cast<Bool*>(obj) )
    {
        out << obj->get();
        return out;
    }
    // String* ptr = dynamic_cast<String*>(obj);
    if ( String* ptr = dynamic_cast<String*>(obj) )
    {
        out << obj->get();
        return out;
    }
    if ( Array* ptr = dynamic_cast<Array*>(obj) )
    {
        out << obj->get();
        return out;
    }

    throw;
}