#include <iostream>
#include <string>

// Class 1: Base Parent Class
class Product {
protected:
    std::string brand;

public:
    Product(std::string b) {
        brand = b;
    }
    void showBrand() {
        std::cout << "Brand: " << brand << std::endl;
    }
};

// Class 2: Derived from Product (Level 2)
class Electronics : public Product {
protected:
    int warrantyMonths;

public:
    // Passes brand up to Product, sets up its own warranty
    Electronics(std::string b, int w) : Product(b) {
        warrantyMonths = w;
    }
    void showWarranty() {
        std::cout << "Warranty: " << warrantyMonths << " months" << std::endl;
    }
};

// Class 3: Derived from Electronics (Level 3 - The Chain)
class Laptop : public Electronics {
private:
    int ram; // Local member unique to Laptop

public:
    // Passes brand and warranty up the chain, sets up local RAM
    Laptop(std::string b, int w, int r) : Electronics(b, w) {
        ram = r;
    }
    void showLaptopDetails() {
        // Demonstrating use of inherited members (brand, warranty) and local member (ram)
        showBrand();      // Inherited from Product
        showWarranty();   // Inherited from Electronics
        std::cout << "RAM Size: " << ram << " GB" << std::endl; // Local
    }
};

int main() {
    std::cout << "--- Part 1: Multilevel Inheritance Chain ---" << std::endl;
    
    // Creating the bottom-chain object
    Laptop myLaptop("Dell", 12, 16);
    
    // Running the function that uses both inherited and local traits
    myLaptop.showLaptopDetails();

    return 0;
}
