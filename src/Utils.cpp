#include "../include/Utils.h"
#include "../include/Order.h"
#include <chrono>
#include <ctime>
#include <string>
#include <sstream>
#include <iomanip>

namespace Utils {

std::string getStatusText(OrderStatus status) {
    switch (status) {
        case OrderStatus::New: return "New";
        case OrderStatus::Rejected: return "Rejected";
        case OrderStatus::Fill: return "Fill";
        case OrderStatus::Pfill: return "Pfill";
        default: return "Unknown";
    }
}
    
std::string getTimestamp() {
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    tm* tm_ptr = std::localtime(&time);
    char buffer[32];
    std::strftime(buffer, sizeof(buffer), "%Y%m%d-%H%M%S", tm_ptr);
    return std::string(buffer);
}

std::string generateOrderId() {
    static int counter = 1;
    return "ord" + std::to_string(counter++);
}

bool validateOrder(const Order& o, string& reason) {

    if (o.instrument != "Rose" &&
        o.instrument != "Lavender" &&
        o.instrument != "Lotus" &&
        o.instrument != "Tulip" &&
        o.instrument != "Orchid") {
        reason = "Invalid Instrument";
        return false;
    }

    if (o.side != OrderSide::Buy && o.side != OrderSide::Sell) {
        reason = "Invalid Side";
        return false;
    }

    if (o.price <= 0) {
        reason = "Invalid Price";
        return false;
    }

    if (o.quantity < 10 || o.quantity > 1000 || o.quantity % 10 != 0) {
        reason = "Invalid Quantity";
        return false;
    }

    return true;
}

} // namespace Utils
