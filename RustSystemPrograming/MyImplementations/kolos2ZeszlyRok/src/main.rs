// #[derive(Debug)]
// struct Position {
//     name: String,
//     bought: bool
// }

// impl PartialEq for Position {
//     fn eq(&self, other: &Self) -> bool {
//         self.name == other.name
//     }
// }

// struct ShoppingList {
//     list: Vec<Position>
// }

// impl ShoppingList {
//     fn new() -> ShoppingList {
//         ShoppingList { list: Vec::new() }
//     }

//     fn push(&mut self, prod: Position) {
//         self.list.push(prod);
//     } 

//     fn bought(&mut self, prod: &str) {
//         for p in self.list.iter_mut() {
//             if p.name == prod {
//                 p.bought = true;
//             }
//         }
//     }
//     fn print(&self) {
//         for p in self.list.iter() {
//             if !p.bought {
//                 print!("{:?}", p);
//             }
//         }
//         for p in self.list.iter() {
//             if p.bought {
//                 print!("{:?}", p);
//             }
//         }
//     }
// }

#[derive(Debug, PartialEq, Clone)]

struct Book {
    title: String,
    author: String,
    year: u32,
    translator: String,
}

impl Book {
    fn new(title: String, author: String, year: u32, translator: String) -> Book {
        Book {title, author, year, translator}
    }
}

struct LibraryEntry {
    book: Book,
    available: bool,
}

struct Library {
    books: Vec<LibraryEntry>,
}

impl Library {
    fn new() -> Self {
        Library { books: Vec::new() }
    }

    fn push_book(&mut self, b: Book) {
        self.books.push(LibraryEntry { book: b, available: true });
    }

    fn find(&self, title: &str) -> Vec<&Book> {
        self.books.iter()
            .filter(|entry| entry.book.title == title)
            .map(|entry| &entry.book)
            .collect()
    }

    fn borrow(&mut self, b: Book) -> Result<Book, String> {
        for entry in self.books.iter_mut() {
            if entry.book == b && entry.available {
                entry.available = false;
                return Ok(entry.book.clone());
            }
        }
        Err("No such book".to_string())
    }

    fn return_book(&mut self, b: Book) {
        for entry in self.books.iter_mut() {
            if entry.book == b && !entry.available {
                entry.available = true;
                return
            }
        }
    }
}


fn main() {
    let mut library = Library::new();

    let book1 = Book::new(
        "The Rust Book".to_string(),
        "Ferris Crab".to_string(),
        2021,
        "None".to_string(),
    );
    let book2 = Book::new(
        "The Rust Book".to_string(),
        "Ferris Crab".to_string(),
        2021,
        "None".to_string(),
    );
    let book3 = Book::new(
        "The Borrow Checker".to_string(),
        "Rustacean".to_string(),
        2022,
        "None".to_string(),
    );

    // Dodawanie książek
    library.push_book(book1.clone());
    library.push_book(book2.clone());
    library.push_book(book3.clone());

    // Wyszukiwanie po tytule
    println!("Szukam książki 'The Rust Book':");
    let results = library.find("The Rust Book");
    for book in &results {
        println!("{:?}", book);
    }

    // Wypożyczenie jednej z książek
    match library.borrow(book1.clone()) {
        Ok(borrowed) => println!("Wypożyczono: {:?}", borrowed),
        Err(err) => println!("Błąd: {}", err),
    }

    // Próba ponownego wypożyczenia tej samej książki
    match library.borrow(book1.clone()) {
        Ok(borrowed) => println!("Wypożyczono ponownie: {:?}", borrowed),
        Err(err) => println!("Błąd przy ponownym wypożyczeniu: {}", err),
    }

    // Zwracanie książki
    println!("Zwracam książkę: {:?}", book1);
    library.return_book(book1.clone());

    // Wypożyczenie po zwrocie
    match library.borrow(book1.clone()) {
        Ok(borrowed) => println!("Wypożyczono po zwrocie: {:?}", borrowed),
        Err(err) => println!("Błąd po zwrocie: {}", err),
    }
}
