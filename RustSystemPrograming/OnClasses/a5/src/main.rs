// zadanie 1
fn char2string(z: char) -> Option<String> {
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

fn zamien_syst8_na_syst2_zaj(z: &str) -> Option<String> {
    let mut out = String::new();
    for c in z.chars() {
        let p = char2string(c);
        let u = p?;
        out.push_str(u.as_str());
    }
    Some(out)
}

fn zamien_syst8_na_syst2(z: &str) -> Option<String> {
        
    if !z.chars().all(|c| ('0'..'7').contains(&c)) {
        return None
    }

    let binary: String = z.chars()
        .map(|digit| {
            match digit {
                '0' => "000",
                '1' => "001",
                '2' => "010",
                '3' => "011",
                '4' => "100",
                '5' => "101",
                '6' => "110",
                '7' => "111",
                _ => unreachable!(),
            }
        })
        .collect::<String>();

        



    Some(String::from(binary))
}


fn wartosc_syst2(z: &str) -> Option<u8> {
    if z.len() > 8 || !z.chars().all(|c| c == '0' || c == '1') {
        return None;
    }

    let mut result: u8 = 0;

    for c in z.chars() {
        let digit = c.to_digit(10)? as u8;
        result = result.checked_mul(2)?.checked_add(digit)?;
    }

    Some(result)
}


fn main() {
   
   let s = "245";
   let bin: &str = "1111";
   println!("{:?} ósemkowo to: {:?} binarnie", s, zamien_syst8_na_syst2(s));
   println!("{:?} ósemkowo to: {:?} binarnie", s, zamien_syst8_na_syst2_zaj(s));
    println!("{:?} binarnie to {:?} dziesietnie",  bin, wartosc_syst2(bin).unwrap());

}
