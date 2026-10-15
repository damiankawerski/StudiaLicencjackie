mod ulamek;

use ulamek::Ulamek;

fn main() {
    println!("Odpal `cargo test`.");
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_dodawanie() {
        let a = Ulamek::new(1, 2);
        let b = Ulamek::new(1, 3);
        let wynik = a + b;
        assert_eq!(wynik, Ulamek::new(5, 6));
    }

    #[test]
    fn test_odejmowanie() {
        let a = Ulamek::new(1, 2);
        let b = Ulamek::new(1, 3);
        let wynik = a - b;
        assert_eq!(wynik, Ulamek::new(1, 6));
    }

    #[test]
    fn test_mnozenie() {
        let a = Ulamek::new(1, 2);
        let b = Ulamek::new(1, 3);
        let wynik = a * b;
        assert_eq!(wynik, Ulamek::new(1, 6));
    }

    #[test]
    fn test_dzielenie() {
        let a = Ulamek::new(1, 2);
        let b = Ulamek::new(1, 3);
        let wynik = a / b;
        assert_eq!(wynik, Ulamek::new(3, 2));
    }

    #[test]
    fn test_add_assign() {
        let mut a = Ulamek::new(1, 2);
        a += Ulamek::new(1, 3);
        assert_eq!(a, Ulamek::new(5, 6));
    }

    #[test]
    fn test_eq() {
        let a = Ulamek::new(2, 4);
        let b = Ulamek::new(1, 2);
        assert_eq!(a, b);
    }

    #[test]
    fn test_as_f64() {
        let a = Ulamek::new(1, 4);
        assert!((a.as_f64() - 0.25).abs() < 1e-9);
    }

    #[test]
    fn test_licznik_mianownik() {
        let u = Ulamek::new(6, 8); 
        assert_eq!(u.licznik(), 3);
        assert_eq!(u.mianownik(), 4);
    }

    #[test]
    #[should_panic(expected = "Mianownik nie może być zerem!")]
    fn test_zero_mianownik() {
        let _ = Ulamek::new(1, 0);
    }

    #[test]
    #[should_panic(expected = "Dzielenie przez zero")]
    fn test_dzielenie_przez_zero() {
        let a = Ulamek::new(1, 2);
        let b = Ulamek::new(0, 1);
        let _ = a / b;
    }
}
