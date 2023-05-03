//
// Created by Pavel Greshnikov on 25.03.2023.
//

#ifndef GPTTRAIDING_MOVINGAVERAGESTRATEGY_H
#define GPTTRAIDING_MOVINGAVERAGESTRATEGY_H

#include "TradingStrategy.h"
#include <string>
#include <deque>


class MovingAverageStrategy : public TradingStrategy {
public:
    MovingAverageStrategy(int shortPeriod, int longPeriod);

    [[nodiscard]] std::string getName() const override;

    CalculationStatus calculateIndicators(const double& price) override;

    bool shouldBuy() const override;

    bool shouldSell() const override;

private:
    int shortPeriod;
    int longPeriod;
    double shortSum = 0;
    double longSum = 0;
    std::deque<double> longPrices;
    std::deque<double> shortPrices;
    std::deque<double> shortMA;
    std::deque<double> longMA;
    bool hasEnoughData = false;
};
#endif //GPTTRAIDING_MOVINGAVERAGESTRATEGY_H
