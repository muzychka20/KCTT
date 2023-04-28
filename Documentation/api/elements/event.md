# Event class

## Event(name, date, startTime, endtime)

Конструктор класса Event для определение начальных значенией экземпляра Event.

## Public API

### std::string GetId()

Функция для получение уникального номера ивента.

### std::string GetName()

Функция для получение имени ивента.

### std::string GetDate()

Функция для получение даты ивента.

### std::string GetStatus()

Функция для получение статуса ивента.

### std::string GetStartTime()

Функция для получение времени старта ивента.

### std::string GetEndTime()

Функция для получение времени завершение ивента.

### void SetName(std::string newName)

Функция для изменения текущего имени ивента.

### void SetDate(std::string newDate)

Функция для изменения текущей даты ивента.

### void SetStatus(std::string newStatus)

Функция для изменения текущего статуса ивента.

### void SetStartTime(std::string newStartTime)

Функция для изменения времени начала ивента.

### void SetEndTime(std::string newEndTime)

Функция для изменения времени конца ивента.

## Private API

- `std::string` id - уникальный номер ивента.

  - Формат: **e[n]** (e1, e2, e3 etc.)

- `std::string` name - имя ивента.

- `std::string` status - текущий статус проекта.

- `std::string` date - дата проведение ивента

  - Формат: **dd.mm.yyyy** (24.04.2022)

- `std::string` startTime - время, когда ивент будет открыт.

  - Формат: **HH:MM** (17:30)

- `std::string` endTime - время, когда ивент завершится.
  - Формат: **HH:MM** (21:40)
