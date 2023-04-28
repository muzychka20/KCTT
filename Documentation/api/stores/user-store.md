# UserStore class

## UserStore()

Конструктор класса UserStore для определение хранилища пользователей.

## Public API

### int GetSize()

Функция для получение количества пользователей.

### void Add(User \*user)

Функция для добавление ссылки на экземпляр класса User в хранилище.

### void Delete(size_t index)

Функция для удаления ссылки по индексу в векторе.

### void DeleteAll()

Функция для отчистки хранилища.

### void DeleteAllCustomers()

Функция для удаления всех пользователей с ролью "Customer".

### void DeleteById(std::string id)

Функция для удаления пользователя по уникальному номеру.

### bool ExistsById(std::string id)

Функция для проверки существование пользователя по уникальному номеру.

### User \*Get(size_t index)

Функция для получении ссылки на экземпляр класса User по индексу хранилища.

### User \*FindById(std::string id);

Функция для получении ссылки на экземпляр класса User по уникальному номеру.

### User \*FindByLogin(std::string login)

Функция для получении ссылки на экземпляр класса User по логину.

## Private API

- `std::vector<User *>` users - хранилище всех пользователей системы.
