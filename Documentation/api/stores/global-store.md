# global-store class

## Public API

### static void InitUsersStore()

Функція ініціалізації списку користувачів.

### static void InitEventStore()

Функція ініціалізації списку івентів.

### static void InitTicketStore()

Функція ініціалізації списку тікетов.

### static bool IsAuthorizedUser()

Функція що збергіє стан авторизації користувача.

### static void SetAuthorizedUser(User *user)

Функція що авторизовує користувача.

### static User *GetAuthorizedUser()

Функція отримання стан авторизації користувача.

### static UserStore *GetUserStore()

Функція отримання списка користувачів.

### static EventStore *GetEventStore()

Функція отримання списка івентів.

### static TicketStore *GetTicketStore()

Функція отримання списка тікетов.

## Private API

### static User *currectUser

Вказівник на текущого користувача.

### static UserStore *userStore

Вказівник на вектор що зберігає користувачів.

### static EventStore *eventStore

Вказівник на вектор що зберігає івенти.

### static TicketStore *ticketStore

Вказівник на вектор що зберігає тікети.