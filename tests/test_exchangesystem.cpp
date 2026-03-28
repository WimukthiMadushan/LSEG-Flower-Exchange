#include <gtest/gtest.h>
#include "../include/ExchangeSystem.h"

TEST(ExchangeSystemTest, DefaultConstructor) {
    ExchangeSystem es;
    // Add checks for default state
}

TEST(ExchangeSystemTest, ProcessValidAndInvalidOrders) {
    ExchangeSystem es;
    Order validOrder("cl1", "Rose", OrderSide::Buy, 10.5, 100);
    Order invalidOrder("cl2", "Invalid", OrderSide::Buy, 10.5, 100);
    std::vector<Order> orders = {validOrder, invalidOrder};
    es.processOrders(orders);
    // Should have at least one report for valid and one for invalid
    EXPECT_GE(es.reports.size(), 2);
    bool foundReject = false, foundNew = false;
    for (const auto& r : es.reports) {
        if (r.status == OrderStatus::Rejected) foundReject = true;
        if (r.status == OrderStatus::New) foundNew = true;
    }
    EXPECT_TRUE(foundReject);
    EXPECT_TRUE(foundNew);
}

// Add more ExchangeSystem tests here
