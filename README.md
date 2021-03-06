# Заголовочный файл, инкапсулирующий протокол USART на микроконтроллере AVR
###### Краткое описание
- Данная библиотека предназначена в полной мере инкапсулировать все механизмы взаимодействия с регистрами ввода-вывода, регистрами инициализации, которые относятся к протоколу USART.
- Функционал был разработан для **микроконтроллера `AVR ATMega328p`** без использования Arduino-фреймворка.
- _Текущая реализация не использует умножение частоты. ( регистр `U2Xn` выставлен в `0` )_
- ***Данная библиотека является частью пакета AVR_Utility, направленного на реализацию всех протоколов обмена данными для микроконтроллера AVR ATMega328p***

---

## Основные функции и их описание
#### Функции обмена данными
```cpp
template<typename T>
static void transmit(T data); // передача одного байта
template<typename T>
static void transmit(T data[]); //передача массива байт
```
**Корректная работа данных функций гарантирована при параметризации их типами `char` и `uint8_t`**
#### Функции инициализации
```cpp
static void init(const uint8_t &stop_bits, const uint8_t &data_bits = 8); //инициалзиация протокола USART. 
```
- Параметр `stop_bits` принимает количество стоп-битов(от 1 до 2);
- Параметр `data_bits` принимает количество бит, необходимых для отправки. Допустимые значения: **от 5 до 8 бит включительно**
---
```cpp
static void set_speed(const uint16_t &speed); //определение скорости работы передачи данных
```
- Параметр `speed` принимает значения, согласно datasheet-у на микроконтроллер. (**Колонка** `UBRRn`)

![Screenshot_1](https://user-images.githubusercontent.com/31825542/134816312-c8d91cab-c4d3-4507-bd08-1a0d68229bc3.png)
---
## Планы по совершенствованию библиотеке
- [ ] Инкапсуляция всего функционала, возможного для реализации по протоколу `USART`;
