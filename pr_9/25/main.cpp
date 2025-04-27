#include <iostream>
#include <stdexcept>

class WeatherService {
public:
    virtual ~WeatherService() = default;

    virtual std::string getForecast() const = 0;
};

class LocalWeatherService : public WeatherService {
public:
    std::string getForecast() const override {
        bool dataAvailable = true;

        if (!dataAvailable) {
            throw std::runtime_error("Данные локального сервиса недоступны.");
        }

        return "Прогноз погоды: Ясно, температура +25°C";
    }
};

class RemoteWeatherService : public WeatherService {
public:
    std::string getForecast() const override {
        bool serverUp = false; 

        if (!serverUp) {
            throw std::runtime_error("Удалённый сервер недоступен.");
        }

        return "Прогноз погоды: Пасмурно, температура +18°C"; 
    }
};

int main() {
    try {
        LocalWeatherService localService;
        std::cout << "Местный прогноз погоды: " << localService.getForecast() << std::endl;

        RemoteWeatherService remoteService;
        std::cout << "Удалённый прогноз погоды: " << remoteService.getForecast() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}