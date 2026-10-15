// 5b 3- 4
// fn wartosc_cyfry_rzymskiej(c: char) -> Result<u16, String> {
//     let rom: Result<u16, String> = match c {
//         'I' => Ok(1),
//         'V' => Ok(5),
//         'X' => Ok(10),
//         'L' => Ok(50),
//         'C' => Ok(100),
//         'D' => Ok(500),
//         'M' => Ok(1000),
//         _ => Err("Niepoprawny znak".to_string())
//     };

//     return rom;
// }

// fn rzymskie(napis: &str) -> Result<u16, String> {
//     let mut sum: u16 = 0;
//     let mut prev: u16 = 0;

//     for c in napis.chars() {
//         let value = wartosc_cyfry_rzymskiej(c)?;
        
//         if prev > value {
//             sum += value;
//         } else {
//             sum += value - 2 * prev;
//         }

//         prev = value;
//     }

//     return Ok(sum);
// }


// 6a 1 2 3

fn div3not4() -> Vec<u16> {
    (1u16..100)
    .filter(|&n| n % 3 == 0 && n % 4 != 0)
    .collect()
}

fn reve() -> Vec<f64> {
    (1..20)
    .map(|n| 1.0 / n as f64)
    .collect()
}

fn doubled(arr: Vec<&str>) -> Vec<&str> {
    arr.into_iter().filter(|s| s.chars().zip(s.chars().skip(1)).any(|(a, b)| a == b))
    .collect()
} 

fn strRev(arr: Vec<&str>) -> Vec<String> {
    arr.into_iter().map(|txt| txt.chars().rev().collect()).collect()
} 

fn main() {
    println!("{:?}", div3not4());
    println!("{:?}", reve());
    let mut vec = Vec::new();
    vec.push("Pizza");
    vec.push("krowa");
    vec.push("Brutto");

    println!("{:?}", doubled(vec));
}