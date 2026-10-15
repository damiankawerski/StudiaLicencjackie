use std::ops::{Add, Sub, Mul, Div, AddAssign, SubAssign, MulAssign, DivAssign};
use std::cmp::{PartialEq, Eq};
use std::str::FromStr;


#[derive(Debug, Clone)]
pub struct Ulamek {
    licznik: i64,
    mianownik: i64,
}

impl Ulamek {
    pub fn new(mut licznik: i64, mut mianownik: i64) -> Self {
        if mianownik == 0 {
            panic!("Mianownik nie może być zerem!");
        }

        if mianownik < 0 {
            licznik = -licznik;
            mianownik = -mianownik;
        }

        let d = nwd(licznik, mianownik);
        Ulamek {
            licznik: licznik / d,
            mianownik: mianownik / d,
        }
    }

    pub fn licznik(&self) -> i64 {
        self.licznik
    }

    pub fn mianownik(&self) -> i64 {
        self.mianownik
    }

    pub fn as_f64(&self) -> f64 {
        self.licznik as f64 / self.mianownik as f64
    }
}

impl Add for Ulamek {
    type Output = Self;
    fn add(self, rhs: Self) -> Self {
        Ulamek::new(
            self.licznik * rhs.mianownik + rhs.licznik * self.mianownik,
            self.mianownik * rhs.mianownik,
        )
    }
}

impl Sub for Ulamek {
    type Output = Self;
    fn sub(self, rhs: Self) -> Self {
        Ulamek::new(
            self.licznik * rhs.mianownik - rhs.licznik * self.mianownik,
            self.mianownik * rhs.mianownik,
        )
    }
}

impl Mul for Ulamek {
    type Output = Self;
    fn mul(self, rhs: Self) -> Self {
        Ulamek::new(self.licznik * rhs.licznik, self.mianownik * rhs.mianownik)
    }
}

impl Div for Ulamek {
    type Output = Self;
    fn div(self, rhs: Self) -> Self {
        if rhs.licznik == 0 {
            panic!("Dzielenie przez zero");
        }
        Ulamek::new(self.licznik * rhs.mianownik, self.mianownik * rhs.licznik)
    }
}

impl AddAssign for Ulamek {
    fn add_assign(&mut self, rhs: Self) {
        *self = self.clone() + rhs;
    }
}

impl SubAssign for Ulamek {
    fn sub_assign(&mut self, rhs: Self) {
        *self = self.clone() - rhs;
    }
}

impl MulAssign for Ulamek {
    fn mul_assign(&mut self, rhs: Self) {
        *self = self.clone() * rhs;
    }
}

impl DivAssign for Ulamek {
    fn div_assign(&mut self, rhs: Self) {
        *self = self.clone() / rhs;
    }
}

impl PartialEq for Ulamek {
    fn eq(&self, other: &Self) -> bool {
        self.licznik == other.licznik && self.mianownik == other.mianownik
    }
}

impl FromStr for Ulamek {
    type Err = ();

    fn from_str(s: &str) -> Result<Self, Self::Err> {
        let parts: Vec<&str> = s.trim().split('/').collect();

        match parts.len() {
            1 => {
                let licznik = parts[0]
                    .parse::<i64>()
                    .unwrap_or_else(|_| panic!("Niepoprawny licznik: '{}'", parts[0]));
                Ok(Ulamek::new(licznik, 1))
            }
            2 => {
                let licznik = parts[0]
                    .parse::<i64>()
                    .unwrap_or_else(|_| panic!("Niepoprawny licznik: '{}'", parts[0]));
                let mianownik = parts[1]
                    .parse::<i64>()
                    .unwrap_or_else(|_| panic!("Niepoprawny mianownik: '{}'", parts[1]));
                Ok(Ulamek::new(licznik, mianownik))
            }
            _ => panic!("Niepoprawny format ułamka: '{}'", s),
        }
    }
}



impl Eq for Ulamek {}

fn nwd(a: i64, b: i64) -> i64 {
    let mut a = a.abs();
    let mut b = b.abs();
    while b != 0 {
        let t = b;
        b = a % b;
        a = t;
    }
    if a == 0 { 1 } else { a }
}
