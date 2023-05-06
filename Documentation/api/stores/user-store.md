# UserStore class

## UserStore()

Конструктор класу UserStore для визначення сховища користувачів.

## Public API

### int GetSize()

Функція для отримання кількості користувачів.

### void Add(User \*user)

Функція для додавання посилань на екземпляр класу User в сховище.

### void Delete(size_t index)

Функція для видалення посилання через індекс у векторі.

### void DeleteAll()

Функція для очищення сховища.

### void DeleteAllCustomers()

Функція для видалення усіх користувачів з ролью "Customer".

### void DeleteById(std::string id)

Функція для видалення користувачів через унікальний номер.

### bool ExistsById(std::string id)

Функція для перевірки на існування користувача через унікальний номер.

### User \*Get(size_t index)

Функція для отримання посилання на екземпляр класу User через індекс сховища.

### User \*FindById(std::string id);

Функція для отримання посилання на екземпляр класу User через унікальний номер.

### User \*FindByLogin(std::string login)

Функція для отримання посилання на екземпляр класу User через логін.

## Private API

- `std::vector<User *>` users - сховище усіх користувачів в системі.
