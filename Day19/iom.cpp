#include <iostream>
#include <iomanip>
    
// ---------------------- BOOLALPHA NOBOOLALPHA -----------------------//
bool val1 = false;
void enableBoolAsString(bool enable) // boolean values print to true or false to screen
{
    if(enable)
    {
        std::boolalpha(std::cout);
    }
    else
    {
        std::noboolalpha(std::cout);
    }
}

void func1()
{
    
    {
    std::cout << "Without Boolalpha : " << val1 << std::endl;
    std::boolalpha(std::cout);
    std::cout << "With Boolalpha 1 :  " << val1 << std::endl;
    }

    std::cout <<  "With Boolalpha 2 :  " << std::boolalpha << val1 << std::endl;
}
// ---------------------- BOOLALPHA NOBOOLALPHA -----------------------//

// ---------------------- SHOW BASE NOSHOWBASE -----------------------//

void func2()
{
    auto n1 {10};   
    auto n2 {010};  
    auto n3 {0x10}; 
    auto n4 {10};
    std::cout << std::showbase << std::setbase(16) << "n1 = " << n1 << ", n2 = " << n2 << ", n3 = "<< n3 << "\n";
    std::cout << std::showbase << std::setbase(16) << "n4 as hex " << n4 << std::endl;
    std::cout << std::showbase << std::setbase(10) << "n4 as decimal " << n4 << std::endl;

}
// ---------------------- SHOW BASE NOSHOWBASE -----------------------//


void func3()
{
    auto n1 {10.0F};
    std::cout <<  "Before: " << n1 << std::showpoint << " After(showpoint): " << n1 << "\n";
    std::cout <<  "Before: " << n1 << std::showpos << " After(showpos): " << n1 << "\n";
}

void func4()
{
    std::cout << "0.01 - fixed:      " << std::fixed << 0.01 << '\n'
              << "0.01 - scientific: " << std::scientific << 0.01 << '\n'
              << "0.01 - hexfloat:   " << std::hexfloat << 0.01 << '\n'
              << "0.01 - default:    " << std::defaultfloat << 0.01 << '\n';
    double f;
    std::istringstream("0x1P-1022") >> std::hexfloat >> f;
    std::cout << "0x1P-1022 hex olarak ayikladigimizda elde ettigimiz deger:" << f << '\n';
}

void func5()
{
    std::cout << "ends add to ends character" << std::ends <<"X"<<std::endl;
}

void func6()
{
    // setfill -> çıktıda setw ile belirlenen boşlugu bununla doldurur
    // setw -> bir sonraki çıktı için genişligi belirler..

    std::cout << std::setfill('#') << std::setw(10) << "Atakan" << std::endl;
}

int main()
{
    enableBoolAsString(true);
    func1();
    enableBoolAsString(false);
    std::cout <<  "With Boolalpha 3 :  "  << val1 << std::endl;

   func2();
   func3();
   func4();
   func5();
   func6();

    return 0;
}