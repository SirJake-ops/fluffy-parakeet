//
// Created by Jacob Pagan on 9/15/2025.
//

#ifndef TRADINGEXCHANGE_MARKPRICE_H
#define TRADINGEXCHANGE_MARKPRICE_H
#include <cstdint>
#include <ctime>
#include <string>
#include <utility>

namespace market {
    class MarkPrice {
    public:
        explicit MarkPrice(std::string symbol, const double &price, const double &ask, const double &last,
                           const uint64_t volume) : _symbol(std::move(symbol)), _bid(price), _ask(ask), _last(last),
                                                    _volume(volume) {
            _timestamp = std::time(nullptr);
        }

        MarkPrice(MarkPrice &&other) noexcept {
            _symbol = std::move(other._symbol);
            _bid = other._bid;
            _ask = other._ask;
            _last = other._last;
            _volume = other._volume;
            _timestamp = std::time(nullptr);
        }


        [[nodiscard]] MarkPrice *generatePrice(const std::string &symbol) const;

    private:
        std::string _symbol;
        double _bid;
        double _ask;
        double _last;
        uint64_t _volume;
        std::time_t _timestamp;
    };
}

#endif //TRADINGEXCHANGE_MARKPRICE_H
