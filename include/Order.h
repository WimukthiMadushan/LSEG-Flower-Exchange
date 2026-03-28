#ifndef LSEG_FLOWER_EXCHANGE_ORDER_H
#define LSEG_FLOWER_EXCHANGE_ORDER_H

#include <string>

using namespace std;

/**
 * @class Order
 * @brief Represents a single order in the exchange.
 */
class Order {
public:
    string orderId;           ///< System-generated order ID
    string clientOrderId;     ///< Client-supplied order ID
    string instrument;        ///< Instrument/flower type
    int side{};               ///< 1 = Buy, 2 = Sell
    double price{};           ///< Order price
    int quantity{};           ///< Order quantity
    long long sequence{};     ///< Time priority (FIFO) - order of arrival

    /**
     * @brief Default constructor.
     */
    Order() = default;
    /**
     * @brief Parameterized constructor.
     */
    Order(string id, string inst, int s, double p, int q);

    /**
     * @brief Equality operator for orders.
     */
    bool operator==(const Order& other) const;
};

#endif // LSEG_FLOWER_EXCHANGE_ORDER_H