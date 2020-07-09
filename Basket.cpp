#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Basket.h"

using namespace std;

namespace sdds {

    // DEFAULT CONSTRUCTOR:
    sdds::Basket::Basket()
    {
        // Safe default state:
        m_fruits = nullptr;     // Set m_fruits to nullptr!
        m_cnt = 0;
        m_price = 0;
    }

    // FULL SCALE CONSTRUCTOR:
    Basket::Basket(const Fruit* fruits, int cnt, double price)
    {
        // Validate parameter values:
        if (fruits != nullptr && cnt > 0 && price > 0) {
            // Accept client parameters:
            m_price = price;
            m_cnt = cnt;
            
            m_fruits = new Fruit[cnt + 1];
            for (int i = 0; i < cnt; i++)
            {
                m_fruits[i] = fruits[i];
            }
        }
        else
        {
            // Safe default state:
            m_fruits = nullptr;
            m_cnt = 0;
            m_price = 0;
        }
    }

    // COPY CONSTRUCTOR:
    Basket::Basket(const Basket& other)
    {
        m_fruits = nullptr;     // Deallocate memory prior to copy.
        *this = other;          // Copy incoming parameters to the current object.
    }

    // DESTRUCTOR:
    Basket::~Basket()
    {
        delete[] m_fruits;      // Deallocate memory.
        m_fruits = nullptr;     // Set to nullptr.
    }

    // PRICE SETTER:
    void Basket::setPrice(double price)
    {
        m_price = price;        // Set price using parameter.
    }

    // CASTING BOOL OPERATOR:
    Basket::operator bool() const
    {
        return (m_fruits != nullptr);   // Returns true if fruits, false if none.
    }

    // COPY ASSIGNMENT OPERATOR:
    Basket& Basket::operator=(const Basket& other) {
        // Check if this and other are the same:
        if (this != &other)
        {
            // If this and other are different, assign other's params to this:
            m_price = other.m_price;
            m_cnt = other.m_cnt;
            
            delete[] m_fruits;                      // Deallocate m_fruits.
            if (other.m_fruits != nullptr)          // Validate other.m_fruits:
            {
                m_fruits = new Fruit[m_cnt + 1];    // Assign memory to this.m_fruits.
                for (int i = 0; i < m_cnt; i++)
                {
                    m_fruits[i] = other.m_fruits[i];
                }
            }
            else
            {
                m_fruits = nullptr;     // If other.m_fruits is invalid, assign to nullptr.
            }
        }
        return *this;
    }
    
    // OVERLOAD INCREMENT += OPERATOR:
    Basket& Basket::operator+=(Fruit fruit)
    {
        // Make a temporary array of fruit with one extra space:
        Fruit* temp = new Fruit[m_cnt + 1];
        
        // Assign current fruits to temporary array:
        for (int i = 0; i < m_cnt; i++)
        {
            temp[i] = m_fruits[i];
        }

        // Add the new fruit to temporary array:
        temp[m_cnt++] = fruit;

        delete[] m_fruits;      // Deallocate memory from current fruits array.
        m_fruits = temp;        // Copy temporary array to m_fruits.

        return *this;
    }

    // OVERLOAD INSERTION << OPEREATOR:
    std::ostream& operator<<(std::ostream& os, const Basket& basket)
    {
        // Check if basket is empty:
        if (basket.m_fruits == nullptr || basket.m_cnt == 0 || basket.m_price == 0)
        {
            // Display warning for empty basket:
            os << "The basket is empty!" << std::endl;
        }
        else
        {
            // Display basket:
            os << "Basket Content:" << std::endl;
            
            // Display settings for fruits:
            std::cout << std::fixed;
            std::cout << std::setprecision(2);

            // Display fruits:
            for (int i = 0; i < basket.m_cnt; i++)
            {
                // Size 10 field
                // Right aligned
                os << std::setw(10) << basket.m_fruits[i].m_name << ": " << basket.m_fruits[i].m_qty << "kg" << std::endl;
            }

            // Display price:
            os << "Price: " << basket.m_price << std::endl;
        }
        return os;
    }
}