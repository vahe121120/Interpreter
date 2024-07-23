#ifndef __TYPES_H__
#define __TYPES_H__

#include <iostream>
#include <vector>
#include <string>

class Types
{
    private: std::string val;
    public:
        // virtual void createObj(void* ptr) = 0;
        virtual std::string get() = 0;
        virtual ~Types() = 0;
};

class Int : public Types
{
    private:
        // this could(must) be an unordered_map<string, void*>
        // std::vector<int> obj;
        std::string val;

    public:
        Int(std::string val);
        // void createObj(void* ptr) override;
        std::string get() override;
};

class Double : public Types
{
    private:
        std::string val;

    public:
        Double(std::string val);
        // void createObj(void* ptr) override;
        std::string get() override;
};

class Bool : public Types
{
    private:
        std::string val;

    public:
        Bool(std::string val);
        // void createObj(void* ptr) override;
        std::string get() override;
};

class String : public Types
{
    private:
        std::string val;
    public:
        String(std::string val);
        // void createObj(void* ptr) override;
        std::string get() override;
};

class Array : public Types
{
    // void createObj(void* ptr) override;
    std::string get() override;
};

std::ostream& operator<<(std::ostream& out, Types* obj);

#endif  // __TYPES_H__