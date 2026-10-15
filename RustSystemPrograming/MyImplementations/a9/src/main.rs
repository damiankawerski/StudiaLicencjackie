#[derive(PartialEq, Debug, Eq, PartialOrd, Ord)]
enum Kolor {
    Pik,
    Kier,
    Karo,
    Trefl
}

#[derive(Debug)]
enum Blad {
    Brak,
    ZlyFormat,
    NieIstnieje(String),
    ZaDuzy(u64, u64),
}

impl Blad {
    fn pokaz_komunikat(&self) {
        match self {
            Blad::Brak => println!("Brak błędu. Wszystko działa. No chyba, że znowu coś spierdzieliłeś poza tym."),
            Blad::ZlyFormat => println!("Błąd: zły format pliku. Co ty próbujesz tu wrzucić, bitmapę do Excela?"),
            Blad::NieIstnieje(nazwa) => println!("Błąd: plik '{}' nie istnieje. Może sprawdź, czy nie masz literówki, Einsteinie.", nazwa),
            Blad::ZaDuzy(aktualny, maksymalny) => println!(
                "Błąd: plik za duży ({} bajtów, max dozwolone: {} bajtów). Czego ty próbujesz tu wrzucić, kopię Windowsa 11?",
                aktualny, maksymalny
            ),
        }
    }
}

fn main() {
    let b1 = Blad::Brak;
    let b2 = Blad::ZlyFormat;
    let b3 = Blad::NieIstnieje(String::from("tajne_plany.pdf"));
    let b4 = Blad::ZaDuzy(15_000_000, 5_000_000);

    println!("--- Test 1: Brak ---");
    b1.pokaz_komunikat();

    println!("\n--- Test 2: Zły format ---");
    b2.pokaz_komunikat();

    println!("\n--- Test 3: Plik nie istnieje ---");
    b3.pokaz_komunikat();

    println!("\n--- Test 4: Plik za duży ---");
    b4.pokaz_komunikat();
}
