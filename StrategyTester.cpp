
#include "StrategyTester.h"

//
// Created by Pavel Greshnikov on 25.03.2023.
//
StrategyTester::StrategyTester(std::shared_ptr<TradingStrategy> strategy) :
        m_strategy(strategy)
        {}

void StrategyTester::run() {
    for (int i = 0; i < m_prices.size(); ++i) {
        CalculationStatus result = m_strategy->calculateIndicators(m_prices[i]);
        if (result == CalculationStatus::NOT_ENOUGH_DATA) {
            continue;
        }
        if (m_strategy->shouldBuy()) {
            double amountToBuy = (m_balance * (1.0 - m_commissionRate)) / m_prices[i];
            m_balance -= (amountToBuy * m_prices[i]) * (1.0 + m_commissionRate);
            m_assets += amountToBuy;
            m_trades.push_back(Trade(i, true, m_prices[i]));
        } else if (m_strategy->shouldSell()) {
            double amountToSell = m_assets;
            m_balance += (amountToSell * m_prices[i]) * (1.0 - m_commissionRate);
            m_assets = 0;
            m_trades.push_back(Trade(i, false, m_prices[i]));
        }
    }
    //m_visualizer.plot(m_prices, m_trades, m_balance + (m_assets * m_prices.back()));
}

