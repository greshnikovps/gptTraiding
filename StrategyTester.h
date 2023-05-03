//
// Created by Pavel Greshnikov on 25.03.2023.
//

#ifndef GPTTRAIDING_STRATEGYTESTER_H
#define GPTTRAIDING_STRATEGYTESTER_H

#include <string>
#include "vector"
#include <memory>
#include "TradingStrategy.h"
#include "Trade.h"

class StrategyTester {
public:
    StrategyTester(std::shared_ptr<TradingStrategy> strategy);

    void run();

private:
    std::shared_ptr<TradingStrategy> m_strategy;
    std::vector<double> m_prices;
    double m_balance;
    double m_commissionRate;
    double m_assets = 0.0;
    std::vector<Trade> m_trades;
    //Visualizer m_visualizer;
};
#endif //GPTTRAIDING_STRATEGYTESTER_H
