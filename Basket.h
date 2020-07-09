#pragma once
#ifndef SDDS_BASKET_H__
#define SDDS_BASKET_H__

namespace sdds {

    const int MAX_NAME_SIZE = 40;

    struct Fruit
    {
        char m_name[MAX_NAME_SIZE + 1];     // Fruit name.
        double m_qty;                       // Quantity in kg.
    };

    class Basket
    {
        Fruit* m_fruits;    // Dynamically allocated array of objects of type Fruit.
        int m_cnt;          // Size of the m_fruits array.
        double m_price;     // Price of the basket.

    public:
        Basket();                                           // Default constructor.
        Basket(const Fruit* fruits, int cnt, double price); // Full scale constructor.
        Basket(const Basket&);                              // Copy constructor
        ~Basket();                                          // Destructor.
        
        void setPrice(double);                              // Price setter.
        operator bool() const;                              // Casting bool operator.
        
        Basket& operator=(const Basket&);                   // Copy assignment operator.
        Basket& operator+=(Fruit fruit);                    // Overload increment operator +=.
        
        friend std::ostream& operator<<(std::ostream& os, const Basket& basket);    // Overload insertion << operator.
    };

}
#endif 

