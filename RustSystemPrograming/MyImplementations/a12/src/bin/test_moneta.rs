use a12::{randgen::RandGen, urna::Urna};

#[derive(Debug, Clone)]
enum Moneta {
    Orzel,
    Reszka,
}

fn main() {
    let mut urna = Urna::new(RandGen::new(4));
    urna.doloz(Moneta::Orzel);
    urna.doloz(Moneta::Reszka);
    println!("{:?}", urna.losuj_bez_us());
}
