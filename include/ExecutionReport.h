    
#ifndef LSEG_FLOWER_EXCHANGE_EXECUTIONREPORT_H
#define LSEG_FLOWER_EXCHANGE_EXECUTIONREPORT_H

#include <string>
#include "Order.h"
#include "OrderBook.h"

/**
 * @class ExecutionReport
 * @brief Represents an execution report for an order, including status and transaction details.
 */
class ExecutionReport {
public:
    std::string orderId;           ///< System-generated order ID
    std::string clientOrderId;     ///< Client-supplied order ID
    std::string instrument;        ///< Instrument/flower type
    int side;                      ///< 1 = Buy, 2 = Sell
    double price;                  ///< Execution price
    int quantity;                  ///< Executed quantity
    int status;                    ///< 0 New, 1 Reject, 2 Fill, 3 Pfill
    std::string reason;            ///< Reason for rejection or status
    std::string timestamp;         ///< Transaction time

    /**
     * @brief Create a fill report for a resting order.
     */
    static ExecutionReport createFillReport(const Order& restingOrder, const std::string& instrument, int side, double price, int quantity);
    /**
     * @brief Create a fill report for a filled order.
     */
    static ExecutionReport createFillReport(const FilledOrder& filledOrder, const std::string& instrument, int side, double price, int quantity);
    /**
     * @brief Create an aggressor report for an incoming order.
     */
    static ExecutionReport createAggressorReport(const Order& incomingOrder, const std::string& instrument, double price, int quantity, int status);
    /**
     * @brief Create a new order report.
     */
    static ExecutionReport createNewReport(const Order& order, const std::string& instrument);
    /**
     * @brief Create a reject report for an order.
     */
    static ExecutionReport createRejectReport(const Order& order, const std::string& instrument, const std::string& reason);
};

#endif