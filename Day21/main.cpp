#include <iostream>
#include <bitset>

class Device
{
    public:
        Device(int id) : m_id(id) {}
        int getDeviceId()  const { return m_id; }
    private:
        int m_id;
};

class PowerSupply : public Device
{
    public:
        PowerSupply() = default;
        void printInfo()
        {
            std::cout << "Power Supply " << getDeviceId() << std::endl;
        }
};

void func1()
{
    Device *device1 = new Device(1);
    Device *device2 = new Device(2);

    PowerSupply *device3 = static_cast<PowerSupply*>(device1);
    device3->printInfo();

    PowerSupply *device4 = static_cast<PowerSupply*>(device2);
    device4->printInfo();
}

void func2()
{
    uint64_t value = 3; // 00000011
    std::cout << "Original " << std::bitset<8>(value) << std::endl;
    std::cout << "with bitset " << std::bitset<32>(value) << std::endl;
    std::cout << "with static_cast " << std::bitset<32>(static_cast<uint32_t>(value)) << std::endl; 
}

void func3()
{
    int a = 10;
    int b = 3;
    std::cout << "Without cast 10 / 3 = " << a / b << std::endl;
    std::cout << "With static_cast 10 / 3 = " << static_cast<double>(a) / static_cast<double>(b) << std::endl;
    std::cout << "With c style cast 10 / 3 = " << ((double)a / (double)b) << std::endl;
}

// unused parameters
void func4()
{
    int *ptr;
    static_cast<void>(ptr); // (void) ptr -> c style
}

class Base 
{
    public:
        Base() = default; 
};

class Derived : public Base 
{
    public:
        Derived() = default; 
}; 

void func5()
{
    Derived d1; 
    Base* b1 = (Base*)(&d1); // allowed 
    Base* b2 = static_cast<Base*>(&d1);
    static_cast<void>(b1);
    static_cast<void>(b2);
}

int main()
{
    func1();
    func2();
    func3();
    func4();
    func5();
    return 0;
}