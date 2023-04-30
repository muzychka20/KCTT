# user-customer class

## Customer(std::string name, std::string login, std::string password)

Конструктор класса Customer для определение начальных значенией экземпляра Customer.

## Public API

### void PrintMenu(char *action) override

Наследуемая функция для отрисовки меню пользователя.

### void ActivateMenu(char *action) override

Наследуемая функция для активации любого обраного варианту из отрисованого меню.

### void ToBuyTicket()

Функция для забронирования тикета.

### void ToCancelTicket()

Функция для отмены бронирования тикета.

### void ToFindEventByName()

Функция для поиска ивента по его имени.

### void ToFindEventByDate()

Функция для поиска ивента по его дате.

### void ToPrintAllEvents()

Функция для отрисовки всех ивентов.

### void ToPrintBoughtTickets()

Функция для отрисовки всех забронированых ивентов.