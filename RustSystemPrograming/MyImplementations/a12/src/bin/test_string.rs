use a12::{randgen::RandGen, urna::Urna};

fn main() {
    let mut urna = Urna::new(RandGen::new(3));
    urna.doloz("hello".to_string());
    urna.doloz("world".to_string());
    println!("{:?}", urna.losuj_z_us());
}
