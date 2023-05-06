# user-customer class

## Customer(std::string name, std::string login, std::string password)

Конструктор класу Customer для визначення початкових значень екземпляра Customer.

## Public API

### void PrintMenu(char *action) override

Наслідувана функція для виведення в консоль меню користувача.

### void ActivateMenu(char *action) override

Наслідувана функція для активування будь-якого обраного варіанту з виведеного в консоль меню.

### void ToBuyTicket()

Функція для забронювання тікету.

### void ToCancelTicket()

Функція для скасування заброньованого тікету.

### void ToFindEventByName()

Функція для пошуку івенту за його іменем.

### void ToFindEventByDate()

Функція для пошуку івенту за його датою.

### void ToPrintAllEvents()

Функція для виведення в консоль списку усіх івентів.

### void ToPrintBoughtTickets()

Функція для виведення в консоль усіх заброньованих івентів.
