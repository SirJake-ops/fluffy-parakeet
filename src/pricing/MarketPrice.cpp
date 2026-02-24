//
// Created by Jacob Pagan on 9/15/2025.
//

#include <memory>
#include <random>

#include "MarkPrice.h"

market::MarkPrice *market::MarkPrice::generatePrice(const std::string &symbol) const {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distribution(-99999, 99999);
    std::uniform_int_distribution<std::uint64_t> distributionInt(0, 999999);

    double price = distribution(gen);
    double ask = distribution(gen);
    double last = distribution(gen);
    std::uint64_t volume = distributionInt(gen);
    const auto newPrice = std::make_shared<MarkPrice>(symbol, price, ask, last, volume);

    return newPrice.get();
}
