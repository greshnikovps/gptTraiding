#include "MovingAverageStrategy.h"
#include "StrategyTester.h"
#include <memory>

int main() {
    // Инициализируем стратегию
    std::shared_ptr<TradingStrategy> strategy = std::make_shared<MovingAverageStrategy>("Moving Average Strategy", 50, 200);

    // Создаем тестер и запускаем его
    StrategyTester tester(strategy);
    tester.run();

    // Создаем координатор и запускаем визуализатор
    //Coordinator coordinator(tester.getAssets());
    //coordinator.visualize();

    return 0;
}
