#include <iostream>
#include <string>

class Product {
 public:
  friend class ProductBuilder;  // Grant the builder access to private members

  void display() const {
    std::cout << "Name: " << name << ", Price: " << price
              << ", Quantity: " << quantity << std::endl;
  }

 private:
  std::string name;
  double price = 0.0;
  int quantity = 0;
};

class ProductBuilder {
 public:
  ProductBuilder() = default;

  ProductBuilder& setName(const std::string& name) {
    m_product.name = name;
    return *this;
  }

  ProductBuilder& setPrice(double price) {
    m_product.price = price;
    return *this;
  }

  ProductBuilder& setQuantity(int quantity) {
    m_product.quantity = quantity;
    return *this;
  }

  Product build() { return m_product; }

 private:
  Product m_product;
};

int main() {
  // Creating an object using the Builder Pattern
  Product my_product = ProductBuilder()
                           .setName("Laptop")
                           .setPrice(1200.50)
                           .setQuantity(10)
                           .build();

  my_product.display();
  return 0;
}