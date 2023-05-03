//
// Created by Pavel Greshnikov on 03.05.2023.
//

#ifndef GPTTRAIDING_TRADE_H
#define GPTTRAIDING_TRADE_H

class Trade {
public:
    Trade(double price, double amount, bool isBuy)
            : m_price(price), m_amount(amount), m_isBuy(isBuy) {}

    double getPrice() const { return m_price; }
    double getAmount() const { return m_amount; }
    bool isBuy() const { return m_isBuy; }

private:
    double m_price;
    double m_amount;
    bool m_isBuy;
};

#endif //GPTTRAIDING_TRADE_H
