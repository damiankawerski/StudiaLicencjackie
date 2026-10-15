use core::num;

// zadanie 1
fn email(mail: &str) -> bool {

    if mail.len() < 3 {
        return false;
    }
    
    let mut count = 0;

    for c in mail.chars() {
        match c {
            '@' => count += 1,
            '.' | 'a'..='z' | 'A'..='Z' | '0'..='9' => {},
            _ => return false,
        }
    }

    if count != 1 {
        return false;
    }

    // 1 i ostatni znak to litera lub cyfra
    let first = mail.chars().next().unwrap();
    let last = mail.chars().last().unwrap();

    if !first.is_ascii_alphanumeric() || !last.is_ascii_alphanumeric() {
        return false;
    }

    // w czesci za malpa jest kropka

    if !mail.split('@').last().unwrap().contains('.') {
        return false;
    }


    true
}

// zadanie 2
#[derive(Clone, Debug, PartialEq)]
struct Set {
    arr: Vec<u32>
}

impl Set {
    fn new() -> Set {
        Set { arr: Vec::new() }
    }

    fn from_slice(slice: &[u32]) -> Set {
        let mut array: Vec<u32> = Vec::new();

        for i in slice {
            if !array.contains(i) {
                array.push(*i);
            }
        }

        array.sort();
        
        Set { arr: array }
    }

    fn union(set1: &Self, set2: &Self) -> Set {
        let mut result: Vec<u32> = Vec::new();

        for i in set1.arr.iter() {
            if !result.contains(i) {
                result.push(*i);
            }
        }

        for i in set2.arr.iter() {
            if !result.contains(i) {
                result.push(*i);
            }
        }

        result.sort();

        Set { arr: result }
    }

    fn is_subset_of(&self, other: &Self) -> bool {
        self.arr.iter().all(|x| other.arr.contains(x))
    }
}

impl PartialOrd for Set {
    fn partial_cmp(&self, other: &Self) -> Option<std::cmp::Ordering> {
        let self_subset = self.is_subset_of(other);
        let other_subser = other.is_subset_of(self);

        match (self_subset, other_subser) {
            (true, true) => Some(std::cmp::Ordering::Equal),
            (true, false) => Some(std::cmp::Ordering::Less),
            (false, true) => Some(std::cmp::Ordering::Greater),
            (false, false) => None
        }
    }
}

// zadanie 3

struct Transaction {
    amount: u32,
    sender: String,
    receiver: String,
}

struct BankAccount {
    number: String,
    history: Vec<Transaction>,
}

impl BankAccount {
    fn new(number: String) -> BankAccount {
        BankAccount { number: number, history: Vec::new() }
    }

    fn transaction(&self, t: Transaction) {
        let mut is_out = false;

        if t.sender.eq(&self.number) {
            is_out = true; 
        } else if t.receiver.eq(&self.number) {
            is_out = false;
        } else {
            return;
        }
    }
}

fn main() {
    let a = Set::from_slice(&[1, 2]);
    let b = Set::from_slice(&[1, 2, 3]);

    println!("{:?}", a < b);  // true
    println!("{:?}", a > b);  // false
}
