// zadanie 1 petle

fn english_dict() {
    let mut arr = Vec::new();
    for c in 'a'..='z' {
        arr.push(c);
    }
    println!("{:?}", arr);

}

fn english_dict_iter() {
    let arr: Vec<char> = ('a'..='z').collect();
    println!("{:?}", arr);

}

fn expon() {
    let mut arr: Vec<i32> = Vec::new();


    for i in 1..11 {
        arr.push(i * i);
    }
    println!("{:?}", arr);
}

fn expon_iter() {
    let mut arr : Vec<i32> = (1..11).map(|x| x * x).collect();
    println!("{:?}", arr);
}

fn two_squares() {
    let mut arr = Vec::new();

    for i in 0..10 {
        arr.push(2_i32.pow(i));
    }

    println!("{:?}", arr);
}

fn two_squares_iter() {
    let mut arr: Vec<i32> = (0..10).map(|x| 2_i32.pow(x)).collect();
    println!("{:?}", arr);
}

fn reciprocals() {
    let mut arr = Vec::new();

    for i in 1..=20 {
        arr.push(1.0 / i as f64);
    }

    println!("{:?}", arr);
}

fn reciprocals_iter() {
    let mut arr: Vec<f64> = (1..=20).map(|x| 1.0 / x as f64).collect();
    println!("{:?}", arr);
}

fn last_func() {
    let mut arr = Vec::new();

    for i in 0..=100 {
        if i % 3 == 0 && i % 4 != 0 {
            arr.push(i);
        }
    }

    println!("{:?}", arr);
}


// zadanie 2

fn filter_by_length(vec: Vec<&str>) -> Vec<&str>{
    let arr = vec.into_iter().filter(|txt| txt.chars().count() < 4).collect();
    arr
}

fn filter_by_a(vec: Vec<&str>) -> Vec<&str> {
    vec.into_iter()
        .filter(|txt| !txt.chars().any(|c| c == 'a' || c == 'A'))
        .collect()
}


fn filter_by_numbers(vec: Vec<&str>) -> Vec<&str> {
    vec.into_iter().filter(|txt| txt.chars().all(|c| c.is_ascii_digit())).collect()
}

fn all_reversed(vec: Vec<&str>) -> Vec<String> {
    vec.into_iter().map(|txt| txt.chars().rev().collect()).collect()
}

fn double_lettered(vec: Vec<&str>) -> Vec<&str> {
    vec.into_iter()
        .filter(|txt| txt.chars().zip(txt.chars().skip(1)).any(|(a, b)| a == b))
        .collect()
}


// zadanie 3

fn indeksy(arr: Vec<&str>, element: &str) -> Vec<usize> {
    let mut vec = Vec::new();
    for (index, txt) in arr.iter().enumerate() {
        if *txt == element {
            vec.push(index);
        }
    }
    vec
}

fn indeksy_iter(arr: Vec<&str>, element: &str) -> Vec<usize>{
    arr.into_iter().enumerate().filter_map(|(index, txt)| if txt == element {Some(index)} else {None}).collect()
}


fn main() {
    
}
 