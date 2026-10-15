use a12::{randgen::RandGen, urna::Urna};

fn main() {
    let mut urna = Urna::new(RandGen::new(2));
    urna.doloz(true);
    urna.doloz(false);
    println!("{:?}", urna.losuj_bez_us());
}
