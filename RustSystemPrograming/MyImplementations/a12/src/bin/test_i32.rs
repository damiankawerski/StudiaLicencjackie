use a12::{randgen::RandGen, urna::Urna};

fn main() {
    let mut urna = Urna::new(RandGen::new(1));
    urna.doloz(1);
    urna.doloz(2);
    println!("{:?}", urna.losuj_z_us());
}
