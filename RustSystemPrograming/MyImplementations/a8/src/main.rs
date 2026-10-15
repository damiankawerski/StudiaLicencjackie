
#[derive(Debug)]
struct RandGen {
    seed: i64
}

impl RandGen {
    fn new(seed: i64) -> RandGen {
        RandGen {seed}
    }

    fn gen_range(&mut self, min: i64, max: i64) -> i64 {
        if min > max {
            panic!("min > max.");
        }

        let a: i64 = 1664525;
        let c: i64 = 1013904223;
        let m: i64 = i64::MAX;

        self.seed = self
            .seed
            .wrapping_mul(a)
            .wrapping_add(c)
            .rem_euclid(m); // seed zawsze >= 0

        let zakres = (max - min + 1).max(1);
        min + self.seed.rem_euclid(zakres)
    }
}


struct Urna {
    generator: RandGen,
    znaki: Vec<char>,
}

impl Urna {
    fn new(gene: RandGen) -> Self {
        Self { generator: gene, znaki: Vec::new() }
    }

    fn losuj_z_us(&mut self) -> Option<char> {
        if self.znaki.is_empty() {
            return None;
        }

        let max = self.znaki.len() -1;

        let index = self.generator.gen_range(0, max as i64);

        let result = Some (self.znaki[index as usize]);

        self.znaki.remove(index as usize);

        result
    }

    fn losuj_bez_us(&mut self) -> Option<char> {
        if self.znaki.is_empty() {
            return None;
        }

        let max = self.znaki.len() -1;

        let index = self.generator.gen_range(0, max as i64);

        let result = Some (self.znaki[index as usize]);

        result
    }

    fn rozmiar(&self) -> usize {
        self.znaki.len()
    }

    fn doloz(&mut self, znak: char) {
        self.znaki.push(znak);
    }

}



fn main() {
    let mut urna = Urna::new(RandGen::new(123));

    let a: Option<char> = urna.losuj_z_us();
    println!("{:?}", a.is_none());
    let a: Option<char> = urna.losuj_bez_us();
    println!("{:?}", a.is_none());


    urna.doloz('a');
    urna.doloz('b');
    urna.doloz('c');
    urna.doloz('d');

    println!("{:?}", urna.rozmiar() == 4);
    let y: Option<char> = urna.losuj_z_us();
    println!("{:?}", y.is_some());
    println!("{:?}", urna.rozmiar() == 3);
    let x: Option<char> = urna.losuj_bez_us();
    println!("{:?}", x.is_some());
    println!("{:?}", urna.rozmiar() == 3);
    println!("{:?}", x != y);
    urna.losuj_z_us();
    println!("{:?}", urna.rozmiar() == 2);
    urna.losuj_z_us();
    println!("{:?}", urna.rozmiar() == 1);
    urna.losuj_z_us();
    println!("{:?}", urna.rozmiar() == 0);
    let z: Option<char> = urna.losuj_z_us();
    println!("{:?}", z.is_none());
    println!("{:?}", urna.rozmiar() == 0);
}
