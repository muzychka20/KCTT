# UI class

## Public API

### static void PrintTitle(std::string title)

Функція що виводить в консоль заголовок.

### static void PrintSimpleMenu(std::vector<std::string> items)

Функція що виводить в консоль меню.

### static void PrintUsersTableTitle()

Функція що виводить в консоль таблицю заголовків параметрів користувача.

### static void PrintEventsTableTitle()

Функція що виводить в консоль таблицю заголовків параметрів івенту.

### static void PrintTicketTableTitle()

Функція що виводить в консоль таблицю заголовків параметрів тікету.

### static void PrintRow()

Функція що виводить в консоль рядок.

### static void PrintUserTableRow(User *user)

Функція що виводить в консоль рядок параметрів користувача.

### static void PrintEventTableRow(Event *event)

Функція що виводить в консоль рядок параметрів івенту.

### static void PrintTicketTableRow(Ticket *ticket)

Функція що виводить в консоль рядок параметрів тікету.

### static void EnterString(std::string title, std::string *string)

Функція виводить заголовок після чого, переходить в режим очікування введення значення користувача.

### static void SetWindowFont(int size)

Функція що вказує шрифт який потрібно використовувати в консолі під час виконання програми.

### static void SetWindowSize(int width, int height)

Функція що вказує розмір шрифта який потрібно використовувати в консолі під час виконання програми.

### static void DisableWindowScrollbar()

Функція що вимикає можливість прокрутки в консолі під час виконання програми.