# Event class

## Event(name, date, startTime, endtime)

Конструктор класу Event для визначення початкових значень екземпляру Event.

## Public API

### std::string GetId()

Функція для отримання унікального номеру івента.

### std::string GetName()

Функція для отримання імені івента.

### std::string GetDate()

Функція для отримання дати івента.

### std::string GetStatus()

Функція для отримання статусу івента.

### std::string GetStartTime()

Функція для отримання часу початку івента.

### std::string GetEndTime()

Функція для отримання часу кінця івенту.

### void SetName(std::string newName)

Функція для редагування поточного імені івенту.

### void SetDate(std::string newDate)

Функція для редагування поточной дати івенту.

### void SetStatus(std::string newStatus)

Функція для редагування поточного статусу івенту.

### void SetStartTime(std::string newStartTime)

Функція для редагування часу початку івенту.

### void SetEndTime(std::string newEndTime)

Функція для редагування часу кінця івенту.

## Private API

- `std::string` id - унікальний номер івента.

  - Формат: **e[n]** (e1, e2, e3 etc.)

- `std::string` name - ім'я івента.

- `std::string` status - поточний статус проєкта.

- `std::string` date - дата проведення івента

  - Формат: **dd.mm.yyyy** (24.04.2022)

- `std::string` startTime - час, коли івент буде відкритим.

  - Формат: **HH:MM** (17:30)

- `std::string` endTime - час, коли івент закінчиться.
  - Формат: **HH:MM** (21:40)
