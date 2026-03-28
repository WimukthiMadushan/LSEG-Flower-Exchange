#pragma once
#include <string>
#include "../include/Order.h"

/**
 * @namespace Utils
 * @brief Utility functions for order processing, status, and validation.
 */
namespace Utils {

    /**
     * @brief Get the status text for an execution status code.
     * @param status Status code (0=New, 1=Rejected, 2=Fill, 3=Pfill).
     * @return Status as a string.
     */
    std::string getStatusText(int status);

    /**
     * @brief Get the current timestamp as a string.
     * @return Timestamp in YYYYMMDD-HHMMSS format.
     */
    std::string getTimestamp();

    /**
     * @brief Generate a unique order ID.
     * @return System-generated order ID string.
     */
    std::string generateOrderId();

    /**
     * @brief Validate an order's fields.
     * @param order The order to validate.
     * @param reason Output parameter for the reason if invalid.
     * @return True if valid, false otherwise.
     */
    bool validateOrder(const Order& order, string& reason);
}
