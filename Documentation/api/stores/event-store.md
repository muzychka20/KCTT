# EventStore class

## EventStore()

Конструктор класа EventStore для визначення початкових значень екземпляра EventStore.

## Public API

### int GetSize()

Функція для підрахунку усіх елементів вектора.

### void Add(Event *event)

Функція для додавання івенту у вектор.

### void Delete(size_t index)

Функція для видалення элементів з вектора.

### void DeleteAll()

Функція для очищення вектора.

### void DeleteById(std::string id)

Функція для видалення элементів з вектора через їх id.

### void DeleteByName(std::string name)

Функція для видалення усіх елементів з вектора по імені.

### void DeleteByDate(std::string date)

Функція для видалення усіх елементів з вектора по даті.

### void ExistsById(std::string id)

Функція для перевірки на існування по id.

### Event *Get(size_t index)

Функція для отримання елемента.

### Event *FindById(std::string id)

Функція для пошуку через id.

### std::vector<Event *> FindByDate(std::string date)

Пошук елемента по даті в векторі.

### std::vector<Event *> FindByName(std::string name)

Пошук елемента по імені в векторі.

## Private API

### std::vector<Event *> events

Вектор який зберігає івенти.