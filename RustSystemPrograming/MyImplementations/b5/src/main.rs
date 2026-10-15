fn wartosc_cyfry(c: char) -> Result<u8, String> {
    if !c.is_ascii_digit() {
        return Err("Nie jest liczbą".to_string());
    }

    match c.to_digit(10) {
        Some(d) => Ok(d as u8),
        None => Err("Błąd konwersji znaku na cyfrę".to_string()),
    }
}


fn dodaj_pisemnie(a: &str, b: &str) -> Result<String, String> {
    if a.is_empty() || b.is_empty() {
        return Err("Pusty string".to_string());
    }

    if !a.chars().all(|c| c.is_ascii_digit()) || !b.chars().all(|c| c.is_ascii_digit()) {
        return Err("Coś tu nie gra – jeden z argumentów nie zawiera liczby".to_string());
    }

    let mut result = String::new();
    let mut carry = 0;
    let mut a_chars = a.chars().rev();
    let mut b_chars = b.chars().rev();

    loop {
        let a_digit = a_chars.next().and_then(|c| c.to_digit(10));
        let b_digit = b_chars.next().and_then(|c| c.to_digit(10));

        if a_digit.is_none() && b_digit.is_none() && carry == 0 {
            break;
        }

        let sum = a_digit.unwrap_or(0) + b_digit.unwrap_or(0) + carry;
        carry = sum / 10;
        result.push(std::char::from_digit(sum % 10, 10).unwrap());
    }

    Ok(result.chars().rev().collect())
}


fn main() {
    let a = "";
    let b = "";
    println!("{:?}", dodaj_pisemnie(a, b));
}
