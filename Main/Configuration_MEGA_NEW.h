#pragma once

//--------------------------------------------------------------------------------------------------------------------------------
// синхронизация времени
//--------------------------------------------------------------------------------------------------------------------------------
//#define GSM_TIME_SYNC // закомментировать, если не надо синхронизировать время контроллера с оператором
#define GSM_SYNC_TIME_INTERVAL 43200000ul // время между синхронизацией часов, мс
#define GPRS_RECONNECT_TIME 35000 // интервал между попытками реконнекта по GPRS, мс

#define WIFI_TIME_SYNC // закомментировать, если не надо синхронизировать время через Wi-Fi, с NTP-сервера
#define NTP_SERVER F("pool.ntp.org") // адрес NTP-сервера
#define NTP_PORT 123 // порт NTP-сервера
#define NTP_TIMEZONE 180 // смещение таймзоны (в минутах) от GMT (нулевого меридиана)
#define NTP_UPDATE_INTERVAL 43200000ul // время между синхронизацией часов, мс
#define YEAR_30_FIX // раскомментировать, если надо сдвигать дату на 30 лет (фикс неправильного расчёта времени, когда дата на 30 лет больше)

//--------------------------------------------------------------------------------------------------------------------------------
// ТАЙМЕР 1 ДЛЯ ВЫЧИТЫВАНИЯ ДАННЫХ С ESP и SIM800 (ДЛЯ Mega2560)
//--------------------------------------------------------------------------------------------------------------------------------

//#define USE_TIMER_ONE_FOR_ESP_SIM800 // закомментировать, если не надо использовать вычитку буферов Serial* по таймеру
#define TIMER_ONE_PERIOD 10000UL	// период для таймера, микросекунд (по умолчанию - раз в 10 миллисекунд принудительно вычитываются буфера)


//--------------------------------------------------------------------------------------------------------------------------------
// НАСТРОЙКА ТАЙМАУТА ЧТЕНИЯ входящих данных для SIM800
//--------------------------------------------------------------------------------------------------------------------------------
#define SIM800_INCOMING_DATA_TIMEOUT 10000 // сколько миллисекунд ждать полного вычитывания данных (закомментировать, если не надо
// использовать эту настройку). Если с модема при детектировании входящих данных за указанное время не поступило полного пакета данных - 
// он пересбросится.

// успокаивать внешний ватчдог в процессе вычитки входящих данных? Эта настройка вкупе с настройкой SIM800_INCOMING_DATA_TIMEOUT
// позволяет перезагружать модем без перезагрузки контроллера, при потере входящих данных в порту.
#define SIM800_CALM_WATCHDOG_DURING_IPD_READ 

//--------------------------------------------------------------------------------------------------------------------------------
// МОДУЛЬ ДИНАМИЧЕСКОГО СБРОСА ИНФОРМАЦИИ С WI-FI-модулей с датчиками
//--------------------------------------------------------------------------------------------------------------------------------
//#define USE_DYNAMIC_SENSORS_RESET_MODULE // использовать или нет модуль для динамического сброса информации с датчиков Wi-Fi модулей.
// данный модуль в прошивке контроллера делает следующее: если данные по датчику пришли в контроллер извне - он запоминает время получения
// данных для такого датчика. И если для датчика не будет поступать данных в течение указанного ниже интервала - то данные автоматически 
// сбросятся на показания "нет данных"

#define DYNAMIC_SENSORS_RESET_INTERVAL 60000 // через сколько миллисекунд сбрасывать данные для динамически добавленных в систему датчиков


// чтение с DHT22
#define DHT_READ_DELAY 40 // пауза (в микросекундах) перед чтением с датчика DHT. По даташиту - 40 микросекунд, иногда помогает увеличить эту паузу.

// второй датчик уровня pH
#define PH_FLOW_LEVEL_SENSOR2_CHANNEL 5 // номер канала микросхемы PCF8574, на который заведён сигнал с датчика уровня воды, по которому подача вобы в бак выключается
