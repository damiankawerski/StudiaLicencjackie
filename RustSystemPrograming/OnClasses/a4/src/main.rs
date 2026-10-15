

// zadanie 1
fn liczba_wystapien(napis: &str, znak: char) -> i32 {
    let mut counter = 0;
    for c in napis.chars() {
        if c == znak {
            counter += 1;
        }
    }
    return counter;
}

// zadanie 2
fn value(znak: char) -> i32 {
    match znak {
        'I' => 1,
        'V' => 5,
        'X' => 10,
        'L' => 50,
        'C' => 100,
        'D' => 500,
        'M' => 1000,
        _ => 0,
    }
}

fn rzymskie(rzymska: &str) -> i32 {
    let mut result = 0;
    let mut prev = 0;
    for c in rzymska.chars() {
        let val = value(c);
        if val > prev {
            result += val - 2 * prev;
        } else {
            result += val;
        }
        prev = val;
    }
    return result;
}

fn test() {
    println!("{:?}", rzymskie("III") == 3);
    println!("{:?}", rzymskie("IX") == 9);
    println!("{:?}", rzymskie("XIX") == 19);
    println!("{:?}", rzymskie("MCMX") == 1910);
}


fn main() {
    test();
}
