# Class event

## Class(name, login, password)
Конструктор классу User для определения начальных значенией экземпляра User.

## Public API

### std::string GetId()

Функция для получение уникального номера пользователя.

### std::string GetRole()

Функция для получения роли пользователя.

### std::string GetName()

Функция для получения имени пользователя.

### std::string GetLogin()

Функция для получения логина пользователя.

### void SetName(std::string newName)

Функция для изменения имени пользователя.

### void SetLogin(std::string newLogin)

Функция для изменения логина пользователя.

### void SetPassword(std::string newPassword)

Функция для изменения пароля пользователя.

### bool ComparePassword(std::string password)

Функция для проверки корректности пароля пользователя.

### virtual void PrintMenu(char *acrion)

Функция для отрисовки меню пользователя.

### virtual void ActivateMenu(char *action)

Функция для активации любого обраного варианту из отрисованого меню.

## Protected API

- `std::string` role - роль пользователя
  - Формат: Customer/Admin

## Private API

- `std::string` id - уникальный номер ивента.
  - Формат: **e[n]** (e1, e2, e3 etc.)

- `std::string` name - имя пользователя.

- `std::string` login - логин пользователя.

- `std::string` password - пароль пользователя.