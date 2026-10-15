fn wartosc_cyfry(c: char) -> Result<u8, String> {
    c.to_digit(10).map(|d| d as u8).ok_or_else(|| format!("Niepoprawny znak"))
}

fn main() {
    let c = 's';
    let b = wartosc_cyfry(c);

    print!("{:?}", b);
}
