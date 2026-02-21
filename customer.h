#ifndef __DEFINED_CUSTOMER_H
#define __DEFINED_CUSTOMER_H

#ifdef __cplusplus
extern "C" {
#endif

#define	COLOR_BLUE      1
#define COLOR_GREEN     2
#define COLOR_VIOLET    3
#define COLOR_RED       4
#define COLOR_YELLOW    5
#define COLOR_TURQUOISE 6
#define COLOR_WHITE     7

struct _CUSTOMER {
    int id;
    char first_name[24];
    char last_name[32];
    char zip_code[8];
    char city[32];
    int favorite_color;
};

typedef struct _CUSTOMER CUSTOMER;

#ifdef __cplusplus
}
#endif

// ==========================================
// MODERNE C++ TEIL
// ==========================================

#ifdef __cplusplus
#include <string>
#include <cstring>

enum class FavoriteColor {
    Blue = COLOR_BLUE,
    Green = COLOR_GREEN,
    Violet = COLOR_VIOLET,
    Red = COLOR_RED,
    Yellow = COLOR_YELLOW,
    Turquoise = COLOR_TURQUOISE,
    White = COLOR_WHITE,
    Unknown
};

class Customer {
public:
    int id{0};
    std::string firstName;
    std::string lastName;
    std::string zipCode;
    std::string city;
    FavoriteColor favoriteColor{FavoriteColor::Unknown};

    Customer() = default;

    explicit Customer(const CUSTOMER& legacy_customer) {
        id = legacy_customer.id;
        firstName = legacy_customer.first_name;
        lastName = legacy_customer.last_name;
        zipCode = legacy_customer.zip_code;
        city = legacy_customer.city;
        favoriteColor = static_cast<FavoriteColor>(legacy_customer.favorite_color);
    }

    CUSTOMER to_legacy_struct() const {
        CUSTOMER legacy = {}; 
        legacy.id = id;
        legacy.favorite_color = static_cast<int>(favoriteColor);
        
        std::strncpy(legacy.first_name, firstName.c_str(), sizeof(legacy.first_name) - 1);
        std::strncpy(legacy.last_name, lastName.c_str(), sizeof(legacy.last_name) - 1);
        std::strncpy(legacy.zip_code, zipCode.c_str(), sizeof(legacy.zip_code) - 1);
        std::strncpy(legacy.city, city.c_str(), sizeof(legacy.city) - 1);

        return legacy;
    }
};

#endif

#endif // ifndef __DEFINED_CUSTOMER_H
