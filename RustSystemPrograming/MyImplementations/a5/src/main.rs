fn char_2_string(z: char) -> Option<String> {
    let u = match z {
        '0' => Some("000"),
        '1' => Some("001"),
        '2' => Some("010"),
        '3' => Some("011"),
        '4' => Some("100"),
        '5' => Some("101"),
        '6' => Some("110"),
        '7' => Some("111"),
        _ => None
    };

    match u {
        Some(str) => Some(String::from(str)),
        None => None
    }
}


// zadanie 1


fn zamien_syst8_na_syst2(z: &str) -> Option<String> {
    let mut result = String::new();

    for c in z.chars() {
        let p = char_2_string(c);
        let u = p?;
        result.push_str(u.as_str());
    }
    Some(result)
}


// zadanie 2
fn wartosc_syst2(z: &str) -> Option<u8> {
    if(z.chars().count() > 8 || !z.chars().all(|c| c == '0' || c == '1')) {
        return None;
    }

    let mut result: u8 = 0;

    let mut exp = 0;
    for c in z.chars().rev() {
        let digit = c.to_digit(10);
        if c == '1' {
            result += u8::pow(2, exp);
        }
        exp += 1;
    }
    Some(result)
}


fn wartosc_syst8(z: &str) -> Option<u8> {
    wartosc_syst2(zamien_syst8_na_syst2(z).unwrap().as_str())
}


fn main() {
    let s = "77";
    println!("{:?}", wartosc_syst8(s));
}
