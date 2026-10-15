// zadanie 1
fn co_drugi_znak(s: &str) -> String {
    s.chars().step_by(2).collect()
}

// zadanie 2
fn reverse_string(s: &str) -> String {
    s.chars().rev().collect()
}

fn  szyfruj(s: &str, key: usize) -> String {
    if key == 0 {
        return s.to_string();
    }

    let segments = s.chars()
        .collect::<Vec<char>>()
        .chunks(key)
        .map(|chunk| chunk.iter().collect::<String>())
        .collect::<Vec<String>>();

    let mut result = String::new();

    for str in segments {
        result.push_str(reverse_string(&str).as_str());
    }

    result

}

// zadanie 3
fn wizytowka(name: &str, surname: &str) -> String {

    let name_first_letter = name.chars().next().unwrap().to_uppercase();
    let surname_first_letter = surname.chars().next().unwrap().to_uppercase();
    let surname_rest = surname.chars().skip(1).collect::<String>().to_lowercase();

    let mut result = name_first_letter.to_string() + ". ";
    result.push_str(surname_first_letter.to_string().as_str());
    result.push_str(surname_rest.as_str());
    result
}

// zadanie 4

fn na_rzymskie(n: u64) -> String {
    let mut number = n;
    let roman_numerals = [
        (1000, "M"), (900, "CM"), (500, "D"), (400, "CD"),
        (100, "C"), (90, "XC"), (50, "L"), (40, "XL"),
        (10, "X"), (9, "IX"), (5, "V"), (4, "IV"), (1, "I")
    ];

    let mut result = String::new();

    for &(value, numeral) in roman_numerals.iter() {
        while number >= value {
            result.push_str(numeral);
            number -= value;
        }
    }
    result
}

fn test_rzymskie() {
    println!("{}", na_rzymskie(3) == "III");
    println!("{}", na_rzymskie(9) == "IX");
    println!("{}", na_rzymskie(19) == "XIX");
    println!("{}", na_rzymskie(1910) == "MCMX");
}

// zadanie 5

fn dodaj_pisemnie(a: &str, b: &str) -> String {
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

    result.chars().rev().collect()
}


fn test_dodaj_pisemnie() {
    let test_cases = [
        ("1", "3", "4"),
        ("8", "3", "11"),
        ("10", "23", "33"),
        ("1", "0", "1"),
        ("11", "00", "11"),
        ("131", "9900", "10031"),
        ("998", "7", "1005"),
        ("24872947", "294729478", "319602425"),
        ("5924729874298749827418582", "6782893629472094209740298", "12707623503770844037158880"),
    ];

    for (a, b, expected) in test_cases.iter() {
        let result = dodaj_pisemnie(a, b);
        if result == *expected {
            println!("Test PASSED: dodaj_pisemnie(\"{}\", \"{}\") == \"{}\"", a, b, expected);

        } else {
            println!("Test FAILED: dodaj_pismnie(\"{}\", \"{}\") == \"{}\", got \"{}\"", a, b, expected, result);

        }
    }
}

fn main() {
    test_dodaj_pisemnie();
}