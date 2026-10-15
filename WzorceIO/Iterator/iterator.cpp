#include <iostream>
#include <string>

class Book {
private:
    std::string title;

public:
    Book(std::string title) : title(title) {}
    std::string getTitle() const { return title; }
};


class Iterator {
public:
    virtual ~Iterator() {}
    virtual bool hasNext() = 0;
    virtual Book* next() = 0;
};


class BookCollection {
private:
    Book* books[10];
    int size;

public:
    BookCollection() : size(0) {
        for (int i = 0 ; i < 10 ; i++) {
            books[i] = nullptr;
        }
    }

    void addBook(Book* book) {
        if (size < 10) {
            books[size++] = book;
        } else {
            std::cerr << "Za dużo książek.\n";
        }
    }

    Book* getBook(int index) const {
        if (index < size) return books[index];
        return nullptr;
    }

    int getSize() const { return size; }

    class BookIterator : public Iterator {
    private:
        const BookCollection& collection;
        int index;
    
    public:
        BookIterator(const BookCollection& collection) 
            : collection(collection), index(0) {}

        bool hasNext() override {
            return index < collection.getSize();
        }

        Book* next() override {
            return collection.getBook(index++);
        }

    };

    Iterator* createIterator() const {
        return new BookIterator(*this);
    }

};

int main() {
    BookCollection collection;
    collection.addBook(new Book("Władca Pierścieni"));
    collection.addBook(new Book("Harry Potter"));
    collection.addBook(new Book("Hobbit"));

    Iterator* it = collection.createIterator();
    while (it->hasNext()) {
        Book* book = it->next();
        std::cout << "Książka: " << book->getTitle() << "\n";
    }

    delete it;
    return 0;
}