# Class event

## Class(name, login, password)
Конструктор класу User для визначення початкових значень екземпляру User.

## Public API

### std::string GetId()

Функція для отримання унікального номеру користувача.

### std::string GetRole()

Функція для отримання ролі користувача.

### std::string GetName()

Функція для отримання імені користувача.

### std::string GetLogin()

Функція для отримання логіну користувача.

### void SetName(std::string newName)

Функція для редагування імені користувача.

### void SetLogin(std::string newLogin)

Функція для редагування логіну користувача.

### void SetPassword(std::string newPassword)

Функція для редагування паролю користувача.

### bool ComparePassword(std::string password)

Функція для перевірки коректності пароля користувача.

### virtual void PrintMenu(char *acrion)

Функція для виведення в консоль меню користувача.

### virtual void ActivateMenu(char *action)

Функція для активування будь-якого обраного варіанту із виведеного в консоль меню.

## Protected API

- `std::string` role - роль користувача.
  - Формат: Customer/Admin

## Private API

- `std::string` id - унікальний номер івенту.
  - Формат: **e[n]** (e1, e2, e3 etc.)

- `std::string` name - ім'я користувача.

- `std::string` login - логін користувача.

- `std::string` password - пароль користувача.
