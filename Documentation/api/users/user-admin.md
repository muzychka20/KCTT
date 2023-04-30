# user-admin class

## Admin(name, login, password)

Конструктор класса Admin для определение начальных значенией экземпляра Admin.

## Public API

### void PrintMenu(char *action) override

Наследуемая функция для отрисовки меню пользователя.

### void ActivateMenu(char *action) override

Наследуемая функция для активации любого обраного варианту из отрисованого меню.

### void ToPrintEvents()

Функция для отрисовки всех ивентов.

### void ToAddEvent()

Функция для додавання нового ивента.

### void ToEditEvent()

Функция для редактирования ивенту.

### void ToDeleteEvent()

Функция для удаления ивенту.

### void ToPrintTickets()

Функция для отрисовки всех тикетов.

### void ToAddTicket()

Функция для додавания тикетов.

### void ToEditTicket()

Функция для редактирования тикетов.

### void ToDeleteTicket()

Функция для удаления тикетов.

### void ToDeleteTicketByEvent()

Функция для удаления тикетов привязанных к определёному ивенту.

### void ToCancelTicket()

Функция для отмены бронирования тикета.

### void ToPrintCustomers()

Функция для отрисовки всех пользователей.

### void ToAddCustomer()

Функция для додавания пользователя.

### void ToEditCustomer()

Функция для редактирования пользователя.

### ToDeleteCustomer()

Функция для удаления пользователя.