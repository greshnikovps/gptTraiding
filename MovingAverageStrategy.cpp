//
// Created by Pavel Greshnikov on 25.03.2023.
//

#include "MovingAverageStrategy.h"

MovingAverageStrategy::MovingAverageStrategy(int shortPeriod, int longPeriod)
        : shortPeriod(shortPeriod), longPeriod(longPeriod) {}

std::string MovingAverageStrategy::getName() const {
    return "Moving Average Crossover";
}

CalculationStatus MovingAverageStrategy::calculateIndicators(const double &price) {
    longPrices.push_back(price);
    shortPrices.push_back(price);
    //while (prices.size() > longPeriod) {
    //    prices.pop_front();
    //    shortMA.pop_front();
    //    longMA.pop_front();
    //}

    // Если данных недостаточно, вернуть NOT_ENOUGH_DATA
    if (longPrices.size() < longPeriod) {
        hasEnoughData = false;
        return CalculationStatus::NOT_ENOUGH_DATA;
    }

    // Рассчитать короткую скользящую среднюю
    shortSum += price;
    longSum += price;

    if (longPrices.size() > longPeriod){
        longSum -= longPrices.front();
        longPrices.pop_front();
    }
    if (shortPrices.size() > shortPeriod){
        shortSum -= shortPrices.front();
        shortPrices.pop_front();
    }
    shortMA.push_back(shortSum / shortPeriod);

    longMA.push_back(longSum / longPeriod);

    hasEnoughData = true;
    return CalculationStatus::OK;
}

bool MovingAverageStrategy::shouldBuy() const {
    if (!hasEnoughData || shortMA.size() < 2 || longMA.size() < 2) {
        return false;
    }
    return shortMA.back() > longMA.back() && shortMA[shortMA.size() - 2] <= longMA[longMA.size() - 2];
}

bool MovingAverageStrategy::shouldSell() const {
    if (!hasEnoughData) {
        return false;
    }
    return shortMA.back() < longMA.back() && shortMA[shortMA.size() - 2] >= longMA[longMA.size() - 2];
}
