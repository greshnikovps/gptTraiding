//
// Created by Pavel Greshnikov on 03.05.2023.
//

#ifndef GPTTRAIDING_TRADINGSTRATEGY_H
#define GPTTRAIDING_TRADINGSTRATEGY_H

#include <string>
enum class CalculationStatus {
    OK,
    NOT_ENOUGH_DATA,
    ERROR
};
class TradingStrategy {
public:
    virtual std::string getName() const = 0;
    virtual CalculationStatus calculateIndicators(const double& price) = 0;
    virtual bool shouldBuy() const = 0;
    virtual bool shouldSell() const = 0;
    //virtual double getBuyPrice(double price) const = 0;
    //virtual double getSellPrice(double price) const = 0;
};
#endif //GPTTRAIDING_TRADINGSTRATEGY_H
